#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config.h"

#include <QIcon>
#include <QApplication>
#include <QString>
#include <QScreen>
#include <QGuiApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWindow(){
    // 获取屏幕大小
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int width = screenGeometry.width();
    int height = screenGeometry.height();

    // 设置窗口大小为屏幕大小
    setGeometry(0, 0, width, height);

    //设置窗口的标题
    setWindowTitle(TITLE);

    //设置窗口的图标
    setWindowIcon(QIcon(ICON));

    // 调用update函数，强制窗口重绘，确保背景被正确加载和显示
    update();

};
