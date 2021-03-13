#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>
#include "shape.h"

class RenderArea final : public QWidget {
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    ~RenderArea();
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
    void setBackgroundColor(QColor color) {mBackgroundColor = color;}
    QColor getBackgroundColor() const {return mBackgroundColor;}
    void setShape(Shape *shape);
    Shape *shape() const {return mShape;}
    QPainter & getPainter() {return mPainter;}
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
signals:

private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    Shape *mShape{nullptr};
    QPainter mPainter;
};

#endif // RENDERAREA_H
