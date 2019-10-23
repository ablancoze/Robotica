/*
 *    Copyright (C)2019 by YOUR NAME HERE
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "specificworker.h"

enum Estados
{
	buscoPared,
	obstaculo,
	avanzar,
	manoPared,
	manoIzquierda,
	giroIzquierda,
	giroDerecha
	
};
Estados estado = buscoPared;
const float threshold = 200; // millimeters
float rot = 0.6;			 // no nos vale
/**
* \brief Default constructor
*/
SpecificWorker::SpecificWorker(MapPrx &mprx) : GenericWorker(mprx)
{
}

/**
* \brief Default destructor
*/
SpecificWorker::~SpecificWorker()
{
	std::cout << "Destroying SpecificWorker" << std::endl;
}

bool SpecificWorker::setParams(RoboCompCommonBehavior::ParameterList params)
{

	RoboCompCommonBehavior::Parameter par = params.at("InnerModelPath");
	innerModel = std::make_shared<InnerModel>(par.value);
	xmin = std::stoi(params.at("xmin").value);
	xmax = std::stoi(params.at("xmax").value);
	ymin = std::stoi(params.at("ymin").value);
	ymax = std::stoi(params.at("ymax").value);
	tilesize = std::stoi(params.at("tilesize").value);

	// Scene
	scene.setSceneRect(xmin, ymin, fabs(xmin) + fabs(xmax), fabs(ymin) + fabs(ymax));
	view.setScene(&scene);
	view.scale(1, -1);
	view.setParent(scrollArea);
	view.fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
	grid.initialize(TDim{tilesize, xmin, xmax, ymin, ymax}, TCell{true, false, nullptr});

	qDebug() << "Grid initialize ok";

	for (auto &[key, value] : grid)
	{
		value.rect = scene.addRect(-tilesize / 2, -tilesize / 2, 100, 100, QPen(Qt::NoPen));
		value.rect->setPos(key.x, key.z);
	}

	robot = scene.addRect(QRectF(-200, -200, 400, 400), QPen(), QBrush(Qt::blue));
	noserobot = new QGraphicsEllipseItem(-50, 100, 100, 100, robot);
	noserobot->setBrush(Qt::magenta);

	view.show();
	return true;
}

void SpecificWorker::initialize(int period)
{
	std::cout << "Initialize worker" << std::endl;
	salida.resize(5);
	puntos.resize(5);
	puntos[0] = QVec::vec3(-300,0,250);
	puntos[1] = QVec::vec3(-150,0,250);
	puntos[2] = QVec::vec3(0,0,250);
	puntos[3] = QVec::vec3(150,0,250);
	puntos[4] = QVec::vec3(300,0,250);
	this->Period = period;
	timer.start(Period);
	qDebug() << "End initialize";
}

//MAQUINA DE ESTADOS
void SpecificWorker::compute()
{
	RoboCompLaser::TLaserData ldata = laser_proxy->getLaserData(); //El laser devuelve 100 medidas
	RoboCompLaser::TLaserData ldata_def;
	switch (estado)
	{
	case buscoPared: //Avanzamos a la distancia mas larga, que me devuelva el laser siempre y no guardamos las casillas que recorremos.
		ordenarLaser(ldata);
		differentialrobot_proxy->setSpeedBase(5, ldata.back().angle);
		usleep(2000000);
		if (ldata.front().dist < threshold) // si llego a un obstaculo
		{
			estado = obstaculo;
		}
		else
		{
			// std::cout << "[+] Avanzo: " << ldata.front().dist << " unidades." << std::endl;
			estado = avanzar;//avanzamos al camino mas largo
		}
		break;

	case avanzar:
		ordenarLaser(ldata);
		if (ldata.front().dist < threshold) // si llego a un obstaculo
		{			
			estado = obstaculo;
		}
		else
		{
			differentialrobot_proxy->setSpeedBase(200, 0);
		}
		break;

	case obstaculo:
		readRobotState();
		//std::cout << "[-] Hay pared a " << ldata.front().dist << " unidades." << std::endl;
		//ordenarLaser(ldata);
		std::cout << "[+] Giro derecha a " << ldata.front().angle << " radianes." <<std::endl;
		differentialrobot_proxy->setSpeedBase(5, ldata.front().angle);

		std::cout << "[-] Estado manoPared +++ " << std::endl;
		estado=manoPared;
		
		
		break;

	case manoPared:
		readRobotState();//actualizamos el estdo
		ordenarLaser(ldata);
		if (ldata.front().dist<threshold)
		{
			estado=giroDerecha;
		}
		else
		{
			differentialrobot_proxy->setSpeedBase(200, 0);
		}
		break;
	case manoIzquierda:
		readRobotState();//actualizamos el estdo
		ldata_def = ldata;
		ordenarLaser(ldata);
		if (ldata_def.back().dist<threshold)
		{
			if (ldata.front().dist<threshold)
			{
				differentialrobot_proxy->setSpeedBase(200, 0);
			}
		}
		break;	
	
	case giroIzquierda:
		break;

	case giroDerecha:

		differentialrobot_proxy->setSpeedBase(5, ldata.front().angle);
		estado=manoPared;
		break;
	
	}
}
void SpecificWorker::casillasOcupadas()
{
	for (auto p : puntos)
	{
		auto r = innerModel->transform("world", p ,"base");
		auto [succese, c] = grid.getCell(r.x(), r.z());
		salida.push_back(c.free);
	}
}
void SpecificWorker::ordenarLaser(TLaserData &ldata)
{
	std::sort(ldata.begin(), ldata.end(), [](RoboCompLaser::TData a, RoboCompLaser::TData b) { return a.dist < b.dist; });
}

void SpecificWorker::readRobotState()
{
	try
	{
		differentialrobot_proxy->getBaseState(bState);
		auto [valid, cell] = grid.getCell(bState.x, bState.z);
		if(valid)
		{
			cell.visited = true;
			cell.rect->setBrush(Qt::green);
		}

		innerModel->updateTransformValues("base", bState.x, 0, bState.z, 0, bState.alpha, 0);
		RoboCompLaser::TLaserData ldata = laser_proxy->getLaserData();

		//draw robot
		robot->setPos(bState.x, bState.z);
		robot->setRotation(-180. * bState.alpha / M_PI);

		//update  occupied cells
		updateOccupiedCells(bState, ldata);
	}
	catch (const Ice::Exception &e)
	{
		std::cout << "Error reading from Laser" << e << std::endl;
	}
	//Resize world widget if necessary, and render the world
	if (view.size() != scrollArea->size())
		view.setFixedSize(scrollArea->width(), scrollArea->height());
}

void SpecificWorker::updateOccupiedCells(const RoboCompGenericBase::TBaseState &bState, const RoboCompLaser::TLaserData &ldata)
{
	InnerModelLaser *n = innerModel->getNode<InnerModelLaser>(QString("laser"));
	for (auto l : ldata)
	{
		auto r = n->laserTo(QString("world"), l.dist, l.angle); // r is in world reference system
		// we set the cell corresponding to r as occupied
		auto [valid, cell] = grid.getCell(r.x(), r.z());
		if (valid)
		{
			cell.free = false;
			cell.rect->setBrush(Qt::darkRed);
		}
	}
}

///////////////////////////////////////////////////////////////////77
////  SUBSCRIPTION
/////////////////////////////////////////////////////////////////////

void SpecificWorker::RCISMousePicker_setPick(const Pick &myPick)
{
	//subscribesToCODE
}
