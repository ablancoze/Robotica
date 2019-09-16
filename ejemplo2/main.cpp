/*      Borja Alberto Tirado Galan
 *      Alvaro Blanco Mangut
 *      Ejercicio 2 - QThread
 *
 */

#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("timer");
    Widget w;
    w.show();

    return a.exec();
}
