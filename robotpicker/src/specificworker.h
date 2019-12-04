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

#include <iostream>
#include <fstream>
#include <genericworker.h>
#include <Qt>
#include <innermodel/innermodel.h>
#include <QPolygon>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QMutexLocker>

class SpecificWorker : public GenericWorker
{
Q_OBJECT
public:
	SpecificWorker(TuplePrx tprx);
	~SpecificWorker();
	bool setParams(RoboCompCommonBehavior::ParameterList params);
	float rot;
	float threshold = 300; // millimeters
	TBaseState initialBstate;

	void GotoPoint_go(string nodo, float x, float y, float alpha);
	void GotoPoint_turn(float speed);
	bool GotoPoint_atTarget();
	void GotoPoint_stop();
	
	struct Target
	{
		mutable QMutex mutex;
		bool active;
		float x;
		float z;
		float a;
		float b;
		float c;
		float initX;
		float initY;
		float modVectorRecta;
		float bandera;
		
		Target()
		{
			active=false;
			x=0.0;
			z=0.0;
			bandera = false;
		}

		void setInitialPosition(float x, float z)
		{
			QMutexLocker locker(&mutex);
			initX=x;
			initY=z;
		}
		void set(float x_, float z_)
		{
			QMutexLocker locker(&mutex);
			active=true;
			x=x_;
			z=z_;
			a=z-initY;
			b=-(x-initX);
			c=(-b*initX)-(a*initY);
		}

		void setModVectorRecta(float mod)
		{
			QMutexLocker locker(&mutex);
			modVectorRecta=mod;
		}

		std::tuple<float,float,float> get() const
		{
			QMutexLocker locker(&mutex);
			return std::make_tuple(a,b,c);
		}

		void setBandera(bool _bandera)
		{
			bandera = _bandera;
		}

		float getModVectorRecta()
		{
			QMutexLocker locker(&mutex);
			return modVectorRecta;
		}
	
	};

	Target target;

	enum Estados
	{
		IDLE,
		TURN,
		GOTO,
		OBSTACULO,
		RODEAR
	};
	Estados estado = IDLE;

	void RCISMousePicker_setPick(Pick myPick);

public slots:
	void compute();
	void initialize(int period);
private:
	RoboCompGenericBase::TBaseState bState;
	RoboCompLaser::TLaserData ldata;
	std::shared_ptr<InnerModel> innermodel;
	void obstaculo();
	void goTo();
	void idle();
	void turn();
	void rodear();
	bool targetVisible();
	bool distanciaRecta(float x, float z);

};

#endif
