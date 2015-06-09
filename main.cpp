#include "mainwindow.h"
#include "core.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Core core;
    core.start();

    return a.exec();
}
