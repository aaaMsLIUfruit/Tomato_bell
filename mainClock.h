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
class MyLabel;


namespace Ui {
class mainClock;
}

class mainClock : public QWidget
{
    Q_OBJECT

public:
    explicit mainClock(QWidget *parent = nullptr);
    ~mainClock();

    void setSpinBoxData(int n);
    void setComBoxData(QString comboBoxData);

signals:
    void returntoClockyes();
    void returntoClockno();

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
    Ui::mainClock *ui;
    QVBoxLayout *mainLayout,*topLayout,*bottomLayout;
    QWidget *topWidget ,*bottomWidget;
    QPushButton *pauseButton;
    QString comboBox;
    MyLabel *timerLabel;
    QTimer *mainTimer;
    QTimer *pauseTimer;
    int remainingTime;
    int remainingPauseTime;
    int completedCycles;
    bool isPaused;
    int rest; // 0: 暂停中，1: 休息中
    int num; // 初始值设为1
    QMessageBox *pauseMessageBox;

    void initWindow();
};

#endif // MAINCLOCK_H
