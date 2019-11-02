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

/**
* \brief Default constructor
*/
SpecificWorker::SpecificWorker(TuplePrx tprx) : GenericWorker(tprx)
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
//       THE FOLLOWING IS JUST AN EXAMPLE
//	To use innerModelPath parameter you should uncomment specificmonitor.cpp readConfig method content
//	try
//	{
//		RoboCompCommonBehavior::Parameter par = params.at("InnerModelPath");
//		std::string innermodel_path = par.value;
//		innerModel = new InnerModel(innermodel_path);
//	}
//	catch(std::exception e) { qFatal("Error reading config params"); }



	


	return true;
}

void SpecificWorker::initialize(int period)
{
	std::cout << "Initialize worker" << std::endl;
	this->Period = period;
	timer.start(Period);

}

void SpecificWorker::compute()
{
	differentialrobot_proxy->getBaseState(bState);
	ldata = laser_proxy->getLaserData(); //El laser devuelve 100 medidas
	switch (estado)
	{
		case IDLE:
		{
			idle();
			break;
		}
		case TURN:
		{
			turn();	
			break;
		}
		case GOTO:
		{
			goTo();
			break;
		}

		case OBSTACULO:
		{
			obstaculo();
			break;
		}
	}
}



void SpecificWorker::goTo()
{
	float threshold = 200; // millimeters
	qDebug()<<"ESTADO GOTO";
	
	//El robot ya esta girado solo tenemos que avanzar hata que nos encontremos con un obstaculo
	std::sort(ldata.begin(), ldata.end(), [](RoboCompLaser::TData a, RoboCompLaser::TData b) { return a.dist < b.dist; }); // Ordeno el laser para moverme hacia la posicion mas lejana
	if (ldata.front().dist < threshold)
	{
		estado=OBSTACULO;
		differentialrobot_proxy->setSpeedBase(0,0);
		return;
	}
	differentialrobot_proxy->setSpeedBase(200,0);
}

void SpecificWorker::obstaculo()
{
	qDebug()<<"ESTADO OBSTACULO";
	// si el angulo es negativo es mas facil hacer mano izquierda, si el angulo es positivo es mas facil hacer mano derecha
	float angulo = bState.alpha; // guardamos el angulo que forma el robot con el eje central del mapa??? o algo asi
	float rot = angulo - 1.57;

}

void SpecificWorker::idle()
{
	qDebug()<<"ESTADO IDLE";
	differentialrobot_proxy->setSpeedBase(0,0);
	if (target.active)
	{
		initialBstate=bState;
		estado=TURN;
	}	
}

void SpecificWorker::turn()
{
	qDebug()<<"ESTADO TURN";
	QVec tr = innermodel->transform("robot", QVec::vec3(target.x, 0, target.z), "world");
	float rot = atan2(tr.x(), tr.z());
	float distancia = tr.norm2();
	if (distancia<100)
	{
		estado = IDLE;
		return;
	}
	
	if (fabs(rot) < 0.1)
	{
		estado=GOTO;
		differentialrobot_proxy->setSpeedBase(0,0);
		return;
	}
	if (rot>1)
		rot=1;
	
	if (rot<-1)
		rot=-1;

	differentialrobot_proxy->setSpeedBase(0,rot);
}


/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void SpecificWorker::RCISMousePicker_setPick(Pick myPick)
{
	qDebug()<<"x="<<myPick.x<<"z="<<myPick.z;
	target.x = myPick.x;
	target.z = myPick.z;
	target.active = true;
}





