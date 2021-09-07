#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent), mBackgroundColor(0,0,255),
    mShapeColor(255,255,255),
    mShape(Astroid)
{
    on_shape_changed();
}

QSize RenderArea::minimumSizeHint() const
{
   return QSize(100,100);
}
QSize RenderArea::sizeHint() const
{
    return QSize(400,200);
}

void RenderArea::on_shape_changed()
{
    switch (mShape)
    {
    case Astroid:
        mScale = 50;
        mIntervalLength = 2 * M_PI;
        mStepCount = 256;
        break;

    case Cycloid:
        mScale = 4;
        mIntervalLength = 6 * M_PI;
        mStepCount = 128;
        break;

    case HuygensCycloid:
        mScale = 4;
        mIntervalLength = 4 * M_PI;
        mStepCount = 256;
        break;

    case HypoCycloid:
        mScale = 15;
        mIntervalLength = 2 * M_PI;
        mStepCount = 256;
        break;

    default:
        break;

    }
}

QPointF  RenderArea::compute_astroid(float t)
{
    float x = pow(cos(t),3);
    float y = pow(sin(t),3);
    return QPointF(x,y);
}

QPointF  RenderArea::compute_cycloid(float t)
{
    float x = 1.5 * (1 - cos(t));
    float y = 1.5 * (t - sin(t));
    return QPointF(x,y);
}

QPointF  RenderArea::compute_huygens(float t)
{
    float x = 4 * (3 * cos(t) - cos(3*t));
    float y = 4 * (3 * sin(t) - sin(3*t));
    return QPointF(x,y);
}

QPointF  RenderArea::compute_hypoCycloid(float t)
{
    float x = 1.5 * (2 * cos(t) - cos(2*t));
    float y = 1.5 * (2 * sin(t) - sin(2*t));
    return QPointF(x,y);
}

QPointF  RenderArea::compute(float t)
{
    switch (mShape)
    {
    case Astroid:
        return compute_astroid(t);
        break;

    case Cycloid:
        return compute_cycloid(t);
        break;

    case HuygensCycloid:
        return compute_huygens(t);
        break;

    case HypoCycloid:
        return compute_hypoCycloid(t);
        break;

    default:
        break;

    }
    return QPointF(0, 0);

}

void RenderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(mBackgroundColor);
    painter.setRenderHint(QPainter::Antialiasing , true);
    painter.setPen(mShapeColor);

    painter.drawRect(this->rect());

    QPoint center = this->rect().center();
    QPointF prevPoint = compute (0);
    QPoint prevPixel;
    prevPixel.setX(prevPoint.x() * mScale + center.x());
    prevPixel.setY(prevPoint.y() * mScale + center.y());
    if (mShape == Cycloid)
    {
        center.setY(center.y() - this->rect().height()/2);
        prevPixel.setY(prevPixel.y() - this->rect().height()/2);
    }

    float step =mIntervalLength/mStepCount;
    for (float t = 0; t <mIntervalLength  ; t+=step)
    {
        QPointF point = compute(t);

        QPoint pixel;
        pixel.setX(point.x() * mScale + center.x());
        pixel.setY(point.y() * mScale + center.y());

        painter.drawLine(pixel, prevPixel);
        prevPixel = pixel;
    }

}
