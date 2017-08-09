#include <QCoreApplication>
#include "pedestrian_detect.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    pedestrian_detect d;
    printf("start\n");
    d.start();
    printf("start done");
    return a.exec();
}

