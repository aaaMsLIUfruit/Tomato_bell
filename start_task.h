#ifndef START_TASK_H
#define START_TASK_H

#include <QWidget>
#include <QComboBox>
#include<QMessageBox>
#include <QSpinBox>
#include "Clock.h"
#include<QSqlDatabase>
#include "mainclock.h"
#include<QSqlError>


namespace Ui {
class start_task;
}

class start_task : public QWidget
{
    Q_OBJECT

public:
    explicit start_task(QWidget *parent = nullptr);
    ~start_task();

    std::unique_ptr<Mainclock> mainclock;

signals:
    void returnToClock();
    void on_comboBox_textActivated(const QString &arg1);
public slots:

    void onUserLoggedIn(int userId);
private slots:


    void on_pushButton_2_clicked();
    void on_start_clicked();
    void on_comboBox_editTextChanged(const QString &arg1);
    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_spinBox_valueChanged(int arg1);
    void on_pushButton_clicked();
    void on_return_to_start_task();

private:
    Ui::start_task *ui;
    QSqlDatabase db;
    int currentUserId;
    bool createConnection();//connect to the database
    bool updateTomatoCount(int userId, int tomatoCount);
    void addTaskLabelIfNotExists(const QString &label,int userID);


};

#endif // START_TASK_H
