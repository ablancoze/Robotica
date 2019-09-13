#ifndef ejemplo1_H
#define ejemplo1_H

#include <QtGui>
#include <QTimer>
#include "ui_counterDlg.h"

class ejemplo1 : public QWidget, public Ui_Counter
{
Q_OBJECT
public:
    ejemplo1();
    virtual ~ejemplo1();

private:
	QTimer mytimer;
	int cont = 0;
		
	// dos callbacks con diferente número de parámetros

public slots:
	void doButton();
    void cuenta();
};

#endif // ejemplo1_H
