/********************************************************************************
** Form generated from reading UI file 'Register.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *yes;
    QPushButton *return_2;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName("Register");
        Register->resize(400, 300);
        label = new QLabel(Register);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 120, 40, 12));
        label_2 = new QLabel(Register);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 160, 40, 12));
        label_3 = new QLabel(Register);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 200, 71, 21));
        lineEdit = new QLineEdit(Register);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(150, 120, 113, 20));
        lineEdit_2 = new QLineEdit(Register);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(150, 160, 113, 20));
        lineEdit_3 = new QLineEdit(Register);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(150, 200, 113, 20));
        yes = new QPushButton(Register);
        yes->setObjectName("yes");
        yes->setGeometry(QRect(130, 240, 80, 18));
        return_2 = new QPushButton(Register);
        return_2->setObjectName("return_2");
        return_2->setGeometry(QRect(10, 10, 80, 18));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Form", nullptr));
        label->setText(QCoreApplication::translate("Register", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("Register", "\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("Register", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        yes->setText(QCoreApplication::translate("Register", "\347\241\256\350\256\244", nullptr));
        return_2->setText(QCoreApplication::translate("Register", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
