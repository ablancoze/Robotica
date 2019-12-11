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

/**
       \brief
       @author authorname
*/



#ifndef SPECIFICWORKER_H
#define SPECIFICWORKER_H

#include <genericworker.h>
#include <innermodel/innermodel.h>

class SpecificWorker : public GenericWorker
{
Q_OBJECT
public:

	enum class Estados{IDLE,TURN,CHECKTAG,GOTO,WAITING};
	Estados estado = Estados::IDLE;

	SpecificWorker(TuplePrx tprx);
	~SpecificWorker();
	bool setParams(RoboCompCommonBehavior::ParameterList params);

	void AprilTags_newAprilTagAndPose(tagsList tags, RoboCompGenericBase::TBaseState bState, RoboCompJointMotor::MotorStateMap hState);
	void AprilTags_newAprilTag(tagsList tags);
	using Tp = std::tuple<int,float,float,float>;
	
	struct Tag
	{
		mutable QMutex mutex;
		std::atomic_bool active;
		int id;
		float tx;
		float ty;
		float tz;
		float rx;
		float ry;
		float rz;
		string cameraId;
		std::vector<Tp> datos;
		Tag()
		{

		}

		void write(std::vector<Tp> &d)
		{
			QMutexLocker locker(&mutex);
			active.store(true);
			datos.swap(d);
		}

		std::vector<Tp> read()
		{
			QMutexLocker locker(&mutex);
			return datos;
		}

		bool isEmpty()
		{
			return active.load();	
		}
	};

Tag tag; 


public slots:
	void compute();
	void initialize(int period);
	void idle();
	void turn();
	void checkTag();
	void goTo();
//Specification slot methods State Machine
	void sm_compute();
	void sm_initialize();
	void sm_finalize();

//--------------------
private:
	std::shared_ptr<InnerModel> innerModel;

};

#endif
