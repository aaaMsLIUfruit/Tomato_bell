#include "mainclock.h"
#include "ui_Mainclock.h"
#include "config.h"

Mainclock::Mainclock(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Mainclock),
    layout(new QVBoxLayout(this)),
    pauseButton(new QPushButton(this)),
    timerLabel(new QLabel(this)),
    mainTimer(new QTimer(this)),
    pauseTimer(new QTimer(this)),
    remainingTime(1500), // 初始时间为25分钟（1500秒）
    remainingPauseTime(300), // 暂停时间为5分钟（300秒）
    isPaused(false),
    pauseMessageBox(nullptr)
{
    ui->setupUi(this);

    setWindowTitle("番茄钟");
    setWindowIcon(QIcon(ICON));

    int fontId = QFontDatabase::addApplicationFont(ZITI);
    QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont myFont(fontFamily);
    myFont.setBold(true);

    initWindow(myFont); // 初始化窗口布局
    togglePausePlay(); // 初始状态为暂停状态，点击后开始计时
}

Mainclock::~Mainclock() {
    delete ui;
}

void Mainclock::initWindow(const QFont &font) {
    // 设置布局管理器
    setLayout(layout);

    // 初始化并配置按钮
    pauseButton->setText("▶"); // 初始状态为播放符号
    pauseButton->setFixedSize(80, 80);
    pauseButton->setStyleSheet("font-size: 30px; color: #800000; background-color: #FFFACD; border-radius: 40px;"); // 字符颜色为酒红色，背景色为米黄色，圆形按钮
    pauseButton->setFont(font); // 应用自定义字体
    layout->addWidget(pauseButton, 0, Qt::AlignCenter);

    // 初始化并配置标签
    timerLabel->setText("25:00"); // 初始化标签为 25 分钟
    timerLabel->setStyleSheet("font-size: 36px; color: #800000;");
    timerLabel->setAlignment(Qt::AlignCenter); // 居中对齐
    timerLabel->setFont(font); // 应用自定义字体
    layout->addWidget(timerLabel);

    // 连接按钮的点击信号和槽函数
    connect(pauseButton, &QPushButton::clicked, this, &Mainclock::togglePausePlay);

    // 连接计时器的超时信号和槽函数
    connect(mainTimer, &QTimer::timeout, this, &Mainclock::updateTimer);
    connect(pauseTimer, &QTimer::timeout, this, &Mainclock::updatePauseTimer);
}

void Mainclock::togglePausePlay() {
    if (!isPaused) {
        // 开始或继续计时
        pauseButton->setText("||"); // 切换到暂停符号
        mainTimer->start(1000); // 每秒更新一次
        pauseTimer->stop(); //暂停暂停计时
    } else {
        // 暂停计时器
        mainTimer->stop();
        pauseButton->setText("▶"); // 切换到播放符号

        // 显示暂停消息框
        showPauseMessageBox();

        // 启动暂停计时器
        pauseTimer->start(1000); // 每秒更新一次
        update();
    }
    isPaused = !isPaused; // 切换状态变量
}

void Mainclock::updateTimer() {
    if (remainingTime > 0) {
        remainingTime--;

        int minutes = remainingTime / 60;
        int seconds = remainingTime % 60;
        timerLabel->setText(QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
    } else {
        // 计时结束
        mainTimer->stop();
        isPaused = true;
        pauseButton->setText("▶"); // 切换到播放符号

        // 进入5分钟休息
        remainingPauseTime = 300;
        showPauseMessageBox();
    }
}

void Mainclock::updatePauseTimer() {
    if (remainingPauseTime > 0) {
        remainingPauseTime--;

        int minutes = remainingPauseTime / 60;
        int seconds = remainingPauseTime % 60;

        // 更新暂停消息框的文本
        if (pauseMessageBox) {
            pauseMessageBox->setText(QString("倒计时: %1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
        }

        if (remainingPauseTime == 0) {
            // 暂停时间结束
            pauseTimer->stop();

            // 关闭暂停消息框并显示失败消息框
            if (pauseMessageBox) {
                pauseMessageBox->close();
                delete pauseMessageBox;
                pauseMessageBox = nullptr;
            }

            showFailureMessageBox();
        }
    }
}

void Mainclock::resumeMainTimer() {
    mainTimer->start(1000); // 恢复主计时器
    isPaused = false;
    pauseButton->setText("||"); // 切换到暂停符号
}

void Mainclock::showPauseMessageBox() {
    if (!pauseMessageBox) {
        pauseMessageBox = new QMessageBox(this);
        pauseMessageBox->setFixedSize(2400, 2400);
        pauseMessageBox->setWindowTitle("暂停中");
        pauseMessageBox->setText(QString("倒计时: %1:%02d").arg(remainingPauseTime / 60).arg(remainingPauseTime % 60));

        // 设置自定义按钮
        QPushButton *continueButton = new QPushButton("继续", pauseMessageBox);
        pauseMessageBox->addButton(continueButton, QMessageBox::AcceptRole);


        connect(continueButton, &QPushButton::clicked, this, &Mainclock::onContinueClicked);

        pauseMessageBox->exec(); // 显示消息框，阻塞用户界面直到关闭
    }
}

void Mainclock::showFailureMessageBox() {
    QMessageBox *failureMessageBox = new QMessageBox(this);
    failureMessageBox->setFixedSize(2400, 2400);
    failureMessageBox->setWindowTitle("失败");
    failureMessageBox->setText("暂停时间结束，请选择操作");

    QPushButton *restartButton = new QPushButton("重新开始", failureMessageBox);
    failureMessageBox->addButton(restartButton, QMessageBox::AcceptRole);

    QPushButton *backButton = new QPushButton("回到上一个界面", failureMessageBox);
    failureMessageBox->addButton(backButton, QMessageBox::RejectRole);

    failureMessageBox->setStandardButtons(QMessageBox::NoButton);
    // 禁用右上角关闭按钮
    failureMessageBox->setWindowFlags(failureMessageBox->windowFlags() & ~Qt::WindowCloseButtonHint);

    connect(restartButton, &QPushButton::clicked, this, &Mainclock::onRestartClicked);
    connect(backButton, &QPushButton::clicked, this, &Mainclock::onBackClicked);

    failureMessageBox->exec(); // 显示消息框，阻塞用户界面直到关闭
}

void Mainclock::onContinueClicked() {
    if (pauseMessageBox) {
        pauseMessageBox->close();
        delete pauseMessageBox;
        pauseMessageBox = nullptr;
    }
    resumeMainTimer();
}

void Mainclock::onRestartClicked() {
    remainingTime = 1500; // 重置时间为25分钟
    timerLabel->setText("25:00");
    isPaused = true;
    togglePausePlay(); // 开始新的计时
}

void Mainclock::onBackClicked() {
    // 执行回到上一个界面的操作
    // TODO: 实现回到上一个界面的具体逻辑
}
