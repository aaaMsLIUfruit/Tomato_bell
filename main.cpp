#include "mainwindow.h"
#include <QScreen>
#include <QApplication>
#include<QtSql/QSqlDatabase>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);


    // QObject::connect(&signIn, &Sign_in::userLoggedIn, &startTask, &start_task::onUserLoggedIn);
    // QObject::connect(&signIn, &Sign_in::userLoggedIn, &userCenter, &usercenter::onUserLoggedIn);

    MainWindow w;
    w.show();


    return a.exec();
}
