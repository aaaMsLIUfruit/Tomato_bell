#include "usercenter.h"
#include "ui_usercenter.h"
#include "config.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>

usercenter::usercenter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::usercenter)
{
    ui->setupUi(this);

    setWindowTitle("个人中心");
    setWindowIcon(QIcon(ICON));

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
    accountInfoLayout->addWidget(new QLabel("账号：", accountInfoPage));
    accountInfoLayout->addWidget(new QLabel("密码：", accountInfoPage));
    accountInfoLayout->addWidget(new QLabel("现有番茄数：", accountInfoPage));

    QSize fixedSize(300, 200);
    // 个人成就页面布局
    personalAchievementsScrollArea = new QScrollArea(personalAchievementsPage);
    QWidget *achievementContent = new QWidget();
    achievementLayout = new QVBoxLayout(achievementContent);

    // 示例数据
    for (int i = 0; i < 11; ++i) {
        achievementLayout->addWidget(new QLabel("成就 " + QString::number(i + 1) + ": 完成情况", achievementContent));
    }

    achievementContent->setLayout(achievementLayout);
    personalAchievementsScrollArea->setWidget(achievementContent);
    personalAchievementsScrollArea->setWidgetResizable(true);

    QVBoxLayout *achievementMainLayout = new QVBoxLayout(personalAchievementsPage);
    achievementMainLayout->addWidget(personalAchievementsScrollArea);
    personalAchievementsPage->setLayout(achievementMainLayout);
    personalAchievementsPage->setFixedSize(fixedSize);

    // 历史统计页面布局
    historyScrollArea = new QScrollArea(historyStatisticsPage);
    QWidget *historyContent = new QWidget();
    historyLayout = new QVBoxLayout(historyContent);

    // 示例数据
    for (int i = 0; i < 7; ++i) {
        historyLayout->addWidget(new QLabel("任务 " + QString::number(i + 1) + ": 完成情况", historyContent));
    }

    historyContent->setLayout(historyLayout);
    historyScrollArea->setWidget(historyContent);
    historyScrollArea->setWidgetResizable(true);

    QVBoxLayout *historyMainLayout = new QVBoxLayout(historyStatisticsPage);
    historyMainLayout->addWidget(historyScrollArea);
    historyStatisticsPage->setLayout(historyMainLayout);
    historyStatisticsPage->setFixedSize(fixedSize);

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
