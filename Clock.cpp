#include "Clock.h"
#include "ui_Clock.h"
#include"config.h"
#include"start_task.h"
#include"usercenter.h"
#include"mainClock.h"
#include <QIcon>
#include <QApplication>
#include <QString>
#include <QScreen>
#include <QGuiApplication>
#include <QPushButton>
#include <memory> // 包含智能指针的头文件


Clock::Clock(QWidget *parent)
    : QWidget{parent},
    Start_task(nullptr),
    Usercenter(nullptr),
    ui(new Ui::Clock){
    //构造函数，初始化注册界面

    ui->setupUi(this);

    setWindowTitle("番茄钟");
    setWindowIcon(QIcon(ICON));


    if (parent) {
       parent->installEventFilter(this);
    }

    connect(ui->start_task,&QPushButton::clicked,this,&Clock::on_start_task_clicked);
    connect(ui->personal_center,&QPushButton::clicked,this,&Clock::on_personal_center_clicked);
}

void Clock::paintEvent(QPaintEvent *event) {
   QPainter painter(this);
   QPixmap pixmap(CLOCK);
   painter.drawPixmap(0, 0, width(), height(), pixmap);
}


Clock::~Clock(){
    delete ui;

}

void Clock::on_return_to_Clock() {


    ui->personal_center->show();
    ui->start_task->show();
    update();
}


void Clock::on_start_task_clicked()
{
    if (!Start_task) {
        Start_task = std::make_unique<start_task>(this);
        connect(Start_task.get(), &start_task::returnToClock, this, &Clock::on_return_to_Clock);
    }
    ui->start_task->hide();
    ui->personal_center->hide();
    Start_task->show();
}


void Clock::on_personal_center_clicked()
{
    if (!Usercenter) {
        Usercenter = std::make_unique<usercenter>(this);
        connect(Usercenter.get(), &usercenter::returnToClock, this, &Clock::on_return_to_Clock);
    }
    ui->start_task->hide();
    ui->personal_center->hide();
    Usercenter->show();
}


