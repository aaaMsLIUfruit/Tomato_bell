#ifndef USERCENTER_H
#define USERCENTER_H

#include <QWidget>
#include "Clock.h"
#include <QtCharts/QChartView>
#include<QLabel>
#include<QSqlDatabase>

namespace Ui {
class usercenter;
}

class usercenter : public QWidget
{
    Q_OBJECT

public:
    explicit usercenter(QWidget *parent = nullptr);
    ~usercenter();


signals:
    void returnToClock();
public slots:
  void onUserLoggedIn(int userId);

private slots:

    //void on_HistoryComboBox_currentIndexChanged(const QString &text);
    void on_return_2_clicked();

private:
    Ui::usercenter *ui;
    int currentUserId;
     void displayUsername();
    // void displayHistory(const QString &period);
    QString username; // 保存用户名
    QSqlDatabase db;
    //QChartView *chartView; // 添加 chartView 变量
};

#endif // USERCENTER_H
