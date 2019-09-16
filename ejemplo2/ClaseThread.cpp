#include "ClaseThread.h"

ClaseThread::ClaseThread(int tiempo, QObject *parent)
    : QThread(parent)
{
    vTiempo = tiempo;
}
void ClaseThread::run()
{
    int contador = 0;
    while(true){
        if(contador == 100){
            contador = 0;
        }
        emit valorModificado(contador);
        msleep(vTiempo);
        contador++;
    }
}


