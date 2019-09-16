#include "widget.h"
#include "ui_widget.h"
#include "ClaseThread.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    vThread1 = new ClaseThread(10, this);
    vThread2 = new ClaseThread(20, this);
    vThread3 = new ClaseThread(40, this);

    ui->progressBar->setValue(0);
    ui->dial->setValue(0);
    ui->lcdNumber->display(0);

    connect(vThread1, SIGNAL(valorModificado(int)), ui->progressBar, SLOT(setValue(int)));
    connect(vThread2, SIGNAL(valorModificado(int)), ui->dial, SLOT(setValue(int)));
    connect(vThread3, SIGNAL(valorModificado(int)), ui->lcdNumber, SLOT(display(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_iniciarBoton_clicked()
{
    printf("Iniciado...\n");
    vThread1->start();
    vThread2->start();
    vThread3->start();
}

void Widget::on_detenerBoton_clicked()
{
    printf("Detenido...\n");
    vThread1->terminate();
    vThread2->terminate();
    vThread3->terminate();
}
