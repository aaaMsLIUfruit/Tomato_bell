#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
class Sign_in; // 前向声明
class Register; // 前向声明
class Mainclock;// 前向声明

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initWindow();//初始化窗口


private:
    Ui::MainWindow *ui;
    std::unique_ptr<Sign_in> sign_in; // 使用智能指针
    std::unique_ptr<Register> register_; // 使用智能指针


private slots:
    void on_sign_in_clicked();
    void on_register_clicked();
    void on_return_to_main();
};
#endif // MAINWINDOW_H
