#include "ejemplo1.h"


ejemplo1::ejemplo1(): Ui_Counter()
{
	setupUi(this);
	show();

	connect(button, SIGNAL(clicked()), this, SLOT(doButton()));
    connect(horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(doSlider(int)));

    mytimer.connect(std::bind(&ejemplo1::cuenta, this));
    mytimer.start(milisec);
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
        mytimer.start(milisec);
    qDebug() << "click on button";
}

void ejemplo1::doSlider(int valor)
{
    milisec = valor;
    mytimer.setPeriod(valor);


}

void ejemplo1::cuenta()
{
    lcdNumber->display(++cont);

}



