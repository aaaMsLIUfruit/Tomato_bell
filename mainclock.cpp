#include "mainclock.h"
#include "ui_mainclock.h"
#include "config.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QMoveEvent>
mainclock::mainclock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainclock)
{
    ui->setupUi(this);
}

mainclock::~mainclock()
{
    delete ui;
}

void mainclock::setComboBoxData(QString comboBoxData)
{

}
void mainclock::setSpinBoxData(int spinBoxData){

}
