/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *sign_in_button;
    QPushButton *register_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sign_in_button = new QPushButton(centralwidget);
        sign_in_button->setObjectName(QString::fromUtf8("sign_in_button"));
        sign_in_button->setGeometry(QRect(330, 220, 91, 31));
        sign_in_button->setStyleSheet(QString::fromUtf8("\n"
"font: \"\351\273\221\344\275\223\";\n"
"font-size: 15pt;\n"
"font-weight: bold;\n"
"color: #800000; "));
        register_button = new QPushButton(centralwidget);
        register_button->setObjectName(QString::fromUtf8("register_button"));
        register_button->setGeometry(QRect(330, 280, 91, 31));
        register_button->setStyleSheet(QString::fromUtf8("font: \"\351\273\221\344\275\223\";\n"
"font-size: 15pt;\n"
"font-weight: bold;\n"
"color: #800000; "));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        sign_in_button->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        register_button->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
