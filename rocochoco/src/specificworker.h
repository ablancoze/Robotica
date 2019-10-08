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
#include "grid.h"
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
	QGraphicsScene scene;
	QGraphicsView view;
	QGraphicsRectItem *robot;
	QGraphicsEllipseItem *noserobot;

public slots:
	void compute();
	void initialize(int period,RoboCompCommonBehavior::ParameterList params);
	//Specification slot methods State Machine
	void sm_compute();
	void sm_initialize();
	void sm_finalize();
	void movimientoDefault(float threshold, float rot);
	void movimientoRoco(float threshold, float rot);
	void maquinaEstados(float threshold, float rot);
	//--------------------
private:
	std::shared_ptr<InnerModel> innerModel;
	RoboCompGenericBase::TBaseState bState;
	int tilesize;
	struct TCell
	{
		uint id;
		bool free;
		bool visited;
		QGraphicsRectItem *rect;
		float cost = 1;

		// method to save the value
		void save(std::ostream &os) const { os << free << " " << visited; };
		void read(std::istream &is) { is >> free >> visited; };
	};
	using TDim = Grid<TCell>::Dimensions;
	Grid<TCell> grid;
};

#endif
