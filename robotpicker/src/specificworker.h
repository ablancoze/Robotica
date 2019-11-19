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


	struct Target
	{
		bool active;
		float x;
		float z;
		float a;
		float b;
		float c;
		float initX;
		float initY;
		
		Target()
		{
			active=false;
			x=0.0;
			z=0.0;
		}
		void setInitialPosition(float x, float z)
		{
			initX=x;
			initY=z;
		}
		void set(float x_, float z_)
		{
			active=true;
			x=x_;
			z=z_;
			a=z-initY;
			b=-(x-initX);
			c=(-b*initX)-(a*initY);
		}

		std::tuple<float,float,float> get() const
		{
			return std::make_tuple(a,b,c);
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
