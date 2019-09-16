#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class ClaseThread;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_iniciarBoton_clicked();

    void on_detenerBoton_clicked();

private:
    Ui::Widget *ui;
    ClaseThread *vThread1;
    ClaseThread *vThread2;
    ClaseThread *vThread3;
};

#endif // WIDGET_H
