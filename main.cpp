#include "mainwindow.h"
#include "Sign_in.h"
#include "start_task.h"
#include "usercenter.h"

#include <QApplication>
#include<QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sign_in signIn;
    start_task startTask;
    usercenter userCenter;

    QObject::connect(&signIn, &Sign_in::userLoggedIn, &startTask, &start_task::onUserLoggedIn);
    QObject::connect(&signIn, &Sign_in::userLoggedIn, &userCenter, &usercenter::onUserLoggedIn);

    MainWindow w;
    w.show();

    return a.exec();
}
