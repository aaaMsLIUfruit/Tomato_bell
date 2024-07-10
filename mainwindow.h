#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

class start_task;
class Sign_in;
class Register;
class Mainclock;

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

    void initWindow();
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    std::unique_ptr<Sign_in> sign_in;
    std::unique_ptr<Register> register_;


private slots:
    void on_sign_in_clicked();
    void on_register_clicked();
    void on_return_to_main();

    //void on_visitor_clicked();
};
#endif // MAINWINDOW_H
