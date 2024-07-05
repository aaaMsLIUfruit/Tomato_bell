#ifndef MAINCLOCK_H
#define MAINCLOCK_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QMessageBox>
#include <QFontDatabase>

namespace Ui {
class Mainclock;
}

class Mainclock : public QWidget
{
    Q_OBJECT

public:
    explicit Mainclock(QWidget *parent = nullptr);
    ~Mainclock();

    void initWindow();

private slots:
    void togglePausePlay(); // 暂停/播放按钮槽函数
    void updateTimer(); // 更新主计时器槽函数
    void updatePauseTimer(); // 更新暂停计时器槽函数
    void resumeMainTimer(); // 恢复主计时器槽函数
    void onContinueClicked(); // 继续按钮点击槽函数
    void onRestartClicked(); // 重新开始按钮点击槽函数
    void onBackClicked(); // 回到上一个界面按钮点击槽函数


private:
    Ui::Mainclock *ui;
    QVBoxLayout *layout;
    QPushButton *pauseButton;
    QLabel *timerLabel;
    QTimer *mainTimer;
    QTimer *pauseTimer;
    int remainingTime;
    int remainingPauseTime;
    bool isPaused;

    QMessageBox *pauseMessageBox; // 暂停时的消息框
    void showPauseMessageBox(); // 显示暂停消息框
    void showFailureMessageBox(); // 显示失败消息框
};

#endif // MAINCLOCK_H
