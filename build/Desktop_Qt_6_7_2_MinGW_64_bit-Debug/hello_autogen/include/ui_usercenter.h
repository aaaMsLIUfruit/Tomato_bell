/********************************************************************************
** Form generated from reading UI file 'usercenter.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCENTER_H
#define UI_USERCENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usercenter
{
public:
    QPushButton *return_2;
    QWidget *chartWidget;

    void setupUi(QWidget *usercenter)
    {
        if (usercenter->objectName().isEmpty())
            usercenter->setObjectName("usercenter");
        usercenter->resize(800, 600);
        usercenter->setMinimumSize(QSize(100, 50));
        usercenter->setMaximumSize(QSize(16777215, 16777215));
        return_2 = new QPushButton(usercenter);
        return_2->setObjectName("return_2");
        return_2->setGeometry(QRect(10, 180, 80, 18));
        chartWidget = new QWidget(usercenter);
        chartWidget->setObjectName("chartWidget");
        chartWidget->setGeometry(QRect(240, 50, 161, 101));

        retranslateUi(usercenter);

        QMetaObject::connectSlotsByName(usercenter);
    } // setupUi

    void retranslateUi(QWidget *usercenter)
    {
        usercenter->setWindowTitle(QCoreApplication::translate("usercenter", "Form", nullptr));
        return_2->setText(QCoreApplication::translate("usercenter", "return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class usercenter: public Ui_usercenter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCENTER_H
