#include "easyclock.h"
#include "ui_easyclock.h"

easyclock::easyclock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::easyclock)
{
    ui->setupUi(this);
}

easyclock::~easyclock()
{
    delete ui;
}
