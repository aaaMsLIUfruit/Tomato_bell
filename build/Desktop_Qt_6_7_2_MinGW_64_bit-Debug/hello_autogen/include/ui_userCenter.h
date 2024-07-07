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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usercenter
{
public:
    QToolButton *UserName;
    QToolButton *Achievement;
    QComboBox *HistoryComboBox;
    QPushButton *DataAnalysis;
    QPushButton *return_2;
    QWidget *chartWidget;

    void setupUi(QWidget *usercenter)
    {
        if (usercenter->objectName().isEmpty())
            usercenter->setObjectName("usercenter");
        usercenter->resize(456, 326);
        usercenter->setMinimumSize(QSize(100, 50));
        usercenter->setMaximumSize(QSize(16777215, 16777215));
        UserName = new QToolButton(usercenter);
        UserName->setObjectName("UserName");
        UserName->setGeometry(QRect(100, 40, 91, 51));
        Achievement = new QToolButton(usercenter);
        Achievement->setObjectName("Achievement");
        Achievement->setGeometry(QRect(30, 120, 161, 51));
        HistoryComboBox = new QComboBox(usercenter);
        HistoryComboBox->addItem(QString());
        HistoryComboBox->addItem(QString());
        HistoryComboBox->addItem(QString());
        HistoryComboBox->setObjectName("HistoryComboBox");
        HistoryComboBox->setGeometry(QRect(30, 210, 161, 22));
        DataAnalysis = new QPushButton(usercenter);
        DataAnalysis->setObjectName("DataAnalysis");
        DataAnalysis->setGeometry(QRect(30, 260, 161, 18));
        return_2 = new QPushButton(usercenter);
        return_2->setObjectName("return_2");
        return_2->setGeometry(QRect(330, 270, 80, 18));
        chartWidget = new QWidget(usercenter);
        chartWidget->setObjectName("chartWidget");
        chartWidget->setGeometry(QRect(240, 50, 161, 101));

        retranslateUi(usercenter);

        QMetaObject::connectSlotsByName(usercenter);
    } // setupUi

    void retranslateUi(QWidget *usercenter)
    {
        usercenter->setWindowTitle(QCoreApplication::translate("usercenter", "Form", nullptr));
        UserName->setText(QCoreApplication::translate("usercenter", "\347\224\250\346\210\267\345\220\215", nullptr));
        Achievement->setText(QCoreApplication::translate("usercenter", "\347\224\250\346\210\267\346\210\220\345\260\261\357\274\232", nullptr));
        HistoryComboBox->setItemText(0, QCoreApplication::translate("usercenter", "\346\227\245\350\256\260\345\275\225", nullptr));
        HistoryComboBox->setItemText(1, QCoreApplication::translate("usercenter", "\346\234\210\350\256\260\345\275\225", nullptr));
        HistoryComboBox->setItemText(2, QCoreApplication::translate("usercenter", "\345\271\264\350\256\260\345\275\225", nullptr));

        DataAnalysis->setText(QCoreApplication::translate("usercenter", "\346\225\260\346\215\256\345\210\206\346\236\220", nullptr));
        return_2->setText(QCoreApplication::translate("usercenter", "return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class usercenter: public Ui_usercenter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCENTER_H
