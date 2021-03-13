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
    void drawShape(QRect & canvas, QPainter & painter)
    {
          QPoint center = canvas.center();
          float step = intervalLength / stepCount;
          for (float t = 0; t < intervalLength; t += step) {
              QPointF point = compute_shape(t);
              QPoint pixel;
              pixel.setX(point.x() * scale + center.x());
              pixel.setY(point.y() * scale + center.y());
              painter.drawPoint(pixel);
          }
    };
protected:
    QColor m_color{Qt::black};
    float intervalLength{0};
    float scale{0};
    int stepCount{0};
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
    Astroid()
    {
        m_color = Qt::red;
        intervalLength = 2 * M_PI;
        scale = 40;
        stepCount = 256;
        qInfo("Astroid()");
    }
    ~Astroid() {qInfo("~Astroid()");}
private:
    QPointF compute_shape(float t) Q_DECL_OVERRIDE
    {
        float cos_t = cos(t);
        float sin_t = sin(t);
        float x = 2 * cos_t * cos_t * cos_t;
        float y = 2 * sin_t * sin_t * sin_t;
        return QPointF(x, y);
    }
};

class Circle : public Shape
{
public:
    Circle()
    {
        m_color = Qt::magenta;
        stepCount = 256;
        scale = 40;
        intervalLength = 2 * M_PI;
        qInfo("Circle()");
    }
    ~Circle() {qInfo("~Circle()");}
private:
    QPointF compute_shape(float t) Q_DECL_OVERRIDE
    {
        float cos_t = cos(t);
        float sin_t = sin(t);
        float x = 2 * cos_t;
        float y = 2 * sin_t;
        return QPointF(x, y);
    }
};

class Cycloid : public Shape
{
public:
    Cycloid()
    {
        m_color = Qt::green;
        stepCount = 128;
        scale = 4;
        intervalLength = 6 * M_PI;
        qInfo("Cycloid()");
    }
    ~Cycloid() {qInfo("~Cycloid()");}
private:
    QPointF compute_shape(float t) Q_DECL_OVERRIDE
    {
        return QPointF(
                    1.5 * (1 * cos(t)),
                    1.5 * (t * sin(t))
                    );
    }
};

class HygensCycloid : public Shape
{
public:
    HygensCycloid()
    {
        m_color = Qt::blue;
        stepCount = 256;
        scale = 4;
        intervalLength = 4 * M_PI;
        qInfo("HygensCycloid()");
    }
    ~HygensCycloid() {qInfo("~HygensCycloid()");}
private:
    QPointF compute_shape(float t) Q_DECL_OVERRIDE
    {
        return QPointF(
                    4 * (3 * cos(t) - cos(3 * t)),
                    4 * (3 * sin(t) - sin(3 * t))
                    );
    }
};

class HypoCycloid : public Shape
{
public:
    HypoCycloid()
    {
        m_color = Qt::black;
        qInfo("HypoCycloid()");
    }
    ~HypoCycloid() {qInfo("~HypoCycloid()");}
private:
    QPointF compute_shape(float t) Q_DECL_OVERRIDE {}
};

#endif // SHAPE_H

