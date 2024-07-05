#include "Register.h"
#include "ui_Register.h"
#include "config.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QMoveEvent>

Register::Register(QWidget *parent)
    : QWidget{parent},
    ui(new Ui::Register){
    //构造函数，初始化注册界面
    ui->setupUi(this);

    setWindowTitle("注册");
    setWindowIcon(QIcon(ICON));


    if (parent) {
        parent->installEventFilter(this);
    }

    connect(ui->yes, &QPushButton::clicked, this, &Register::on_yes_clicked);
    connect(ui->return_2, &QPushButton::clicked, this, &Register::on_return_button_clicked);

}

bool Register::eventFilter(QObject *obj, QEvent *event) {
    if (obj == parent()) {
        if (event->type() == QEvent::Move) {
            // 处理窗口移动事件
            QWidget *parentWidget = qobject_cast<QWidget *>(parent());
            if (parentWidget) {
                QRect parentGeometry = parentWidget->geometry();
                int x = parentGeometry.x() + (parentGeometry.width() - width()) / 2;
                int y = parentGeometry.y() + (parentGeometry.height() - height()) / 2;
                move(x, y);  // 移动窗口以保持居中
            }
        }
    }

    return QWidget::eventFilter(obj, event);  // 返回事件处理结果
}


void Register::showEvent(QShowEvent *event) {
    // 显示事件处理
    QWidget::showEvent(event);

    // 确保窗口在父窗口居中
    if (parentWidget()) {
        QRect parentGeometry = parentWidget()->geometry();
        int x = parentGeometry.x() + (parentGeometry.width() - width()) / 2;
        int y = parentGeometry.y() + (parentGeometry.height() - height()) / 2;
        move(x, y);  // 调整位置以居中
    }
}

void Register::on_return_button_clicked() {
    emit returnToMain(); // 发射自定义信号
    close(); // 关闭注册界面
}

void Register::on_yes_clicked(){
    emit returnToMain();
    close();
}

Register::~Register(){
    delete ui;
}


