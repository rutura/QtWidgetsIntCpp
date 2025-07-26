#ifndef PAINTCANVAS_H
#define PAINTCANVAS_H

#include <QWidget>

class PaintCanvas : public QWidget
{
    Q_OBJECT
public:
    enum class ToolType {Pen, Rect, Ellipse, Eraser};

    explicit PaintCanvas(QWidget *parent = nullptr);

    ToolType getTool() const;
    void setTool(ToolType newTool);

    bool getFill() const;
    void setFill(bool newFill);

    int getPenWidth() const;
    void setPenWidth(int newPenWidth);

    QColor getFillColor() const;
    void setFillColor(const QColor &newFillColor);

    QColor getPenColor() const;
    void setPenColor(const QColor &newPenColor);


private:
    void drawLineTo(const QPoint &endPoint);
    void drawRectTo(const QPoint &endPoint, bool ellipse = false);
    void eraseUnder(const QPoint &topLeft);
    void resizeImage(QImage *image, const QSize &newSize);


signals:
private:
    ToolType tool{ToolType::Pen};
    bool fill{false};
    bool drawing{false};
    int penWidth{3};
    QColor fillColor{Qt::red};
    QColor penColor{Qt::green};
    QPoint lastPoint{};
    QRectF lastRect{};
    QRectF lastEraserRect{};
    QImage image{};

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
};

#endif // PAINTCANVAS_H
