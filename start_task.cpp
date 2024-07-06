#include "start_task.h"
#include "ui_start_task.h"
#include "config.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QMoveEvent>


start_task::start_task(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::start_task),
    Mainclock(nullptr)
{
    ui->setupUi(this);

    setWindowTitle("任务设置");
    setWindowIcon(QIcon(ICON));



    ui->comboBox->addItem("学习");
    ui->comboBox->addItem("工作");
    ui->comboBox->setCurrentText(" ");
    ui->comboBox->setEditable(true);

    ui->spinBox->setValue(0);


    // ComboBox槽函数
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &start_task::on_comboBox_currentTextChanged);
    connect(ui->comboBox,&QComboBox::editTextChanged,this,&start_task::on_comboBox_editTextChanged);

    //connect(ui->comboBox,&QComboBox::textActivated,this,&start_task::on_comboBox_textActivated);
    // QSpinBox槽函数
    connect(ui->spinBox, &QSpinBox::valueChanged, this, &start_task::on_spinBox_valueChanged);

    connect(ui->pushButton_2, &QPushButton::clicked, this, &start_task::on_pushButton_2_clicked);

    connect(ui->start,&QPushButton::clicked,this,&start_task::on_start_clicked);

    connect(ui->pushButton,&QPushButton::clicked,this,&start_task::on_pushButton_clicked);
}

start_task::~start_task()
{
    delete ui;
    if (Mainclock != nullptr) {
        delete Mainclock;
    }

}



void start_task::on_start_clicked()
{
    if (Mainclock == nullptr) {
        Mainclock = new mainclock(this); // 创建新的 mainclock 对象
        Mainclock->setAttribute(Qt::WA_DeleteOnClose); // 窗口关闭时自动删除
    }

    QString comboBoxData=ui->comboBox->currentText();
    int spinBoxData=ui->spinBox->value();

    // 传递数据

    Mainclock->setComboBoxData(comboBoxData);
    Mainclock->setSpinBoxData(spinBoxData);

    // 显示新页面

    ui->pushButton_2->hide();
    ui->comboBox->hide();
    ui->pushButton->hide();
    ui->spinBox->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->lineEdit->hide();
    ui->start->hide();
    Mainclock->show();
}


void start_task::on_pushButton_2_clicked()
{
    emit returnToClock();
    close();
}




void start_task::on_comboBox_editTextChanged(const QString &arg1)
{

    //ui->comboBox->setEditable(true);
    ui->comboBox->setCurrentText(arg1);

}


void start_task::on_comboBox_currentTextChanged(const QString &arg1)
{
   ui->comboBox->setCurrentText(arg1);
}


void start_task::on_spinBox_valueChanged(int arg1)
{
    ui->spinBox->setValue(arg1);
}





//void start_task::on_comboBox_textActivated(const QString &arg1)
//{
//    ui->comboBox->setCurrentText(arg1);
//}


void start_task::on_pushButton_clicked()
{
    if(!ui->lineEdit->text().isEmpty())
    {   ui->comboBox->setEditable(true);
        ui->comboBox->addItem(ui->lineEdit->text());
        ui->lineEdit->clear();
    }

}

