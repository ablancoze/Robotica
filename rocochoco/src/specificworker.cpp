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
	const float threshold = 200; // millimeters
	float rot = 0.6;			 // rads per second

	movimientoRoco(threshold,rot);

}

void SpecificWorker::movimientoRoco(float threshold, float rot)
{
	try
	{
		// read laser data
		RoboCompLaser::TLaserData ldata = laser_proxy->getLaserData();
		//sort laser data from small to large distances using a lambda function.
		// std::cout << "HEAD: " << ldata.begin().dist << std::endl;
		// std::cout << "END: " << ldata.end().dis << std::endl;
		for (const auto &l: ldata)
			std::cout << l.dist << " " << l.angle << std::endl;
		std::cout << std::endl;

		std::sort(ldata.begin(), ldata.end(), [](RoboCompLaser::TData a, RoboCompLaser::TData b) { return a.dist < b.dist; });
		
		if (ldata.front().dist < threshold)
		{
			std::cout << ldata.front().dist << std::endl;
			differentialrobot_proxy->setSpeedBase(5, rot);
			usleep(rand() % (1500000 - 100000 + 1) + 100000); // random wait between 1.5s and 0.1sec
		}
		else
		{
			differentialrobot_proxy->setSpeedBase(200, 0);
		}
	}
	catch (const Ice::Exception &ex)
	{
		std::cout << ex << std::endl;
	}
}
void SpecificWorker::maquinaEstados(float threshold, float rot)
{
	
}
void SpecificWorker::movimientoDefault(float threshold, float rot)
{
	try
	{
		// read laser data
		RoboCompLaser::TLaserData ldata = laser_proxy->getLaserData();
		//sort laser data from small to large distances using a lambda function.
		std::sort(ldata.begin(), ldata.end(), [](RoboCompLaser::TData a, RoboCompLaser::TData b) { return a.dist < b.dist; });

		if (ldata.front().dist < threshold)
		{
			std::cout << ldata.front().dist << std::endl;
			differentialrobot_proxy->setSpeedBase(5, rot);
			usleep(rand() % (1500000 - 100000 + 1) + 100000); // random wait between 1.5s and 0.1sec
		}
		else
		{
			differentialrobot_proxy->setSpeedBase(200, 0);
		}
	}
	catch (const Ice::Exception &ex)
	{
		std::cout << ex << std::endl;
	}
}

void SpecificWorker::sm_compute()
{
	std::cout << "Entered state compute" << std::endl;
	compute();
}

void SpecificWorker::sm_initialize()
{
	std::cout << "Entered initial state initialize" << std::endl;
}

void SpecificWorker::sm_finalize()
{
	std::cout << "Entered final state finalize" << std::endl;
}
