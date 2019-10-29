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
	base,
	avanzando,
	manoPared,
	avanzoHaciaPared,
	manoDer,
	manoIzq,
	algoritmoMano,
	algoritmoManoIzq,
	mismoPunto,
	obstaculo

};
Estados estado = base;
float threshold = 200; // millimeters
float anguloGiro = 0;
int contaxu = 0;
float posicionX=0;
float posicionZ=0;

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
	puntos[0] = QVec::vec3(-300, 0, 250);
	puntos[1] = QVec::vec3(-150, 0, 250);
	puntos[2] = QVec::vec3(0, 0, 250);
	puntos[3] = QVec::vec3(150, 0, 250);
	puntos[4] = QVec::vec3(300, 0, 250);
	this->Period = period;
	timer.start(Period);
	qDebug() << "End initialize";
}

//MAQUINA DE ESTADOS
void SpecificWorker::compute()
{
	try
	{
		RoboCompLaser::TLaserData ldata = laser_proxy->getLaserData(); // leo el laser tiene desde la posicion [1] hasta la [99] posiciones desde angulos positivos a negativos lee de izquerda a derecha
		//readRobotState();
		switch (estado)
		{
			case base:
			{
				std::cout << "estado base" << std::endl;
				std::sort(ldata.begin(), ldata.end(), [](RoboCompLaser::TData a, RoboCompLaser::TData b) { return a.dist < b.dist; }); // Ordeno el laser para moverme hacia la posicion mas lejana
				std::cout << "estado base angulo=" <<ldata.back().angle<< std::endl;
				differentialrobot_proxy->setSpeedBase(0, ldata.back().angle);														   //Roto el robot hacia esa direccion
				usleep(1000000);																								   // Duermo el hilo para que al robot le tiempo a girar
				anguloGiro = ldata.back().angle;																					   // guardo el angulo de giro, para luego saber cuanto tengo que girar de mas para ponerme correctamente
				estado = avanzando;
				break;
			}

			case avanzando:
			{
				std::cout << " estado avanzando" << std::endl;
				std::sort(ldata.begin(), ldata.end(), [](RoboCompLaser::TData a, RoboCompLaser::TData b) { return a.dist < b.dist; }); // Ordeno el laser para moverme hacia la posicion mas lejana

				//Cuando llege al obstaculo me alineo 90 grados, poniendo la mano sobre el
				if (ldata.front().dist < threshold)
				{
					std::cout << " estado avanzando--> if (ldata.front().dist < threshold)" << std::endl;
					estado = manoPared;
				}
				else // avanzo siempre que no me choche
				{
					std::cout << " estado avanzando--> else del if (ldata.front().dist < threshold)" << std::endl;
					differentialrobot_proxy->setSpeedBase(400, 0);
				}
				break;
			}

			case manoPared: //Alineo el robot con lo que se gaya topado
			{
				std::cout << " estado manoPared" << std::endl;
				std::sort(ldata.begin(), ldata.end(), [](RoboCompLaser::TData a, RoboCompLaser::TData b) { return a.dist < b.dist; }); // Ordeno el laser para moverme hacia la posicion mas lejana
				if (anguloGiro >= 0.0)																								   // mi mano sera la izquierda
				{
					std::cout << " estado manoPared--->if(anguloGiro >= 0.0)" << std::endl;
					//Calculo de los 90º
					differentialrobot_proxy->setSpeedBase(0, obtenerRot(anguloGiro)); //Roto el robot hacia esa direccion
					usleep(1000000);											   // Duermo el hilo para que al robot le tiempo a girar

					if (ldata.front().dist < threshold) // Probabmente sea una pared o lo mismo son dos obstaculos muy juntos... de ilusiones vive el hombre
					{
						std::cout << " estado manoPared--->if(anguloGiro >= 0.0)-->if(ldata.front().dist < threshold)" << std::endl;
						estado = manoIzq;
					}
					else // avanzo hasta que me choque XD
					{
						std::cout << " estado manoPared--->if(anguloGiro >= 0.0)-->else del if(ldata.front().dist < threshold)" << std::endl;
						estado = avanzoHaciaPared;
					}
				}
				else // mi mano sera la derecha
				{
					std::cout << " estado manoPared--->else del if(anguloGiro >= 0.0)" << std::endl;
					differentialrobot_proxy->setSpeedBase(0, obtenerRot(anguloGiro)); //Roto el robot hacia esa direccion
					usleep(1000000);											   // Duermo el hilo para que al robot le tiempo a girar

					if (ldata.front().dist < threshold) // Probabmente sea una pared o lo mismo son dos obstaculos muy juntos... de ilusiones vive el hombre
					{
						std::cout << " estado manoPared--->else del if(anguloGiro >= 0.0)-->if(ldata.front().dist < threshold)" << std::endl;
						estado = manoDer;
					}
					else
					{
						std::cout << " estado manoPared--->else del if(anguloGiro >= 0.0)-->else del if(ldata.front().dist < threshold)" << std::endl;
						estado = avanzoHaciaPared;
					}
				}

				break;
			}
			case avanzoHaciaPared:
			{
				std::cout << " estado avanzoHaciaPared" << std::endl;
				std::sort(ldata.begin(), ldata.end(), [](RoboCompLaser::TData a, RoboCompLaser::TData b) { return a.dist < b.dist; }); // Ordeno el laser para moverme hacia la posicion mas lejana
				//Avanzo hasta dar con la pared, ojala y sea una pared.
				if (ldata.front().dist < threshold)
				{
					std::cout << " estado avanzoHaciaPared-->if(ldata.front().dist < threshold)" << std::endl;
					if (anguloGiro >= 0) // mi mano sera la izquierda
					{
						std::cout << " estado avanzoHaciaPared-->if(ldata.front().dist < threshold)-->if(anguloGiro >= 0)" << std::endl;
						estado = manoIzq;
					}
					else
					{
						std::cout << " estado avanzoHaciaPared-->if(ldata.front().dist < threshold)-->else del if(anguloGiro >= 0)" << std::endl;
						estado = manoDer;
					}
				}
				else
				{
					std::cout << " estado avanzoHaciaPared-->else del if(ldata.front().dist < threshold)" << std::endl;
					differentialrobot_proxy->setSpeedBase(400, 0);
				}

				break;
			}

			case manoDer:
			{
				std::cout << "estado manoDer" << std::endl;
				//giro el robot otros 90 grado... Tenemos en cuenta que ya viene con un giro de 90 grados
				differentialrobot_proxy->setSpeedBase(0, -1.57);
				usleep(1000000);
				//Si las distancia de mi laser a la izquierda son menores que mi threshold entonces es porque tengo la pared a mi lado.
				if (ldata[99].dist < threshold && ldata[98].dist < threshold && ldata[97].dist < threshold && ldata[96].dist)
				{
				}
				else //Si no se da el caso anterior es porque quizas estaba en un obstaculo entonces avanzo y vuelvo a girar -90º grados.
				{
					differentialrobot_proxy->setSpeedBase(0, 1.57);
					usleep(1000000);
					estado = avanzoHaciaPared;
				}
				break;
			}

			case manoIzq:
			{
				std::cout << "estado manoIzq" << std::endl;
				//giro el robot otros 90 grado... Tenemos en cuenta que ya viene con un giro de 90 grados
				usleep(1000000);
				differentialrobot_proxy->setSpeedBase(0, 1.57);
				usleep(1000000);
				//Si las distancia de mi laser a la izquierda son menores que mi threshold entonces es porque tengo la pared a mi lado.
				if (ldata[1].dist <= (threshold + 1500) && ldata[2].dist <= (threshold + 1700))
				{
					std::cout << "estado manoIzq-->if(ldata[1].dist <= (threshold + 1500) && ldata[2].dist...)" << std::endl;
					estado = algoritmoMano;
					differentialrobot_proxy->getBaseState(bState);				
					posicionX=bState.x;
					posicionZ=bState.z;
					
				}
				else //Si no se da el caso anterior es porque quizas estaba en un obstaculo entonces avanzo y vuelvo a girar -90º grados.
				{
					std::cout << "estado manoIzq--> else del if(ldata[1].dist <= (threshold + 1500) && ldata[2].dist...)" << std::endl;
					differentialrobot_proxy->setSpeedBase(400, 0);
					usleep(1000000);
					differentialrobot_proxy->setSpeedBase(0, -1.57);
					usleep(1000000);

					estado = avanzoHaciaPared;
					
				}
				break;
			}

			case algoritmoMano:
			{
				std::cout << "estado algoritmoMano" << std::endl;
				differentialrobot_proxy->getBaseState(bState);
				std::cout << "posicion del robot en el punto util: X="<<posicionX<<" Z="<<posicionZ<<" posicion del robot actual: X="<<bState.x<<" Z="<<bState.z << std::endl;
				if (bState.x >= 2100 && bState.z >= 570 && bState.x <= 2500 && bState.z <= 600 && contaxu > 0)// Compruebo si he vuelto al mismo punto
				{
					std::cout << "estado algoritmoMano-->if(bState.x == posicionX && bState.z == posicionZ && contaxu > 0)" << std::endl;
					estado=mismoPunto;
				}
				else // si vuelvo al mismo punto roto -90 avanzo 500 roto otros +90 y aumento mi threashold.
				{
					std::cout << "estado algoritmoMano-->else del if(bState.x == posicionX && bState.z == posicionZ && contaxu > 0)" << std::endl;
					std::sort(ldata.begin(), ldata.end(), [](RoboCompLaser::TData a, RoboCompLaser::TData b) { return a.dist < b.dist; }); // Ordeno el laser para moverme hacia la posicion mas lejana
					if (ldata.front().dist<threshold)
					{
						std::cout << "estado algoritmoMano-->else del if(bState.x == posicionX && bState.z == posicionZ && contaxu > 0)-->if(ldata.front().dist<threshold)" << std::endl;
						estado=algoritmoManoIzq;
					}
					else
					{
						std::cout << "estado algoritmoMano-->if(bState.x == posicionX && bState.z == posicionZ && contaxu > 0)-->else del if(ldata.front().dist<threshold)" << std::endl;;
						differentialrobot_proxy->setSpeedBase(400, 0);
					}
				}
				contaxu=1;
				break;
			}

			case algoritmoManoIzq:
			{
				std::cout << "estado algoritmoManoIzq" << std::endl;
				//giro el robot otros 90 grado... Tenemos en cuenta que ya viene con un giro de 90 grados
				differentialrobot_proxy->setSpeedBase(0, 1.57);
				usleep(1000000);
				//Si las distancia de mi laser a la izquierda son menores que mi threshold entonces es porque tengo la pared a mi lado.
				if (ldata[1].dist <= (threshold + 1500) && ldata[2].dist <= (threshold + 1700))
				{
					std::cout << "estado algoritmoManoIzq-->if(ldata[1].dist <= (threshold + 1500) && ldata[2].dist...)" << std::endl;
					estado = algoritmoMano;			
				}
				else //Si no se da el caso anterior es porque quizas estaba en un obstaculo entonces avanzo y vuelvo a girar -90º grados.
				{
					std::cout << "estado algoritmoManoIzq--> else del if(ldata[1].dist <= (threshold + 1500) && ldata[2].dist...)" << std::endl;
					differentialrobot_proxy->setSpeedBase(400, 0);
					usleep(1000000);
					differentialrobot_proxy->setSpeedBase(0, -1.57);
					usleep(1000000);
					estado = avanzoHaciaPared;
				}
				break;
			}
			
			case mismoPunto:
			{
				//Roto -90 grados
				differentialrobot_proxy->setSpeedBase(0, -1.57);
				usleep(1000000);
				//Avanzo una minima distancia
				differentialrobot_proxy->setSpeedBase(400, 0);
				usleep(99999);
				threshold = threshold+700;
				//Roto +90 grados
				differentialrobot_proxy->setSpeedBase(0, 1.57);
				usleep(1000000);
				//actualizo mi punto incial.
				differentialrobot_proxy->getBaseState(bState);				
				posicionX=bState.x;
				posicionZ=bState.z;
				estado=algoritmoMano;
				break;
			}
			case obstaculo:
			{
				break;
			}
		}
	}
	catch (const Ice::Exception &ex)
	{
		std::cout << ex << std::endl; //If there is any error/exception display the same.
	}
}
void SpecificWorker::casillasOcupadas()
{
	for (auto p : puntos)
	{
		auto r = innerModel->transform("world", p, "base");
		auto [succese, c] = grid.getCell(r.x(), r.z());
		salida.push_back(c.free);
	}
}

float SpecificWorker::obtenerRot(float angulo)
{
	float rot = 0;
	if (angulo >= 0)
		rot = 1.57 - angulo;
	else
		rot = -1.57 - (angulo);

	return rot;
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
		if (valid)
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
