#include "ejemplo1.h"

ejemplo1::ejemplo1(): Ui_Counter() 
{

	setupUi(this);
	show();
	connect(button, SIGNAL(clicked()), this, SLOT(doButton()) );
	connect(&mytimer, SIGNAL(timeout()), this, SLOT(cuenta()) );
    mytimer.start(500);
}

ejemplo1::~ejemplo1()
{}

void ejemplo1::doButton()
{
	static bool stopped = false;
	stopped = !stopped;
	if(stopped)
		mytimer.stop();
	else
		mytimer.start(500);
	qDebug() << "click on button";
}
void ejemplo1::cuenta(){

	lcdNumber->display(++cont);
}




