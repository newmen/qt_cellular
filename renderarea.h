#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include "cellular.h"

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = 0);
    virtual ~RenderArea();

    QSize minimumSizeHint() const;

//signals:
public slots:
    void next();
    void play();
    void stop();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Cellular cellular;
    QTimer* timer;
};

#endif // RENDERAREA_H
