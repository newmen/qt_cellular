#include <QtGui>

#include "renderarea.h"

#define SIDE_LENGTH 20

RenderArea::RenderArea(QWidget* parent) :
    QWidget(parent), cellular(21, 13)
{
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(next()));
}

RenderArea::~RenderArea() {
    delete timer;
}

void RenderArea::next() {
    cellular.next();
    update();
}

void RenderArea::play() {
    timer->start(100);
}

void RenderArea::stop() {
    timer->stop();
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(SIDE_LENGTH * (cellular.sizeX() + 1), SIDE_LENGTH * (cellular.sizeY() + 1));
}

void RenderArea::paintEvent(QPaintEvent*)
{
    QRect rect(0, 0, SIDE_LENGTH, SIDE_LENGTH);

    QBrush brush_state0(Qt::white);
    QBrush brush_state1(Qt::green);
    QPen pen(Qt::black);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(pen);

    for (int x = 0; x < cellular.sizeX(); ++x) {
        for (int y = 0; y < cellular.sizeY(); ++y) {
            if (cellular.cell(x, y) == 0) painter.setBrush(brush_state0);
            else painter.setBrush(brush_state1);
        
            int real_x = x * SIDE_LENGTH + SIDE_LENGTH / 2;
            int real_y = y * SIDE_LENGTH + SIDE_LENGTH / 2;
            painter.save();
            painter.translate(real_x, real_y);
            painter.drawRect(rect);
            painter.restore();
        }
    }

    painter.setRenderHint(QPainter::Antialiasing, false);
}
