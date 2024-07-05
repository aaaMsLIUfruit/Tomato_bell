/********************************************************************************
** Form generated from reading UI file 'mainclock.ui'
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

class Ui_mainclock
{
public:

    void setupUi(QWidget *mainclock)
    {
        if (mainclock->objectName().isEmpty())
            mainclock->setObjectName("mainclock");
        mainclock->resize(400, 300);

        retranslateUi(mainclock);

        QMetaObject::connectSlotsByName(mainclock);
    } // setupUi

    void retranslateUi(QWidget *mainclock)
    {
        mainclock->setWindowTitle(QCoreApplication::translate("mainclock", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainclock: public Ui_mainclock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCLOCK_H
