#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include<QPainter>
#include"mypushbutton.h"
class mypushbutton;
class start_task;
class usercenter;

namespace Ui{
class Clock;
}

class Clock : public QWidget
{
    Q_OBJECT
public:
    explicit Clock(QWidget *parent = nullptr);
    ~Clock();

    void paintEvent(QPaintEvent *event);

private:
     Ui::Clock *ui;
     //std::unique_ptr<mypushbutton> *starttask;
     //std::unique_ptr<mypushbutton> *personalcenter;
     mypushbutton *starttask;
     mypushbutton *personalcenter;
     std::unique_ptr<start_task> Start_task;// 使用智能指针
     std::unique_ptr<usercenter> Usercenter;


signals:

 private slots:

     void on_start_task_clicked();
     void on_return_to_Clock();
     void on_personal_center_clicked();
};

#endif // CLOCK_H
