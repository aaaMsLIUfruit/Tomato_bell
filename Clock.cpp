#include "Clock.h"
#include "ui_Clock.h"
#include"start_task.h"
#include"usercenter.h"
#include <QIcon>
#include <QApplication>
#include <QString>
#include <QScreen>
#include <QGuiApplication>
#include <QPushButton>
#include <memory> // 包含智能指针的头文件
#include <QPainter>


Clock::Clock(QWidget *parent)
    : QWidget{parent},
    Start_task(nullptr),
    Usercenter(nullptr),
    ui(new Ui::Clock){
    //构造函数，初始化注册界面

    ui->setupUi(this);
    //initClock();

    starttask=new mypushbutton(":/xiaoba.png","");

    starttask->setParent(this);
    starttask->move(this->width()*0.5-starttask->width()*0.5,this->height()*0.3);

    personalcenter=new mypushbutton(":/personal2.png",":/personal1.png");
    personalcenter->setParent(this);
    personalcenter->move(this->width()*0.1,this->height()*0.1);

    if (parent) {
       parent->installEventFilter(this);
    }
    connect(starttask,&mypushbutton::clicked,this,&Clock::on_start_task_clicked);
    // connect(ui->start_task,&QPushButton::clicked,this,&Clock::on_start_task_clicked);
    connect(personalcenter,&mypushbutton::clicked,this,&Clock::on_personal_center_clicked);
}

// void Clock::initClock()
// {
//     QScreen *screen = QGuiApplication::primaryScreen();
//     QRect screenGeometry = screen->geometry();
//     int cwidth = screenGeometry.width();
//     int cheight = screenGeometry.height();

//     // 设置窗口大小为屏幕大小
//     setGeometry(0, 0, cwidth, cheight);

//     // 设置窗口的标题
//     setWindowTitle("番茄钟");

//     // 设置窗口的图标
//     setWindowIcon(QIcon(ICON));


//     // 调用 update 函数，强制窗口重绘，确保背景被正确加载和显示
//     update();
// }

void Clock::paintEvent(QPaintEvent *event) {
   QPainter painter(this);
   QPixmap pixmap(":/background1.jpg");
   painter.drawPixmap(0, 0, width(), height(), pixmap);
}


Clock::~Clock(){
    delete ui;
    if(starttask!=NULL)
        delete starttask;
    if(personalcenter!=NULL)
        delete personalcenter;
}

void Clock::on_return_to_Clock() {


    // ui->personal_center->show();
    // ui->start_task->show();
    starttask->show();
    personalcenter->show();
    update();
}


void Clock::on_start_task_clicked()
{
     starttask->room1();
    QTimer::singleShot(500,this,[=](){
        if (!Start_task) {
            Start_task = std::make_unique<start_task>(this);
            connect(Start_task.get(), &start_task::returnToClock, this, &Clock::on_return_to_Clock);
        }
    starttask->hide();
    personalcenter->hide();
    Start_task->show();
    });
}


void Clock::on_personal_center_clicked()
{
    if (!Usercenter) {
        Usercenter = std::make_unique<usercenter>(this);
        connect(Usercenter.get(), &usercenter::returnToClock, this, &Clock::on_return_to_Clock);
    }
    starttask->hide();
    personalcenter->hide();
    Usercenter->show();
}


