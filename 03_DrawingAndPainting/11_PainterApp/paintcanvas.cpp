#include "paintcanvas.h"
#include <QPainter>
#include <QMouseEvent>

PaintCanvas::PaintCanvas(QWidget *parent)
    : QWidget{parent}
{}

PaintCanvas::ToolType PaintCanvas::getTool() const
{
    return tool;
}

void PaintCanvas::setTool(ToolType newTool)
{
    tool = newTool;
}

bool PaintCanvas::getFill() const
{
    return fill;
}

void PaintCanvas::setFill(bool newFill)
{
    fill = newFill;
}

int PaintCanvas::getPenWidth() const
{
    return penWidth;
}

void PaintCanvas::setPenWidth(int newPenWidth)
{
    penWidth = newPenWidth;
}

QColor PaintCanvas::getFillColor() const
{
    return fillColor;
}

void PaintCanvas::setFillColor(const QColor &newFillColor)
{
    fillColor = newFillColor;
}

QColor PaintCanvas::getPenColor() const
{
    return penColor;
}

void PaintCanvas::setPenColor(const QColor &newPenColor)
{
    penColor = newPenColor;
}

void PaintCanvas::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(penColor, penWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawLine(lastPoint,endPoint);

    int adjustment = penWidth + 2;

    update(QRect(lastPoint,endPoint).normalized().adjusted(-adjustment, -adjustment, +adjustment, +adjustment));


    lastPoint = endPoint;

}

void PaintCanvas::drawRectTo(const QPoint &endPoint, bool ellipse)
{

}

void PaintCanvas::eraseUnder(const QPoint &topLeft)
{

}

void PaintCanvas::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;

}


void PaintCanvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        drawing = true;
    }
}

void PaintCanvas::mouseReleaseEvent(QMouseEvent *event)
{
        if (event->button() == Qt::LeftButton && drawing) {
            drawing = false;
            if (tool == ToolType::Pen) {
                drawLineTo(event->pos());
            }
        }
}

void PaintCanvas::mouseMoveEvent(QMouseEvent *event)
{
        if ((event->buttons() & Qt::LeftButton) && drawing) {
            drawLineTo(event->pos());
        }
}

void PaintCanvas::paintEvent(QPaintEvent *event)
{
    QPainter painter{this};
    QRect rectToDraw = event->rect();
    painter.drawImage(rectToDraw, image);
}

void PaintCanvas::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}






