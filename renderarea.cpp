#include <QtGui>
#include "renderarea.h"

#define SIDE_LENGTH 15

RenderArea::RenderArea(QWidget* parent) : QWidget(parent)
{
    cellular = new Cellular(34, 21);
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(next()));
}

RenderArea::~RenderArea() {
    delete timer;
    delete cellular;
}

void RenderArea::next() {
    cellular->next();
    update();
}

void RenderArea::play() {
    timer->start(100);
}

void RenderArea::stop() {
    timer->stop();
}

void RenderArea::save() {
    cellular->save();
}

void RenderArea::restore() {
    cellular->restore();
    update();
}

int RenderArea::getCoordinate(int cell_index) const {
    return cell_index * SIDE_LENGTH + SIDE_LENGTH / 2;
}

int RenderArea::getIndex(int coordinate) const {
    return (coordinate - SIDE_LENGTH / 2) / SIDE_LENGTH;
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(SIDE_LENGTH * (cellular->sizeX() + 1), SIDE_LENGTH * (cellular->sizeY() + 1));
}

void RenderArea::mousePressEvent(QMouseEvent* event) {
    cellular->invertCell(getIndex(event->x()), getIndex(event->y()));
    update();
}

void RenderArea::paintEvent(QPaintEvent*)
{
    QRect rect(0, 0, SIDE_LENGTH, SIDE_LENGTH);

    QBrush brush_state0(Qt::white);
    QBrush brush_state1(Qt::darkGreen);
    QPen pen(Qt::black);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(pen);

    for (int x = 0; x < cellular->sizeX(); ++x) {
        for (int y = 0; y < cellular->sizeY(); ++y) {
            if (cellular->cell(x, y) == 0) painter.setBrush(brush_state0);
            else painter.setBrush(brush_state1);
        
            painter.save();
            painter.translate(getCoordinate(x), getCoordinate(y));
            painter.drawRect(rect);
            painter.restore();
        }
    }

    painter.setRenderHint(QPainter::Antialiasing, false);
}
