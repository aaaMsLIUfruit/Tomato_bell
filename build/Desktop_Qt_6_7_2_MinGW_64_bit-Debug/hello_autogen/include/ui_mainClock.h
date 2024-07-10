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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainClock
{
public:
    QPushButton *exitButton;
    QComboBox *MusicBox;

    void setupUi(QWidget *mainClock)
    {
        if (mainClock->objectName().isEmpty())
            mainClock->setObjectName("mainClock");
        mainClock->resize(800, 600);
        mainClock->setAutoFillBackground(false);
        exitButton = new QPushButton(mainClock);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(650, 530, 80, 18));
        MusicBox = new QComboBox(mainClock);
        MusicBox->addItem(QString());
        MusicBox->addItem(QString());
        MusicBox->addItem(QString());
        MusicBox->addItem(QString());
        MusicBox->addItem(QString());
        MusicBox->setObjectName("MusicBox");
        MusicBox->setGeometry(QRect(640, 60, 62, 22));

        retranslateUi(mainClock);

        QMetaObject::connectSlotsByName(mainClock);
    } // setupUi

    void retranslateUi(QWidget *mainClock)
    {
        mainClock->setWindowTitle(QCoreApplication::translate("mainClock", "Form", nullptr));
        exitButton->setText(QCoreApplication::translate("mainClock", "\351\200\200\345\207\272", nullptr));
        MusicBox->setItemText(0, QCoreApplication::translate("mainClock", "\346\236\227\344\270\255\347\273\206\351\233\250", nullptr));
        MusicBox->setItemText(1, QCoreApplication::translate("mainClock", "\345\267\264\351\273\216\345\222\226\345\225\241\351\246\206", nullptr));
        MusicBox->setItemText(2, QCoreApplication::translate("mainClock", "\346\262\231\346\273\251\346\265\267\346\265\252", nullptr));
        MusicBox->setItemText(3, QCoreApplication::translate("mainClock", "\346\234\252\351\200\211\346\213\251\351\237\263\344\271\220", nullptr));
        MusicBox->setItemText(4, QString());

    } // retranslateUi

};

namespace Ui {
    class mainClock: public Ui_mainClock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCLOCK_H
