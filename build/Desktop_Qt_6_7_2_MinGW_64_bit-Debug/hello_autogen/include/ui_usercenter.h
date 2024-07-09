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

    void setupUi(QWidget *usercenter)
    {
        if (usercenter->objectName().isEmpty())
            usercenter->setObjectName("usercenter");
        usercenter->resize(400, 300);
        return_2 = new QPushButton(usercenter);
        return_2->setObjectName("return_2");
        return_2->setGeometry(QRect(300, 260, 80, 21));

        retranslateUi(usercenter);

        QMetaObject::connectSlotsByName(usercenter);
    } // setupUi

    void retranslateUi(QWidget *usercenter)
    {
        usercenter->setWindowTitle(QCoreApplication::translate("usercenter", "Form", nullptr));
        return_2->setText(QCoreApplication::translate("usercenter", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class usercenter: public Ui_usercenter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCENTER_H
