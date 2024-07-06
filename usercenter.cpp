#include "usercenter.h"
#include "ui_userCenter.h"

UserCenter::UserCenter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserCenter) {
    ui->setupUi(this);

    // 设置用户图片
    QPixmap pixmap(":/resources/user.png");
    ui->userInfo->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));


}

UserCenter::~UserCenter() {
    delete ui;
}
