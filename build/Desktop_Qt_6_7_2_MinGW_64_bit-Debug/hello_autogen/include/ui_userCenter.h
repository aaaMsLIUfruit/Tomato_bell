/********************************************************************************
** Form generated from reading UI file 'userCenter.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCENTER_H
#define UI_USERCENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserCenter
{
public:
    QLabel *userInfo;
    QToolButton *UserName;
    QToolButton *Achievement;
    QComboBox *HistoryComboBox;
    QPushButton *pushButton;

    void setupUi(QWidget *UserCenter)
    {
        if (UserCenter->objectName().isEmpty())
            UserCenter->setObjectName("UserCenter");
        UserCenter->resize(456, 326);
        UserCenter->setMinimumSize(QSize(100, 50));
        UserCenter->setMaximumSize(QSize(16777215, 16777215));
        userInfo = new QLabel(UserCenter);
        userInfo->setObjectName("userInfo");
        userInfo->setGeometry(QRect(30, 40, 51, 51));
        UserName = new QToolButton(UserCenter);
        UserName->setObjectName("UserName");
        UserName->setGeometry(QRect(100, 40, 91, 51));
        Achievement = new QToolButton(UserCenter);
        Achievement->setObjectName("Achievement");
        Achievement->setGeometry(QRect(30, 120, 161, 51));
        HistoryComboBox = new QComboBox(UserCenter);
        HistoryComboBox->addItem(QString());
        HistoryComboBox->addItem(QString());
        HistoryComboBox->addItem(QString());
        HistoryComboBox->setObjectName("HistoryComboBox");
        HistoryComboBox->setGeometry(QRect(30, 210, 161, 22));
        pushButton = new QPushButton(UserCenter);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 260, 161, 18));

        retranslateUi(UserCenter);

        QMetaObject::connectSlotsByName(UserCenter);
    } // setupUi

    void retranslateUi(QWidget *UserCenter)
    {
        UserCenter->setWindowTitle(QCoreApplication::translate("UserCenter", "Form", nullptr));
        userInfo->setText(QString());
        UserName->setText(QCoreApplication::translate("UserCenter", "\347\224\250\346\210\267\345\220\215", nullptr));
        Achievement->setText(QCoreApplication::translate("UserCenter", "\347\224\250\346\210\267\346\210\220\345\260\261\357\274\232", nullptr));
        HistoryComboBox->setItemText(0, QCoreApplication::translate("UserCenter", "\346\227\245\350\256\260\345\275\225", nullptr));
        HistoryComboBox->setItemText(1, QCoreApplication::translate("UserCenter", "\346\234\210\350\256\260\345\275\225", nullptr));
        HistoryComboBox->setItemText(2, QCoreApplication::translate("UserCenter", "\345\271\264\350\256\260\345\275\225", nullptr));

        pushButton->setText(QCoreApplication::translate("UserCenter", "\346\225\260\346\215\256\345\210\206\346\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserCenter: public Ui_UserCenter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCENTER_H
