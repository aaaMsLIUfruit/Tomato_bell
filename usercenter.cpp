#include "usercenter.h"
#include "ui_usercenter.h"
#include "config.h"

usercenter::usercenter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::usercenter)

{
    ui->setupUi(this);

    setWindowTitle("个人中心");
    setWindowIcon(QIcon(ICON));

    connect(ui->return_2,&QPushButton::clicked,this,&usercenter::on_return_2_clicked);
}

usercenter::~usercenter()
{
    delete ui;

}



void usercenter::on_return_2_clicked()
{
    emit returnToClock();
    close();
}

