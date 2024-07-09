#include "usercenter.h"
#include "ui_usercenter.h"
#include "config.h"
#include<QDebug>
#include<QSqlError>
#include<QSqlQuery>
#include<QMessageBox>
#include <QHBoxLayout>
#include <QLabel>

extern int currentUserID;


usercenter::usercenter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::usercenter)
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

    connect(ui->return_2,&QPushButton::clicked,this,&usercenter::on_return_2_clicked);

    // 左侧按钮
    btnAccountInfo = new QPushButton("账户基本信息", this);
    btnPersonalAchievements = new QPushButton("个人成就", this);
    btnHistoryStatistics = new QPushButton("历史统计", this);

    // 右侧页面
    stackedWidget = new QStackedWidget(this);
    accountInfoPage = new QWidget(this);
    personalAchievementsPage = new QWidget(this);
    historyStatisticsPage = new QWidget(this);

    // 账户基本信息页面布局
    QVBoxLayout *accountInfoLayout = new QVBoxLayout(accountInfoPage);
    QSqlQuery query(db);
    query.prepare("SELECT username FROM Users WHERE id = :id");
    query.bindValue(":id", currentUserID);

    if (query.exec() && query.next()) {
        QString username = query.value(0).toString();
        accountInfoLayout->addWidget(new QLabel("账号：" + username, accountInfoPage));
    }

    query.prepare("SELECT password FROM Users WHERE id = :id");
    query.bindValue(":id", currentUserID);

    if (query.exec() && query.next()) {
        QString password = query.value(0).toString();
        accountInfoLayout->addWidget(new QLabel("密码：" + password, accountInfoPage));
    }

    query.prepare("SELECT tomato_count FROM Users WHERE id = :id");
    query.bindValue(":id", currentUserID);

    if (query.exec() && query.next()) {
        int tomatoCount = query.value(0).toInt();
        QString tomatoCountStr = QString("现有番茄数：%1").arg(tomatoCount);
        accountInfoLayout->addWidget(new QLabel(tomatoCountStr, accountInfoPage));
    }

    // 个人成就页面布局
    QScrollArea *personalAchievementsScrollArea = new QScrollArea(personalAchievementsPage);
    QWidget *achievementContent = new QWidget();
    QVBoxLayout *achievementLayout = new QVBoxLayout(achievementContent);

    struct Achievement {
        int threshold;
        QString title;
        QString description;
    };

    Achievement achievements[] = {
        {1, "小试牛刀", "完成1个番茄"},
        {5, "小有成就", "完成五个番茄"},
        {10, "坚持不懈", "完成10个番茄"},
        {15, "毅力可嘉", "完成15个番茄"},
        {20, "学无止境", "完成20个番茄"}
    };

    for (const auto& achievement : achievements) {
        QLabel *label = new QLabel(achievement.title + ": " + achievement.description, achievementContent);

        if (tomatoCount >= achievement.threshold) {
            label->setAutoFillBackground(false); // 透明背景
        } else {
            QPalette palette = label->palette();
            palette.setColor(QPalette::Window, Qt::gray);
            label->setAutoFillBackground(true);
            label->setPalette(palette); // 灰色背景
        }

        achievementLayout->addWidget(label);
    }

    achievementContent->setLayout(achievementLayout);
    personalAchievementsScrollArea->setWidget(achievementContent);
    personalAchievementsScrollArea->setWidgetResizable(true);

    QVBoxLayout *achievementMainLayout = new QVBoxLayout(personalAchievementsPage);
    achievementMainLayout->addWidget(personalAchievementsScrollArea);
    personalAchievementsPage->setLayout(achievementMainLayout);
    QSize fixedSize(300, 200);
    personalAchievementsPage->setFixedSize(fixedSize);

    // 历史统计页面布局
    historyScrollArea = new QScrollArea(historyStatisticsPage);
    QWidget *historyContent = new QWidget();
    historyLayout = new QVBoxLayout(historyContent);
    QMap<QDate, int> weeklyData;

    query.prepare("SELECT task_date, COUNT(*) as count FROM Tomatoes "
                  "WHERE task_date >= :start_date AND task_date <= :end_date "
                  "GROUP BY task_date");
    QDate endDate = QDate::currentDate();
    QDate startDate = endDate.addDays(-6); // 最近一周
    query.bindValue(":start_date", startDate.toString("yyyy-MM-dd"));
    query.bindValue(":end_date", endDate.toString("yyyy-MM-dd"));

    if (query.exec()) {
        while (query.next()) {
            QDate date = query.value("task_date").toDate();
            int count = query.value("count").toInt();
            weeklyData[date] = count;
        }
    }

    for (int i = 0; i < 7; ++i) {
        QDate date = startDate.addDays(i);
        if (!weeklyData.contains(date)) {
            weeklyData[date] = 0;
        }
    }

    // 使用Qt Charts显示柱状图
    QtCharts::QBarSet *set = new QtCharts::QBarSet("番茄钟数");
    QStringList categories;

    for (int i = 0; i < 7; ++i) {
        QDate date = startDate.addDays(i);
        *set << weeklyData[date];
        categories << date.toString("MM-dd");
    }

    QtCharts::QBarSeries *series = new QtCharts::QBarSeries();
    series->append(set);

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("最近一周番茄钟数");
    chart->setAnimationOptions(QtCharts::QChart::SeriesAnimations);

    QtCharts::QBarCategoryAxis *axisX = new QtCharts::QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
    axisY->setRange(0, *std::max_element(weeklyData.begin(), weeklyData.end()));
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    historyLayout->addWidget(chartView);
    historyContent->setLayout(historyLayout);
    historyScrollArea->setWidget(historyContent);
    historyScrollArea->setWidgetResizable(true);

    QVBoxLayout *historyMainLayout = new QVBoxLayout(historyStatisticsPage);
    historyMainLayout->addWidget(historyScrollArea);
    historyStatisticsPage->setLayout(historyMainLayout);

    // 添加页面到stackedWidget
    stackedWidget->addWidget(accountInfoPage);
    stackedWidget->addWidget(personalAchievementsPage);
    stackedWidget->addWidget(historyStatisticsPage);

    // 主布局
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    QVBoxLayout *leftLayout = new QVBoxLayout();
    leftLayout->addWidget(new QLabel("个人中心"));
    leftLayout->addWidget(btnAccountInfo);
    leftLayout->addWidget(btnPersonalAchievements);
    leftLayout->addWidget(btnHistoryStatistics);
    leftLayout->addStretch();

    mainLayout->addLayout(leftLayout);
    mainLayout->addWidget(stackedWidget);
    setLayout(mainLayout);

    // 设置信号和槽
    connect(btnAccountInfo, &QPushButton::clicked, this, &usercenter::showAccountInfo);
    connect(btnPersonalAchievements, &QPushButton::clicked, this, &usercenter::showPersonalAchievements);
    connect(btnHistoryStatistics, &QPushButton::clicked, this, &usercenter::showHistoryStatistics);
    connect(ui->return_2, &QPushButton::clicked, this, &usercenter::on_return_2_clicked);

    // 默认显示账户基本信息页面
    stackedWidget->setCurrentWidget(accountInfoPage);
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

void usercenter::showAccountInfo()
{
    stackedWidget->setCurrentWidget(accountInfoPage);
}

void usercenter::showPersonalAchievements()
{
    stackedWidget->setCurrentWidget(personalAchievementsPage);
}

void usercenter::showHistoryStatistics()
{
    stackedWidget->setCurrentWidget(historyStatisticsPage);
}
