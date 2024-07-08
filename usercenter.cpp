#include "usercenter.h"
#include "qboxlayout.h"
#include "ui_usercenter.h"
#include "config.h"
#include<QDebug>
#include<QSqlError>
#include<QSqlQuery>
#include<QMessageBox>
usercenter::usercenter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::usercenter),currentUserId(-1)

{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("TOMATO");
    db.setUserName("root");
    db.setPassword("YourPassword");
    db.setPort(3306);

    if (!db.open()) {
        qDebug() << "Failed to connect to database:" << db.lastError().text();
    }
    else
        qDebug()<<"already connected to database";



    ui->setupUi(this);

    setWindowTitle("个人中心");
    setWindowIcon(QIcon(ICON));

    QPixmap *pix=new QPixmap(":/icon.png");
    QLabel* UserImg=new QLabel;

    UserImg->setParent(this);
    UserImg->setFixedSize(ui->UserName->height(),ui->UserName->height());
    UserImg->move(ui->Achievement->x(),ui->UserName->y());


    pix->scaled(UserImg->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    UserImg->setScaledContents(true);
    UserImg->setPixmap(*pix);

    connect(ui->return_2,&QPushButton::clicked,this,&usercenter::on_return_2_clicked);

}

usercenter::~usercenter()
{
    delete ui;

}

void usercenter::onUserLoggedIn(int userId) {
    currentUserId = userId;
    displayUsername(); // 显示用户名
}

void usercenter::displayUsername()
{
    if (currentUserId == -1) {
        ui->UserName->setText("未知用户");
        return;
    }

    QSqlQuery query(db);
    query.prepare("SELECT username FROM Users WHERE id = :id");
    query.bindValue(":id", currentUserId);
    if (query.exec() && query.next()) {
        QString username = query.value(0).toString();
        ui->UserName->setText(username);
    } else {
        ui->UserName->setText("未知用户");
    }
}


void usercenter::on_return_2_clicked()
{
    emit returnToClock();
    close();
}

