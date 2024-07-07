#include "Register.h"
#include "qsqlquery.h"
#include "ui_Register.h"
#include "config.h"
#include <QRegularExpression>
#include<QSqlError>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    setWindowTitle("注册");
    setWindowIcon(QIcon(ICON));

    // 初始化时禁用输入字段
    enableInputFields(false);

    if (parent)
    {
        parent->installEventFilter(this);
    }

    connect(ui->yes, &QPushButton::clicked, this, &Register::on_yes_clicked);
    connect(ui->return_2, &QPushButton::clicked, this, &Register::on_return_button_clicked);

    //显示用户注册协议
    showAgreement();

    // 初始化数据库连接
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("Fighting");
    db.setDatabaseName("TOMATO");
    db.setUserName("root");
    db.setPassword("Bestran123");

    if (!db.open()) {
        qDebug() << "Failed to connect to database:" << db.lastError().text();
    }
}

bool Register::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == parent())
    {
        if (event->type() == QEvent::Move)
        {
            // 处理窗口移动事件
            QWidget *parentWidget = qobject_cast<QWidget *>(parent());
            if (parentWidget)
            {
                QRect parentGeometry = parentWidget->geometry();
                int x = parentGeometry.x() + (parentGeometry.width() - width()) / 2;
                int y = parentGeometry.y() + (parentGeometry.height() - height()) / 2;
                move(x, y);  // 移动窗口以保持居中
            }
        }
    }

    return QWidget::eventFilter(obj, event);  // 返回事件处理结果
}

void Register::showEvent(QShowEvent *event)
{
    // 显示事件处理
    QWidget::showEvent(event);

    // 确保窗口在父窗口居中
    if (parentWidget())
    {
        QRect parentGeometry = parentWidget()->geometry();
        int x = parentGeometry.x() + (parentGeometry.width() - width()) / 2;
        int y = parentGeometry.y() + (parentGeometry.height() - height()) / 2;
        move(x, y);  // 调整位置以居中
    }
}

//新增
bool Register::validateAccount()
{ QString account = ui->lineEdit->text(); // 获取账号输入框的内容

    // 验证账号是否为11位数字
    QRegularExpression re("\\d{11}");
    QRegularExpressionMatch match = re.match(account);
    if (!match.hasMatch())
    {
        QMessageBox::warning(this, "输入错误", "账号必须为11位数字构成的手机号码！", QMessageBox::Ok);
        return false;
    }
    return true;
}

//新增
bool Register::validatePasswords()
{
    QString password1 = ui->lineEdit_2->text();
    QString password2 = ui->lineEdit_3->text();

    if (password1 != password2)
    {
        QMessageBox::warning(this, "输入错误", "两次输入的密码不一致！", QMessageBox::Ok);
        return false;
    }

    if (password1.length() > 15)
    {
        QMessageBox::warning(this, "输入错误", "密码长度不能超过15个字符！", QMessageBox::Ok);
        return false;
    }

    QRegularExpression re("^[a-zA-Z0-9]*$");
    QRegularExpressionMatch match = re.match(password1);
    if (!match.hasMatch())
    {
        QMessageBox::warning(this, "输入错误", "密码只能包含字母和数字！", QMessageBox::Ok);
        return false;
    }

    return true;
}

//新增
void Register::showAgreement()
{
    QMessageBox::information(this, "用户注册协议",
                             "1.您输入的账号需为本人手机号码，由十一位有效数字构成"
                             "2.您所设置的账户密码不得超过15个字符（密码可包含数字、大小写字母、字符）",
                             QMessageBox::Ok);
    // 启用输入字段
    enableInputFields(true);
}

//新增
void Register::enableInputFields(bool enable)
{
    ui->lineEdit->setEnabled(enable);
    ui->lineEdit_2->setEnabled(enable);
    ui->lineEdit_3->setEnabled(enable);
    ui->yes->setEnabled(enable);
}


// 检查用户是否存在
bool Register::isUserExists(const QString &username)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Users WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        qDebug() << "Failed to check user:" << query.lastError().text();
        QMessageBox::critical(this, "数据库错误", "检查用户时出错，请稍后重试。");
        return true;  // 出现错误时，假设用户存在以防止错误的注册
    }

    if (query.next() && query.value(0).toInt() > 0) {
        return true;
    }

    return false;
}

// 将用户信息写入数据库
void Register::addUserToDatabase(const QString &username, const QString &password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Failed to insert new user:" << query.lastError().text();
        QMessageBox::critical(this, "数据库错误", "无法将用户添加到数据库，请稍后重试。");
    } else {
        QMessageBox::information(this, "注册成功", "用户注册成功！");
    }
}

//完成注册
void Register::on_yes_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    if (validateAccount() && validatePasswords())
    {
        if (isUserExists(username)) {
            QMessageBox::warning(this, "注册失败", "该用户名已存在，请选择其他用户名。");
            // 清空输入框，回到注册页面
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
        } else {
            addUserToDatabase(username, password);
            emit returnToMain();
            close();
        }
    }
}


void Register::on_return_button_clicked() {
    emit returnToMain(); // 发射自定义信号
    close(); // 关闭注册界面
}


Register::~Register()
{
    delete ui;
}
