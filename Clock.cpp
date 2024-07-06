#include "Clock.h"
#include "ui_Clock.h"
#include"config.h"

Clock::Clock(QWidget *parent)
    : QWidget{parent},
    ui(new Ui::Clock){
    //构造函数，初始化注册界面
    ui->setupUi(this);

    setWindowTitle("番茄钟");
    setWindowIcon(QIcon(ICON));


    if (parent) {
        parent->installEventFilter(this);
    }

}

Clock::~Clock(){
    delete ui;
}
