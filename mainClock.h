#ifndef MAINCLOCK_H
#define MAINCLOCK_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QMessageBox>
#include <QFontDatabase>
#include "config.h"

namespace Ui {
class Mainclock;
}

class Mainclock : public QWidget
{
    Q_OBJECT

public:
    explicit Mainclock(QWidget *parent = nullptr);
    ~Mainclock();

    void setSpinBoxData(int n);
    void setComBoxData(QString comboBoxData);

signals:
    void returntoClock();

private slots:
    void togglePausePlay();
    void updateTimer();
    void updatePauseTimer();
    void resumeMainTimer();
    void showPauseMessageBox();
    void updatePauseMessageBoxText();
    void showFailureMessageBox();
    void onContinueClicked();
    void onRestartClicked();
    void onBackClicked();

private:
    Ui::Mainclock *ui;
    QVBoxLayout *layout;
    QPushButton *pauseButton;
    QString comboBox;
    QLabel *timerLabel;
    QTimer *mainTimer;
    QTimer *pauseTimer;
    int remainingTime;
    int remainingPauseTime;
    bool isPaused;
    int rest; // 0: 暂停中，1: 休息中
    int num; // 初始值设为1
    QMessageBox *pauseMessageBox;

    void initWindow();
};

#endif // MAINCLOCK_H
