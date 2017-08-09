#include <QCoreApplication>
#include "pedestrian_detection.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Pedestrian_detection p;
    p.start();
    return a.exec();
}

