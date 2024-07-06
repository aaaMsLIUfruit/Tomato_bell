#ifndef MAINCLOCK_H
#define MAINCLOCK_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
class start_task;
namespace Ui {
class mainclock;
}

class mainclock : public QWidget
{
    Q_OBJECT

public:
    explicit mainclock(QWidget *parent = nullptr);
    ~mainclock();


    void setComboBoxData(QString comboBoxData);
    void setSpinBoxData(int spinBoxData);

private:
    Ui::mainclock *ui;
};

#endif // MAINCLOCK_H
