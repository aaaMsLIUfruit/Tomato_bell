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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainClock
{
public:
    QPushButton *exitButton;

    void setupUi(QWidget *mainClock)
    {
        if (mainClock->objectName().isEmpty())
            mainClock->setObjectName("mainClock");
        mainClock->resize(800, 600);
        mainClock->setAutoFillBackground(false);
        exitButton = new QPushButton(mainClock);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(650, 530, 80, 18));

        retranslateUi(mainClock);

        QMetaObject::connectSlotsByName(mainClock);
    } // setupUi

    void retranslateUi(QWidget *mainClock)
    {
        mainClock->setWindowTitle(QCoreApplication::translate("mainClock", "Form", nullptr));
        exitButton->setText(QCoreApplication::translate("mainClock", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainClock: public Ui_mainClock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCLOCK_H
