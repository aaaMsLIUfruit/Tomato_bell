#include "mainwindow.h"
#include <QScreen>
#include <QApplication>
#include<QtSql/QSqlDatabase>

#include <QApplication>
#include <QFontDatabase>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    int fontId = QFontDatabase::addApplicationFont(QStringLiteral(":/ziti.ttf"));
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
    if (fontFamilies.size() > 0)
    {
        QFont font;
        font.setFamily(fontFamilies[0]);//设置全局字体
        a.setFont(font);
    }


    // QObject::connect(&signIn, &Sign_in::userLoggedIn, &startTask, &start_task::onUserLoggedIn);
    // QObject::connect(&signIn, &Sign_in::userLoggedIn, &userCenter, &usercenter::onUserLoggedIn);

    MainWindow w;
    w.show();


    return a.exec();
}
