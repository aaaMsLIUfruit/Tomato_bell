#ifndef MAINCLOCK_H
#define MAINCLOCK_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QMessageBox>
#include <QFontDatabase>
#include <QMediaPlayer>
#include <QUrl>

namespace Ui {
class mainClock;
}

class Mainclock : public QWidget
{
    Q_OBJECT

public:
    explicit Mainclock(QWidget *parent = nullptr);
    ~Mainclock();

    void setSpinBoxData(int n);
    void setComBoxData(QString comboBoxData);
    bool isMusic2;
    bool isMusic3;

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
    void playMusic();
    void selectMusic(QString choice);
private:
    Ui::mainClock *ui;
    QVBoxLayout *layout;
    QPushButton *pauseButton;
    QString comboBox;
    QLabel *timerLabel;
    QTimer *mainTimer;
    QTimer *pauseTimer;
    int remainingTime;
    int remainingPauseTime;
    int completedCycles;
    bool isPaused;
    int rest; // 0: 暂停中，1: 休息中
    int num; // 初始值设为1
    int Music;
    QMessageBox *pauseMessageBox;
    QMediaPlayer musicPlayer;

    void initWindow();
};

#endif // MAINCLOCK_H
