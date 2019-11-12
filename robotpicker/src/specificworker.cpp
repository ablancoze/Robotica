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
    //THE FOLLOWING IS JUST AN EXAMPLE
	//To use innerModelPath parameter you should uncomment specificmonitor.cpp readConfig method content
	try
	{
		RoboCompCommonBehavior::Parameter par = params.at("InnerModelPath");
		std::string innermodel_path = par.value;
		innermodel = std::make_shared<InnerModel>(innermodel_path);
	}
	catch(std::exception e) { qFatal("Error reading config params"); }

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
	innermodel->updateTransformValues("base",bState.x,0,bState.z,0,bState.alpha,0);
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

		case RODEAR:
		{
			rodear();
			break;
		}

	}
}

void SpecificWorker::idle()
{
	qDebug()<<"ESTADO IDLE";
	differentialrobot_proxy->setSpeedBase(0,0);
	if (target.active)
	{
		initialBstate=bState;
		estado=TURN;
		target.active = false;
	}	
}

void SpecificWorker::turn()
{
	qDebug()<<"ESTADO TURN";
	QVec tr;
	float rot;
	float distancia;
	if (target.active)
	{
		estado = IDLE;
		differentialrobot_proxy->setSpeedBase(0,0);
		return;
	}
	tr = innermodel->transform("base", QVec::vec3(target.x, 0, target.z), "world");
	rot = atan2(tr.x(), tr.z());
	qDebug()<<"ROT= "<< rot;
	distancia = tr.norm2(); //Devuelve el tamaño del vector
	if (distancia<120)
	{
		estado = IDLE;
		return;
	}
		
	if (fabs(rot) < 0.05)
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

void SpecificWorker::goTo()
{
	QVec tr;
	float distancia;
	qDebug()<<"ESTADO GOTO";
	tr = innermodel->transform("base", QVec::vec3(target.x, 0, target.z), "world");
	distancia = tr.norm2(); //Devuelve el tamaño del vector
	
	if (distancia<120)
	{
		estado = IDLE;
		return;
	}
	
	if (target.active)
	{
		estado = IDLE;
		differentialrobot_proxy->setSpeedBase(0,0);
		return;
	}

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
	QVec tr;
	float distancia;
	tr = innermodel->transform("base", QVec::vec3(target.x, 0, target.z), "world");
	distancia = tr.norm2(); //Devuelve el tamaño del vector
	
	if (distancia<120)
	{
		estado = IDLE;
		differentialrobot_proxy->setSpeedBase(0,0);
		return;
	}

	if (target.active)
	{
		estado = IDLE;
		differentialrobot_proxy->setSpeedBase(0,0);
		return;
	}
	// si el angulo es negativo es mas facil hacer mano izquierda, si el angulo es positivo es mas facil hacer mano derecha
	std::sort(ldata.begin(), ldata.end(), [](RoboCompLaser::TData a, RoboCompLaser::TData b) { return a.dist < b.dist; }); // Ordeno el laser para moverme hacia la posicion mas lejana
	if (ldata.front().dist > threshold)
	{
		estado = RODEAR;
		differentialrobot_proxy->setSpeedBase(0,0);
		return;
	}
	differentialrobot_proxy->setSpeedBase(0,0.3);
	


}

void SpecificWorker::rodear()
{
	qDebug()<<"ESTADO RODEAR";	
	QVec tr;
	float distancia;
	tr = innermodel->transform("base", QVec::vec3(target.x, 0, target.z), "world");
	distancia = tr.norm2(); //Devuelve el tamaño del vector
	if (distancia<120)
	{
		estado = IDLE;
		differentialrobot_proxy->setSpeedBase(0,0);
		return;
	}
	if (target.active)
	{
		estado = IDLE;
		differentialrobot_proxy->setSpeedBase(0,0);
		return;
	}
	auto posicionVec = std::min_element(ldata.begin()+90,ldata.end(),[](auto &&la,auto &&lb){return la.dist < lb.dist};
	//Compruebo que tengo obstaculo a la derecha
	if (*posicionVec.dist < threshold)
		differentialrobot_proxy->setSpeedBase(200,0.3);
	else if (*posicionVec.dist > threshold)
	{
		differentialrobot_proxy->setSpeedBase(200,-0.3);
	}
	else 
		differentialrobot_proxy->setSpeedBase(200,0);
	
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





