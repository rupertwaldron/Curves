#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor(QColor (0, 0, 255)),
    mShapeColor(255, 255, 255),
    mShape{new Astroid()}
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
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setBrush(mShape->getShapeColor());
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(mShapeColor);

    auto canvas = this->rect();

    painter.drawRect(canvas);
    mShape->drawShape(canvas, painter);

//    painter.drawLine(this->rect().topLeft(), this->rect().bottomRight());
}
