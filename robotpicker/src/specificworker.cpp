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
	RoboCompLaser::TLaserData ldata = laser_proxy->getLaserData(); //El laser devuelve 100 medidas
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

}

void SpecificWorker::obstaculo()
{

}

void SpecificWorker::idle()
{
	differentialrobot_proxy->setSpeedBase(0,0);
	if (target.active)
	{
		initialBstate=bState;
		
		estado=TURN;
	}	
}

void SpecificWorker::turn()
{
	Qvec tr = innermodel->transform("base",QVec::vec3(target.x,0,target.z),"world")
	float rot = atan2(tr.x, tr.z);
	float distancia = tr.norm2();
	if (distancia<100)
	{
		estado = idle;
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

float calculoRecta(float xBase, float zBase, float xTarget, float zTarget)
{

	return angulo;
}


/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void SpecificWorker::RCISMousePicker_setPick(Pick myPick)
{
	qDebug()<<"x="<<myPick.x;
	target.x = myPick.x;
	target.z = myPick.z;
	target.active = true;
}





