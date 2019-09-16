#ifndef CLASETHREAD_H
#define CLASETHREAD_H
#include <QObject>
#include <QThread>

class ClaseThread : public QThread
{
    Q_OBJECT
public:
    ClaseThread(int tiempo, QObject *parent = nullptr);
signals:
    void valorModificado(int);
protected:
    void run() override;    //Alt + Enter
private:
    int vTiempo;            //milisegundos
};
#endif // CLASETHREAD_H
