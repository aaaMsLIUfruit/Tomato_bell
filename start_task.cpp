#include "start_task.h"
#include "qsqlquery.h"
#include "ui_start_task.h"
#include "config.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QMoveEvent>
#include <memory>


start_task::start_task(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::start_task),currentUserId(-1),
    mainclock(nullptr)
{
    if (!createConnection()) {
        qDebug() << "Failed to connect to database.";
    }

    ui->setupUi(this);

    setWindowTitle("任务设置");
    setWindowIcon(QIcon(ICON));



    ui->comboBox->addItem("学习");
    ui->comboBox->addItem("工作");
    ui->comboBox->setCurrentText(" ");
    ui->comboBox->setEditable(true);

    ui->spinBox->setValue(0);


    // ComboBox槽函数
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &start_task::on_comboBox_currentTextChanged);
    connect(ui->comboBox,&QComboBox::editTextChanged,this,&start_task::on_comboBox_editTextChanged);

    //connect(ui->comboBox,&QComboBox::textActivated,this,&start_task::on_comboBox_textActivated);
    // QSpinBox槽函数
    connect(ui->spinBox, &QSpinBox::valueChanged, this, &start_task::on_spinBox_valueChanged);

    connect(ui->pushButton_2, &QPushButton::clicked, this, &start_task::on_pushButton_2_clicked);

    connect(ui->start,&QPushButton::clicked,this,&start_task::on_start_clicked);

    connect(ui->pushButton,&QPushButton::clicked,this,&start_task::on_pushButton_clicked);
}

start_task::~start_task()
{
    delete ui;
    db.close();
}

void start_task::onUserLoggedIn(int userId) {
    currentUserId = userId;

}


void start_task::on_pushButton_2_clicked()
{
    emit returnToClock();
    close();
}




void start_task::on_comboBox_editTextChanged(const QString &arg1)
{

    //ui->comboBox->setEditable(true);
    ui->comboBox->setCurrentText(arg1);

}


void start_task::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->comboBox->setCurrentText(arg1);
}


void start_task::on_spinBox_valueChanged(int arg1)
{
    ui->spinBox->setValue(arg1);
}

void start_task::on_return_to_start_task(){
    ui->pushButton_2->show();
    ui->comboBox->show();
    ui->pushButton->show();
    ui->spinBox->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->lineEdit->show();
    ui->start->show();
}


//链接数据库
bool start_task::createConnection() {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("TOMATO");
    db.setUserName("root");
    db.setPassword("YourPassword");
    db.setPort(3306);

    if (!db.open()) {
        qDebug() << "Failed to connect to database:" << db.lastError().text();
        return false;
    }
    else
        qDebug()<<"already connected to database";
    return true;
}


//添加新任务标签
void start_task::on_pushButton_clicked()
{
    QString newLabel = ui->lineEdit->text();
    if (!newLabel.isEmpty()) {
        addTaskLabelIfNotExists(newLabel,currentUserId);
        ui->comboBox->setEditable(true);
        ui->comboBox->addItem(newLabel);
        ui->lineEdit->clear();
    }
}

//检查标签是否存在并添加到数据库
void start_task::addTaskLabelIfNotExists(const QString &label,int userID) {
    QSqlQuery query;
    query.prepare("SELECT label_id FROM TaskLabels WHERE label_name = :label_name AND user_id = :user_id");
    query.bindValue(":label_name", label);
    query.bindValue(":user_id", userID);

    if (!query.exec()) {
        qDebug() << "Failed to check task label:" << query.lastError().text();
        return;
    }

    if (!query.next()) {
        // 如果标签不存在，插入新的标签
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO TaskLabels (label_name, user_id) VALUES (:label_name, :user_id)");
        insertQuery.bindValue(":label_name", label);
        insertQuery.bindValue(":user_id", userID);

        if (!insertQuery.exec()) {
            qDebug() << "Failed to insert new task label:" << insertQuery.lastError().text();
        } else {
            qDebug() << "New task label inserted successfully.";
        }
    } else {
        // 标签已存在，显示提示信息
        QMessageBox::information(this, "标签已存在", "该标签已存在，请输入其他标签。");
        qDebug() << "Task label already exists for this user.";
    }
}

//开始做任务了
void start_task::on_start_clicked()
{
    if (mainclock == nullptr) {
        mainclock = std::make_unique<Mainclock>(this); // 创建新的 mainclock 对象
        mainclock->setAttribute(Qt::WA_DeleteOnClose); // 窗口关闭时自动删除
        connect(mainclock.get(), &Mainclock::returntoClock, this, &start_task::on_return_to_start_task);
    }

    int spinBoxData=ui->spinBox->value();
    QString comboBoxData=ui->comboBox->currentText();

    // 传递数据
    mainclock->setComBoxData(comboBoxData);
    mainclock->setSpinBoxData(spinBoxData);

    int tomatoCount = spinBoxData;
    //添加到数据库
    QSqlQuery query;
    query.prepare("INSERT INTO History (user_id, label_id, task_date, task_duration, tomato_count) "
                  "VALUES (:user_id, :label_id, CURRENT_DATE(), :task_duration, :tomato_count)");

    //下面的和登录的数据库有关，那里的用户信息要传到这里
    int user_id = 1;

    int label_id = 1; // 替换为实际的 label_id

    query.bindValue(":user_id", user_id);
    query.bindValue(":label_id", label_id);
    query.bindValue(":task_duration", tomatoCount*25);//一个番茄是25分钟来是不
    query.bindValue(":tomato_count", tomatoCount);

    if (!query.exec()) {
        qDebug() << "Failed to insert task data:" << query.lastError().text();
    } else {
        qDebug() << "Task data inserted successfully.";
        if (!updateTomatoCount(user_id, tomatoCount)) {
            qDebug() << "Failed to update tomato count.";
        }
    }

    // 显示新页面

    ui->pushButton_2->hide();
    ui->comboBox->hide();
    ui->pushButton->hide();
    ui->spinBox->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->lineEdit->hide();
    ui->start->hide();
    mainclock->show();


}


//更新Users库中番茄钟数据（累计）
bool start_task::updateTomatoCount(int userId, int tomatoCount) {
    QSqlQuery query;
    query.prepare("UPDATE Users SET tomato_count = tomato_count + :tomato_count WHERE user_id = :user_id");
    query.bindValue(":tomato_count", tomatoCount);
    query.bindValue(":user_id", userId);
    if (!query.exec()) {
        qDebug() << "Failed to update tomato count:" << query.lastError().text();
        return false;
    }
    return true;
}
