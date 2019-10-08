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
	pared,
	obstaculo
};
Estados estado = base;

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

void SpecificWorker::initialize(int period,RoboCompCommonBehavior::ParameterList params)
{
	std::cout << "Initialize worker" << std::endl;
	RoboCompCommonBehavior::Parameter par = params.at("InnerModelPath");
	innerModel = std::make_shared<InnerModel>(par.value);
	int xmin = std::stoi(params.at("xmin").value);
	int xmax = std::stoi(params.at("xmax").value);
	int ymin = std::stoi(params.at("ymin").value);
	int ymax = std::stoi(params.at("ymax").value);
	tilesize = std::stoi(params.at("tilesize").value);
	
	// Scene
	scene.setSceneRect(xmin, ymin, fabs(xmin) + fabs(xmax), fabs(ymin) + fabs(ymax));
	//scene.setSceneRect(-12000, -6000, 38000, 16000);
	view.setScene(&scene);
	view.scale(1, -1);
	view.setParent(scrollArea);
	//view.setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
	view.fitInView(scene.sceneRect(), Qt::KeepAspectRatio);

	//grid.initialize(TDim{tilesize, -12000, 25000, -6000, 10000}, TCell{0, true, false, nullptr, 0.});
	grid.initialize(TDim{tilesize, xmin, xmax, ymin, ymax}, TCell{0, true, false, nullptr, 0.});

	for (auto &[key, value] : grid)
	{
		auto tile = scene.addRect(-tilesize / 2, -tilesize / 2, 100, 100, QPen(Qt::NoPen));
		tile->setPos(key.x, key.z);
		value.rect = tile;
	}

	robot = scene.addRect(QRectF(-200, -200, 400, 400), QPen(), QBrush(Qt::blue));
	noserobot = new QGraphicsEllipseItem(-50, 100, 100, 100, robot);
	noserobot->setBrush(Qt::magenta);

	this->Period = period;
	timer.start(Period);
	emit this->initializetocompute();
}

void SpecificWorker::compute()
{
	const float threshold = 200; // millimeters
	float rot = 0.6;			 // rads per second

	movimientoDefault(threshold, rot);
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
		// for (const auto &l: ldata)
		// 	std::cout << l.dist << " " << l.angle << std::endl;
		// std::cout << std::endl;

		std::sort(ldata.begin(), ldata.end(), [](RoboCompLaser::TData a, RoboCompLaser::TData b) { return a.dist < b.dist; });
		std::cout << ldata.back().dist << std::endl;

		switch (estado)
		{
		case base:
			differentialrobot_proxy->setSpeedBase(10, rot);
			differentialrobot_proxy->setSpeedBase(200, 0);
			estado = pared;
			break;

		case pared:

			break;

		case obstaculo:

			break;
		}

		if (ldata.front().dist < threshold)
		{
			std::cout << ldata.front().dist << std::endl;
			differentialrobot_proxy->setSpeedBase(10, rot);
			usleep(rand() % (1500000 - 100000 + 1) + 100000); // random wait between 1.5s and 0.1sec
		}
		else
		{
			differentialrobot_proxy->setSpeedBase(300, 0);
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

// bool SpecificWorker::obstacle()
// {
// 	//sort laser data from small to large distances using a lambda function.
// 	std::sort(ldata.begin(), ldata.end(), [](RoboCompLaser::TData a, RoboCompLaser::TData b) { return a.dist < b.dist; });
// 	if (ldata.front().dist < threshold)
// 	{
// 		return true;
// 	}
// 	return false;
// }

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
			differentialrobot_proxy->setSpeedBase(5, !rot);
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
