#ifndef EASYCLOCK_H
#define EASYCLOCK_H

#include <QWidget>

namespace Ui {
class easyclock;
}

class easyclock : public QWidget
{
    Q_OBJECT

public:
    explicit easyclock(QWidget *parent = nullptr);
    ~easyclock();

private:
    Ui::easyclock *ui;
};

#endif // EASYCLOCK_H
