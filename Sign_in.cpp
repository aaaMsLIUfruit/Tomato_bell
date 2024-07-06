
#include "Sign_in.h"
#include "ui_Sign_in.h"
#include "config.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QMoveEvent>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Sign_in::Sign_in(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sign_in),
    clock(nullptr) { // 初始化指针为 nullptr
    // 构造函数，初始化登陆界面
    ui->setupUi(this);

    setWindowTitle("登录");
    setWindowIcon(QIcon(ICON));



    if (parent) {
        parent->installEventFilter(this);
    }

    connect(ui->yes, &QPushButton::clicked, this, &Sign_in::on_yes_clicked);
    connect(ui->return_2,&QPushButton::clicked, this, &Sign_in::on_return_button_clicked);


}

bool Sign_in::eventFilter(QObject *obj, QEvent *event) {
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

void Sign_in::showEvent(QShowEvent *event) {
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

bool Sign_in::validateAccount() {
    QString account = ui->account->text(); // 获取账号输入框的内容

    // 验证账号是否为11位数字
    QRegularExpression re("\\d{11}");
    QRegularExpressionMatch match = re.match(account);
    if (!match.hasMatch()) {
        QMessageBox::warning(this, "输入错误", "账号必须为11位数字构成的手机号码！", QMessageBox::Ok);
        return false;
    }
    return true;
}

bool Sign_in::validatePassword() {
    QString password = ui->password->text(); // 获取密码输入框的内容

    // 验证密码是否为不超过15个字符的数字、字母、字符的组合
    QRegularExpression re("^[\\w!@#$%^&*()_+\\-=\\[\\]{};':\"\\\\|,.<>/?]{1,15}$");
    QRegularExpressionMatch match = re.match(password);
    if (!match.hasMatch()) {
        QMessageBox::warning(this, "输入错误", "密码必须是不超过15个字符的数字、字母、字符的组合！请输入正确密码！", QMessageBox::Ok);
        return false;
    }
    return true;
}

void Sign_in::on_yes_clicked() {
    if (!validateAccount() || !validatePassword()) {
        return; // 如果账号或密码验证失败，直接返回
    }

    if (clock == nullptr) {
        clock = new Clock(this); // 创建新的 Clock 对象
        clock->setAttribute(Qt::WA_DeleteOnClose); // 窗口关闭时自动删除
    }
    ui->yes->hide();
    ui->account->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->password->hide();
    ui->return_2->hide();
    clock->show();
}

void Sign_in::on_return_button_clicked() {
    emit returnToMain(); // 发射自定义信号

    close(); // 关闭注册界面
}

Sign_in::~Sign_in() {
    delete ui;
    // 删除 clock 指针
    if (clock != nullptr) {
        delete clock;
    }
}
