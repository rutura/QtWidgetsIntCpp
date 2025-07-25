#include "widget.h"
#include "./ui_widget.h"
#include <QPainter>
#include <QPainterPath>

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
    Q_UNUSED(event);
    QPainter painter{this};

    //Add a background color
    painter.fillRect(rect(), Qt::lightGray);

    QPainterPath path;
    path.addRect(100, 100, 100, 100);
    path.moveTo(150,150);
    path.lineTo(150,50);
    path.arcTo(50,50,200,200,90,90);
    path.lineTo(150,150);

    painter.setBrush(Qt::blue);
    painter.drawPath(path);


    // Create second path with two circles connected by lines
    QPainterPath path2;
    path2.addEllipse(100, 220, 100, 100);
    path2.addEllipse(400, 220, 100, 100);

    // Draw the upper connecting line
    path2.moveTo(150, 220);
    path2.lineTo(450, 220);

    // Draw the lower connecting line
    path2.moveTo(150, 320);
    path2.lineTo(450, 320);

    painter.drawPath(path2);

    //Translate and move the shape to a new location
    path2.translate(150, 150);
    painter.drawPath(path2);




















}
