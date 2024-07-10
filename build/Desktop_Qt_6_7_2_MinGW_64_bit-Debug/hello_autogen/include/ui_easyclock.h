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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_easyclock
{
public:

    void setupUi(QWidget *easyclock)
    {
        if (easyclock->objectName().isEmpty())
            easyclock->setObjectName("easyclock");
        easyclock->resize(400, 300);

        retranslateUi(easyclock);

        QMetaObject::connectSlotsByName(easyclock);
    } // setupUi

    void retranslateUi(QWidget *easyclock)
    {
        easyclock->setWindowTitle(QCoreApplication::translate("easyclock", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class easyclock: public Ui_easyclock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EASYCLOCK_H
