#ifndef START_TASK_H
#define START_TASK_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include "Clock.h"
#include "mainclock.h"


namespace Ui {
class start_task;
}

class start_task : public QWidget
{
    Q_OBJECT

public:
    explicit start_task(QWidget *parent = nullptr);
    ~start_task();

    mainclock* Mainclock;

signals:
    void returnToClock();
   // void on_comboBox_textActivated(const QString &arg1);

private slots:
    void on_pushButton_2_clicked();

    void on_start_clicked();

    void on_comboBox_editTextChanged(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_spinBox_valueChanged(int arg1);


    void on_pushButton_clicked();

private:
    Ui::start_task *ui;


};

#endif // START_TASK_H
