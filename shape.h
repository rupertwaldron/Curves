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
          float step = mIntervalLength / mStepCount;
          QPoint previousPixel = calculatePoint(0, canvas);
          for (float t = step; t < mIntervalLength; t += step) {
              QPoint pixel = calculatePoint(t, canvas);
              painter.drawLine(previousPixel, pixel);
              previousPixel = pixel;
          }
    };
    void setScale(float scale) {mScale = scale;}
    float scale() {return mScale;}
protected:
    QColor m_color{Qt::black};
    float mIntervalLength{0};
    float mScale{0};
    int mStepCount{0};
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
    inline QPoint calculatePoint(float t, QRect &canvas)
    {
        QPoint center = canvas.center();
        QPointF point = compute_shape(t);
        return QPoint (
                    point.x() * mScale + center.x(),
                    point.y() * mScale + center.y()
                    );
  }
};

class Line : public Shape
{
public:
    Line()
    {
        mIntervalLength = 1;
        mScale = 50;
        mStepCount = 128;
        qInfo("Line()");
    }
    ~Line() {qInfo("~Line()");}
private:
    QPointF compute_shape(float t) Q_DECL_OVERRIDE
    {
        return QPointF(1 - t, 1 - t);
    }
};

class Astroid : public Shape
{
public:
    Astroid()
    {
        mIntervalLength = 2 * M_PI;
        mScale = 40;
        mStepCount = 256;
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
        mStepCount = 256;
        mScale = 40;
        mIntervalLength = 2 * M_PI;
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
        mStepCount = 128;
        mScale = 4;
        mIntervalLength = 6 * M_PI;
        qInfo("Cycloid()");
    }
    ~Cycloid() {qInfo("~Cycloid()");}
private:
    QPointF compute_shape(float t) Q_DECL_OVERRIDE
    {
        return QPointF(
                    1.5 * (1 - cos(t)),
                    1.5 * (t - sin(t))
                    );
    }
};

class HygensCycloid : public Shape
{
public:
    HygensCycloid()
    {
        mStepCount = 256;
        mScale = 4;
        mIntervalLength = 4 * M_PI;
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
        mStepCount = 256;
        mScale = 15;
        mIntervalLength = 2 * M_PI;
        qInfo("HypoCycloid()");
    }
    ~HypoCycloid() {qInfo("~HypoCycloid()");}
private:
    QPointF compute_shape(float t) Q_DECL_OVERRIDE {
        return QPointF(
                   1.5 * (2 * cos(t) + cos(2 * t)),
                   1.5 * (2 * sin(t) - sin(2 *t))
                    );
    }
};

#endif // SHAPE_H

