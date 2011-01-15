#include <QtGui/QApplication>
#include "mutexplorer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mutexplorer w;
    w.show();
    return a.exec();
}
