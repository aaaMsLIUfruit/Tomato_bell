#include "usercenter.h"
#include "ui_usercenter.h"
#include "config.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QDate>
#include <QScrollArea>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

extern int currentUserID;

usercenter::usercenter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::usercenter)
    , stackedWidget(new QStackedWidget(this))
    , accountInfoPage(new QWidget(this))
    , personalAchievementsPage(new QWidget(this))
    , historyStatisticsPage(new QWidget(this))
{
    ui->setupUi(this);

    // 连接数据库
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("testM");
    db.setUserName("root");
    db.setPassword("123456");
    db.setPort(3306);

    if (!db.open()) {
        qDebug() << "Failed to connect to database:" << db.lastError().text();
    } else {
        qDebug() << "Connected to database";
    }

    // 设置窗口属性
    setWindowTitle("个人中心");
    setWindowIcon(QIcon(ICON));

    // 左侧按钮
    QPushButton *btnAccountInfo = new QPushButton("账户基本信息", this);
    QPushButton *btnPersonalAchievements = new QPushButton("个人成就", this);
    QPushButton *btnHistoryStatistics = new QPushButton("历史统计", this);

    // 右侧页面
    stackedWidget = new QStackedWidget(this);
    accountInfoPage = new QWidget(this);
    personalAchievementsPage = new QWidget(this);
    historyStatisticsPage = new QWidget(this);

    // 账户基本信息页面布局
    QVBoxLayout *accountInfoLayout = new QVBoxLayout(accountInfoPage);
    QSqlQuery query(db);
    query.prepare("SELECT username, password, tomato_count FROM Users WHERE user_id = :userID");
    query.bindValue(":userID", currentUserID);
    if (query.exec()) {
        if (query.next()) {
            QString username = query.value(0).toString();
            QString password = query.value(1).toString();
            int tomatoCount = query.value(2).toInt();

            accountInfoLayout->addWidget(new QLabel("账号：" + username, accountInfoPage));
            accountInfoLayout->addWidget(new QLabel("密码：" + password, accountInfoPage));
            accountInfoLayout->addWidget(new QLabel("现有番茄数：" + QString::number(tomatoCount), accountInfoPage));
        }
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
        {1, "小试牛刀", "获得1个番茄"},
        {5, "小有成就", "获得5个番茄      解锁背景音乐 巴黎咖啡馆"},
        {10, "坚持不懈", "获得10个番茄    解锁背景音乐 沙滩海浪"},
        {15, "毅力可嘉", "获得15个番茄    解锁背景皮肤 雨中少女"},
        {20, "学无止境", "获得20个番茄"},
        {100,"番茄首富","获得100个番茄"}
    };

    int tomatoCount = 0;
    query.prepare("SELECT username, password, tomato_count FROM Users WHERE user_id = :userID");
    query.bindValue(":userID", currentUserID);
    if (query.exec()) {
        if (query.next()) {
            tomatoCount = query.value(2).toInt();
        }
    }

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
    QSize fixedSize(600, 400);
    personalAchievementsPage->setFixedSize(fixedSize);

    // 历史统计页面布局
    QScrollArea *historyScrollArea = new QScrollArea(historyStatisticsPage);
    QWidget *historyContent = new QWidget();
    QVBoxLayout *historyLayout = new QVBoxLayout(historyContent);
    QMap<QDate, int> weeklyData;

    query.prepare("SELECT task_date, COUNT(*) as count FROM History "
                  "WHERE task_date >= :start_date AND task_date <= :end_date "
                  "GROUP BY task_date");
    QDate endDate = QDate::currentDate();
    QDate startDate = endDate.addDays(-6); // 最近一周
    query.bindValue(":start_date", startDate.toString("yyyy-MM-dd"));
    query.bindValue(":end_date", endDate.toString("yyyy-MM-dd"));

    if (query.exec()) {
        while (query.next()) {
            QDate date = query.value(0).toDate();
            int count = query.value(1).toInt();
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
    QBarSet *set = new QBarSet("番茄钟数");
    QStringList categories;

    for (int i = 0; i < 7; ++i) {
        QDate date = startDate.addDays(i);
        *set << weeklyData[date];
        categories << date.toString("MM-dd");
    }

    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("最近一周番茄钟数");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, *std::max_element(weeklyData.begin(), weeklyData.end()) + 1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
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
