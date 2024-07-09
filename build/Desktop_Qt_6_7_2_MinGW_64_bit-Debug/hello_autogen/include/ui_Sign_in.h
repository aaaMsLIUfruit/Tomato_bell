/********************************************************************************
** Form generated from reading UI file 'Sign_in.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_IN_H
#define UI_SIGN_IN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sign_in
{
public:
    QLineEdit *account;
    QLineEdit *password;
    QLabel *label;
    QLabel *label_2;
    QPushButton *yes;
    QPushButton *return_2;

    void setupUi(QWidget *Sign_in)
    {
        if (Sign_in->objectName().isEmpty())
            Sign_in->setObjectName("Sign_in");
        Sign_in->resize(800, 800);
        account = new QLineEdit(Sign_in);
        account->setObjectName("account");
        account->setGeometry(QRect(400, 300, 300, 35));
        account->setEchoMode(QLineEdit::Password);
        password = new QLineEdit(Sign_in);
        password->setObjectName("password");
        password->setGeometry(QRect(400, 200, 300, 35));
        password->setEchoMode(QLineEdit::Normal);
        label = new QLabel(Sign_in);
        label->setObjectName("label");
        label->setGeometry(QRect(360, 200, 60, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(Sign_in);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(360, 300, 60, 30));
        label_2->setFont(font);
        yes = new QPushButton(Sign_in);
        yes->setObjectName("yes");
        yes->setGeometry(QRect(500, 400, 120, 30));
        yes->setFont(font);
        return_2 = new QPushButton(Sign_in);
        return_2->setObjectName("return_2");
        return_2->setGeometry(QRect(100, 100, 150, 50));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font1.setPointSize(16);
        return_2->setFont(font1);

        retranslateUi(Sign_in);

        QMetaObject::connectSlotsByName(Sign_in);
    } // setupUi

    void retranslateUi(QWidget *Sign_in)
    {
        Sign_in->setWindowTitle(QCoreApplication::translate("Sign_in", "Form", nullptr));
        label->setText(QCoreApplication::translate("Sign_in", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("Sign_in", "\345\257\206\347\240\201", nullptr));
        yes->setText(QCoreApplication::translate("Sign_in", "\347\231\273\345\275\225", nullptr));
        return_2->setText(QCoreApplication::translate("Sign_in", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sign_in: public Ui_Sign_in {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_IN_H
