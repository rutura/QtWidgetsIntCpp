#include "widget.h"
#include "./ui_widget.h"
#include "indicator.h"
#include "watertank.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Connect water tank signals to indicator slots
    /*
    connect(tank, &WaterTank::normal, indicator, &Indicator::activateNormal);
    connect(tank, &WaterTank::warning, indicator, &Indicator::activateWarning);
    connect(tank, &WaterTank::danger, indicator, &Indicator::activateDanger);
    */
}

Widget::~Widget()
{
    delete ui;
}
