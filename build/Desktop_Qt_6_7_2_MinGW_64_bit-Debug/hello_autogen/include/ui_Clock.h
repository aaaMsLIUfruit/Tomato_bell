/********************************************************************************
** Form generated from reading UI file 'Clock.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCK_H
#define UI_CLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Clock
{
public:
    QPushButton *personal_center;
    QPushButton *start_task;

    void setupUi(QWidget *Clock)
    {
        if (Clock->objectName().isEmpty())
            Clock->setObjectName("Clock");
        Clock->resize(581, 413);
        personal_center = new QPushButton(Clock);
        personal_center->setObjectName("personal_center");
        personal_center->setGeometry(QRect(20, 80, 80, 21));
        start_task = new QPushButton(Clock);
        start_task->setObjectName("start_task");
        start_task->setGeometry(QRect(200, 130, 80, 21));

        retranslateUi(Clock);

        QMetaObject::connectSlotsByName(Clock);
    } // setupUi

    void retranslateUi(QWidget *Clock)
    {
        Clock->setWindowTitle(QCoreApplication::translate("Clock", "Form", nullptr));
        personal_center->setText(QCoreApplication::translate("Clock", "\344\270\252\344\272\272\344\270\255\345\277\203", nullptr));
        start_task->setText(QCoreApplication::translate("Clock", "\345\274\200\345\247\213\344\273\273\345\212\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Clock: public Ui_Clock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCK_H
