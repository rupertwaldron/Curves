#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>
#include "shape.h"

class RenderArea : public QWidget {
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    ~RenderArea();
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
//    enum Shapes { Astroid, Cicloid, HygensCicloid, HypoCicloid };
    void setBackgroundColor(QColor color) {mBackgroundColor = color;}
    QColor getBackgroundColor() const {return mBackgroundColor;}
    void setShape(Shape *shape);
    Shape *getShape() const {return mShape;}
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:

private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    Shape *mShape{nullptr};
};

#endif // RENDERAREA_H
