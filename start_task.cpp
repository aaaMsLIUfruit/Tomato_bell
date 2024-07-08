#include "start_task.h"
#include "ui_start_task.h"
#include "config.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QMoveEvent>
#include <memory>


start_task::start_task(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::start_task),
    mainclock(nullptr)
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
}



void start_task::on_start_clicked()
{
    if (mainclock == nullptr) {
        mainclock = std::make_unique<Mainclock>(this); // 创建新的 mainclock 对象
        mainclock->setAttribute(Qt::WA_DeleteOnClose); // 窗口关闭时自动删除
        connect(mainclock.get(), &Mainclock::returntoClockyes, this, &start_task::on_return_to_start_task1);
        connect(mainclock.get(),&Mainclock::returntoClockno, this, &start_task::on_return_to_start_task2);
    }

    int spinBoxData=ui->spinBox->value();
    QString comboBoxData=ui->comboBox->currentText();

    // 传递数据
    mainclock->setComBoxData(comboBoxData);
    mainclock->setSpinBoxData(spinBoxData);

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
    mainclock->show();
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

void start_task::on_return_to_start_task1(){
    ui->pushButton_2->show();
    ui->comboBox->show();
    ui->pushButton->show();
    ui->spinBox->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->lineEdit->show();
    ui->start->show();
    mainclock.reset();

    QMessageBox::information(this, "任务完成", "你已成功完成任务！");
}

void start_task::on_return_to_start_task2(){
    ui->pushButton_2->show();
    ui->comboBox->show();
    ui->pushButton->show();
    ui->spinBox->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->lineEdit->show();
    ui->start->show();
    mainclock.reset();

    QMessageBox::information(this, "任务失败", "任务失败，再接再厉吧");
}

