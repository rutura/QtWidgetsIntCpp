#include "widget.h"
#include "./ui_widget.h"
#include <QPainter>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    qDebug() << "Logical coordinates:" << painter.window();
    qDebug() << "Physical coordinates:" << painter.viewport();

    //Draw a white background and set the brush back to the defaults
    painter.fillRect(rect(), Qt::white);
    painter.setBrush(Qt::NoBrush);


    QPen pen(Qt::red);
    pen.setWidth(3);
    painter.setPen(pen);


    //This rectangle is drawn with the defaults: logical and physical coordinates are the same
    painter.drawRect(100,100,50,50);


    //Change the logical coordinates to go from (-100,-100) to (100, 100)
    painter.setWindow(-100,-100, 200, 200); // Change logical
    painter.setViewport(0,0,width(),height()); // Change physical coords


    pen.setColor(Qt::green);
    painter.setPen(pen);
    painter.drawRect(100,100,50,50);
















}
