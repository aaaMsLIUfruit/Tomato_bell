/********************************************************************************
** Form generated from reading UI file 'usercenter.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCENTER_H
#define UI_USERCENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usercenter
{
public:
    QPushButton *return_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;

    void setupUi(QWidget *usercenter)
    {
        if (usercenter->objectName().isEmpty())
            usercenter->setObjectName(QString::fromUtf8("usercenter"));
        usercenter->resize(400, 300);
        return_2 = new QPushButton(usercenter);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(300, 260, 80, 21));
        radioButton = new QRadioButton(usercenter);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(150, 70, 73, 18));
        radioButton_2 = new QRadioButton(usercenter);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(150, 100, 73, 18));
        radioButton_3 = new QRadioButton(usercenter);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(150, 140, 73, 18));

        retranslateUi(usercenter);

        QMetaObject::connectSlotsByName(usercenter);
    } // setupUi

    void retranslateUi(QWidget *usercenter)
    {
        usercenter->setWindowTitle(QApplication::translate("usercenter", "Form", nullptr));
        return_2->setText(QApplication::translate("usercenter", "\350\277\224\345\233\236", nullptr));
        radioButton->setText(QApplication::translate("usercenter", "1", nullptr));
        radioButton_2->setText(QApplication::translate("usercenter", "2", nullptr));
        radioButton_3->setText(QApplication::translate("usercenter", "3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class usercenter: public Ui_usercenter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCENTER_H
