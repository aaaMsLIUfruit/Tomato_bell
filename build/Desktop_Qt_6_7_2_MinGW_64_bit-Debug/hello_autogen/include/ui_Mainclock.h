/********************************************************************************
** Form generated from reading UI file 'mainClock.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCLOCK_H
#define UI_MAINCLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mainclock
{
public:

    void setupUi(QWidget *Mainclock)
    {
        if (Mainclock->objectName().isEmpty())
            Mainclock->setObjectName("Mainclock");
        Mainclock->resize(400, 300);
        Mainclock->setAutoFillBackground(false);

        retranslateUi(Mainclock);

        QMetaObject::connectSlotsByName(Mainclock);
    } // setupUi

    void retranslateUi(QWidget *Mainclock)
    {
        Mainclock->setWindowTitle(QCoreApplication::translate("Mainclock", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mainclock: public Ui_Mainclock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCLOCK_H
