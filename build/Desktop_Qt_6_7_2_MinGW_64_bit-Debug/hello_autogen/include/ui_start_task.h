/********************************************************************************
** Form generated from reading UI file 'start_task.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_TASK_H
#define UI_START_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_start_task
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *spinBox;
    QPushButton *start;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QLineEdit *lineEdit;

    void setupUi(QWidget *start_task)
    {
        if (start_task->objectName().isEmpty())
            start_task->setObjectName("start_task");
        start_task->resize(400, 300);
        label = new QLabel(start_task);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 50, 161, 16));
        label_2 = new QLabel(start_task);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 80, 81, 16));
        label_3 = new QLabel(start_task);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 120, 81, 16));
        spinBox = new QSpinBox(start_task);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(120, 120, 42, 22));
        spinBox->setMaximum(10);
        start = new QPushButton(start_task);
        start->setObjectName("start");
        start->setGeometry(QRect(220, 220, 80, 21));
        pushButton_2 = new QPushButton(start_task);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(80, 220, 80, 21));
        comboBox = new QComboBox(start_task);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(120, 80, 101, 22));
        pushButton = new QPushButton(start_task);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(180, 160, 101, 21));
        lineEdit = new QLineEdit(start_task);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(50, 160, 113, 22));

        retranslateUi(start_task);

        QMetaObject::connectSlotsByName(start_task);
    } // setupUi

    void retranslateUi(QWidget *start_task)
    {
        start_task->setWindowTitle(QCoreApplication::translate("start_task", "Form", nullptr));
        label->setText(QCoreApplication::translate("start_task", "\345\274\200\345\247\213\344\270\200\344\270\252\347\225\252\350\214\204\351\222\237\344\273\273\345\212\241", nullptr));
        label_2->setText(QCoreApplication::translate("start_task", "\351\200\211\346\213\251\344\273\273\345\212\241\345\220\215\347\247\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("start_task", "\350\276\223\345\205\245\347\225\252\350\214\204\344\270\252\346\225\260\357\274\232", nullptr));
        start->setText(QCoreApplication::translate("start_task", "\345\274\200\345\247\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("start_task", "\345\217\226\346\266\210", nullptr));
        pushButton->setText(QCoreApplication::translate("start_task", "\346\267\273\345\212\240\345\270\270\347\224\250\344\273\273\345\212\241\346\240\207\347\255\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class start_task: public Ui_start_task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_TASK_H
