#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>

//    enum Shapes { Astroid, Cicloid, HygensCicloid, HypoCicloid };

class Shape
{
public:
    Shape() {qInfo("Shape()");}
    virtual ~Shape() {qInfo("~Shape()");}
};

class Astroid : public Shape
{
public:
    Astroid() {qInfo("Astroid()");}
    ~Astroid() {qInfo("~Astroid()");}
};







#endif // SHAPE_H

