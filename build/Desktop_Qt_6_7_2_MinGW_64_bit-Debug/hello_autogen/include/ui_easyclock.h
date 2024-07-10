/********************************************************************************
** Form generated from reading UI file 'easyclock.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EASYCLOCK_H
#define UI_EASYCLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_easyclock
{
public:
    QPushButton *exitButton;

    void setupUi(QWidget *easyclock)
    {
        if (easyclock->objectName().isEmpty())
            easyclock->setObjectName("easyclock");
        easyclock->resize(800, 600);
        exitButton = new QPushButton(easyclock);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(660, 550, 80, 21));

        retranslateUi(easyclock);

        QMetaObject::connectSlotsByName(easyclock);
    } // setupUi

    void retranslateUi(QWidget *easyclock)
    {
        easyclock->setWindowTitle(QCoreApplication::translate("easyclock", "Form", nullptr));
        exitButton->setText(QCoreApplication::translate("easyclock", "\350\277\224\345\233\236\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class easyclock: public Ui_easyclock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EASYCLOCK_H
