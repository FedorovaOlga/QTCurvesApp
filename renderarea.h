#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum ShapeType {Astroid, Cycloid, HuygensCycloid, HypoCycloid,FancyCurve};

    void setBackgroundColor(QColor col) {mBackgroundColor = col;}
    QColor backgroundColor() const {return mBackgroundColor;}
    void setShapeColor(QColor col) {mShapeColor = col;}
    QColor shapeColor() const {return mShapeColor;}

    void setShape(ShapeType shape) {mShape = shape; on_shape_changed();}
    QColor getShape() const {return mShape;}

    void setScale(float scale) { mScale = scale; repaint(); }
    float scale() const {return mScale;}

    void setInternalLength(float intLenth) { mIntervalLength = intLenth; repaint(); }
    float internalLength() const {return mIntervalLength;}

    void setStepCount(int cnt) { mStepCount = cnt; repaint(); }
    int stepCount() const {return mStepCount;}

    void setFancyCurveParams(int a, int b) { fancyCurveA = a; fancyCurveB = b; repaint(); }
    float getFancyCurveA() const {return fancyCurveA;}
    float getFancyCurveB() const {return fancyCurveB;}

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
signals:

private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;
    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_huygens(float t);
    QPointF compute_hypoCycloid(float t);
    QPointF compute_fancyCurve(float t);
    QPointF compute(float t);
    void on_shape_changed();
    float mIntervalLength;
    float mScale;
    int mStepCount;
    float fancyCurveA;
    float fancyCurveB;


};

#endif // RENDERAREA_H
