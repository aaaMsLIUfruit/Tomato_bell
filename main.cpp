#include "mainwindow.h"
#include <QScreen>
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QRect screenRect=QGuiApplication::primaryScreen()->geometry();

    return a.exec();
}
