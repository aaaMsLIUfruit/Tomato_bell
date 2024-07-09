#ifndef USERCENTER_H
#define USERCENTER_H
#include <QWidget>
#include "Clock.h"
#include <QtCharts/QChartView>
#include<QLabel>
#include<QSqlDatabase>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QScrollArea>

QT_BEGIN_NAMESPACE
namespace Ui { class usercenter; }
QT_END_NAMESPACE

class usercenter : public QWidget
{
    Q_OBJECT

public:
    explicit usercenter(QWidget *parent = nullptr);
    ~usercenter();

signals:
    void returnToClock();


private slots:
    void on_return_2_clicked();
    void showAccountInfo();
    void showPersonalAchievements();
    void showHistoryStatistics();

private:
    Ui::usercenter *ui;
    void displayUsername();
    QString username; // 保存用户名
    QSqlDatabase db;
    QPushButton *btnAccountInfo;
    QPushButton *btnPersonalAchievements;
    QPushButton *btnHistoryStatistics;
    QStackedWidget *stackedWidget;
    QWidget *accountInfoPage;
    QWidget *personalAchievementsPage;
    QWidget *historyStatisticsPage;
    QScrollArea *historyScrollArea;
    QScrollArea *personalAchievementsScrollArea;
    QVBoxLayout *historyLayout;
    QVBoxLayout *achievementLayout;
};

#endif // USERCENTER_H
