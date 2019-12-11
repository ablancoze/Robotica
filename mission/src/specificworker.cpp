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
	emit computetofinalize();
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



	defaultMachine.start();
	


	return true;
}

void SpecificWorker::initialize(int period)
{
	std::cout << "Initialize worker" << std::endl;
	this->Period = period;
	timer.start(Period);
	emit this->initializetocompute();

}

void SpecificWorker::compute()
{
//computeCODE
//QMutexLocker locker(mutex);
//	try
//	{
//		camera_proxy->getYImage(0,img, cState, bState);
//		memcpy(image_gray.data, &img[0], m_width*m_height*sizeof(uchar));
//		searchTags(image_gray);
//	}
//	catch(const Ice::Exception &e)
//	{
//		std::cout << "Error reading from Camera" << e << std::endl;
//	}

	switch (estado)
	{
		case Estados::IDLE:
		{
			idle();
			break;
		}
		case Estados::TURN:
		{
			turn();	
			break;
		}
		case Estados::CHECKTAG:
		{
			checkTag();
			break;
		}

		case Estados::GOTO:
		{
			goTo();
			break;
		}
	}
}


void SpecificWorker::idle()
{
	estado = Estados::TURN;
}
void SpecificWorker::turn()
{
	try
	{
		if(tag.read().empty() == false)
		{

			estado = Estados::GOTO;
		}
		gotopoint_proxy->turn(0.5);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
void SpecificWorker::checkTag()
{

}

void SpecificWorker::goTo()
{
	// std::vector<Tp> tp = tag.read() 		
	// gotopoint_proxy->go(tp[0]);
	gotopoint_proxy->stop();
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void SpecificWorker::sm_compute()
{
	compute();
}

void SpecificWorker::sm_initialize()
{
	std::cout<<"Entered initial state initialize"<<std::endl;
}

void SpecificWorker::sm_finalize()
{
	std::cout<<"Entered final state finalize"<<std::endl;
}


////////////////////////////////////////////////////////////////////////////////
// STUBS
////////////////////////////////////////////////////////////////////////////////


void SpecificWorker::AprilTags_newAprilTagAndPose(tagsList tags, RoboCompGenericBase::TBaseState bState, RoboCompJointMotor::MotorStateMap hState)
{
	
}

void SpecificWorker::AprilTags_newAprilTag(tagsList tags)
{
	std::vector<Tp> tps;
	for(const auto &t : tags)
	{
		tps.push_back(std::make_tuple(t.id,t.tx,t.tz,t.ry));
	}
	tag.write(tps);

}
