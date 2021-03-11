#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor(QColor (0, 0, 255)),
    mShapeColor(255, 255, 255)
{
    qInfo("RenderArea(QWidget *)");
}

RenderArea::~RenderArea()
{
    delete mShape;
    qInfo("~RenderArea()");
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 400);
}

void RenderArea::setShape(Shape *shape)
{
    if (mShape == nullptr) {
        mShape = shape;
    } else {
        delete mShape;
        mShape = shape;
    }
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if (mShape != nullptr) {
        painter.setBrush(mShape->getShapeColor());
    } else {
        painter.setBrush(mBackgroundColor);
    }
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(mShapeColor);

    painter.drawRect(this->rect());
    painter.drawLine(this->rect().topLeft(), this->rect().bottomRight());
}
