#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>
#include <QPainter>
#include "renderarea.h"

class Shape
{
public:
    Shape() {qInfo("Shape()");}
    virtual ~Shape() {qInfo("~Shape()");}
    QColor getShapeColor() {return m_color;}
    virtual void drawShape(QRect & canvas, QPainter & painter) {
        painter.drawLine(canvas.bottomRight(), canvas.topLeft());
    }
protected:
    QColor m_color;
    virtual QPointF compute_shape(float t) = 0;
private:
    Shape(const Shape & rhs) {
        qInfo("Shape(const Shape &)");
        this->m_color = rhs.m_color;
    }
    Shape & operator= (const Shape & rhs) {
        qInfo("operator=(const Shape &)");
        this->m_color = rhs.m_color;
        return *this;
    }
    Shape & operator=(const Shape && rhs) {
        qInfo("operator=(const Shape &&)");
        this->m_color = rhs.m_color;
        return *this;
    }
};

class Astroid : public Shape
{
public:
    Astroid() {
        m_color = Qt::red;
        qInfo("Astroid()");
    }
    ~Astroid() {qInfo("~Astroid()");}
    void drawShape(QRect & canvas, QPainter & painter) Q_DECL_OVERRIDE {
        QPoint center = canvas.center();
        int stepCount = 256;
        float scale = 40;
        float intervalLength = 2 * M_PI;
        float step = intervalLength / stepCount;
        for (float t = 0; t < intervalLength; t += step) {
            QPointF point = compute_shape(t);
            QPoint pixel;
            pixel.setX(point.x() * scale + center.x());
            pixel.setY(point.y() * scale + center.y());
            painter.drawPoint(pixel);
        }
    }
private:
    QPointF compute_shape(float t) Q_DECL_OVERRIDE {
        float cos_t = cos(t);
        float sin_t = sin(t);
        float x = 2 * cos_t * cos_t * cos_t;
        float y = 2 * sin_t * sin_t * sin_t;
        return QPointF(x, y);
    }
};

class Cycloid : public Shape
{
public:
    Cycloid() {
        m_color = Qt::green;
        qInfo("Cycloid()");
    }
    ~Cycloid() {qInfo("~Cycloid()");}
private:
    QPointF compute_shape(float t) {}
};

class HygensCycloid : public Shape
{
public:
    HygensCycloid() {
        m_color = Qt::cyan;
        qInfo("HygensCycloid()");
    }
    ~HygensCycloid() {qInfo("~HygensCycloid()");}
private:
    QPointF compute_shape(float t) {}
};

class HypoCycloid : public Shape
{
public:
    HypoCycloid() {
        m_color = Qt::yellow;
        qInfo("HypoCycloid()");
    }
    ~HypoCycloid() {qInfo("~HypoCycloid()");}
private:
    QPointF compute_shape(float t) {}
};







#endif // SHAPE_H

