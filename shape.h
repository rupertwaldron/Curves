#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>

class Shape
{
public:
    Shape() {qInfo("Shape()");}
    virtual ~Shape() {qInfo("~Shape()");}
    QColor getShapeColor() {return m_color;}
protected:
    QColor m_color;
};

class Astroid : public Shape
{
public:
    Astroid() {
        m_color = Qt::red;
        qInfo("Astroid()");
    }
    ~Astroid() {qInfo("~Astroid()");}
};

class Cycloid : public Shape
{
public:
    Cycloid() {
        m_color = Qt::green;
        qInfo("Cycloid()");
    }
    ~Cycloid() {qInfo("~Cycloid()");}
};

class HygensCycloid : public Shape
{
public:
    HygensCycloid() {
        m_color = Qt::cyan;
        qInfo("HygensCycloid()");
    }
    ~HygensCycloid() {qInfo("~HygensCycloid()");}
};

class HypoCycloid : public Shape
{
public:
    HypoCycloid() {
        m_color = Qt::yellow;
        qInfo("HypoCycloid()");
    }
    ~HypoCycloid() {qInfo("~HypoCycloid()");}
};







#endif // SHAPE_H

