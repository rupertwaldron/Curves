#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>

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

class Cycloid : public Shape
{
public:
    Cycloid() {qInfo("Cycloid()");}
    ~Cycloid() {qInfo("~Cycloid()");}
};

class HygensCycloid : public Shape
{
public:
    HygensCycloid() {qInfo("HygensCycloid()");}
    ~HygensCycloid() {qInfo("~HygensCycloid()");}
};

class HypoCycloid : public Shape
{
public:
    HypoCycloid() {qInfo("HypoCycloid()");}
    ~HypoCycloid() {qInfo("~HypoCycloid()");}
};







#endif // SHAPE_H

