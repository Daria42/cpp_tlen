#include "edge.h"
#include <QPainter>
#include <QtMath>

Edge::Edge(Vertex *from, Vertex *to, QGraphicsItem *parent) : QGraphicsLineItem(parent) {
    from_ = from;
    to_ = to;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setZValue(-100);
}

void Edge::updatePos() {
    QLineF line(mapFromItem(from_, 0, 0), mapFromItem(to_, 0, 0));
    setLine(line);
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    if (from_->pos() == to_->pos()) return;
    if (weight_ != 1) {
        QPointF delta(qreal(from_->x() - to_->x()), qreal(from_->y() - to_->y()));
        qreal deltaLen = qSqrt(delta.x() * delta.x() + delta.y() * delta.y());
        delta.setX(15 * delta.x() / deltaLen);
        delta.setY(15 * delta.y() / deltaLen);
        QPointF A((from_->x() + to_->x()) / 2 + delta.x(),
            (from_->y() + to_->y()) / 2 + delta.y());
        QPointF B((from_->x() + to_->x()) / 2 - delta.x(),
            (from_->y() + to_->y()) / 2 - delta.y());
        setLine(QLineF(from_->pos(), to_->pos()));
        painter->setPen(pen());
        painter->drawLine(QLineF(from_->pos(), A));
        painter->drawLine(QLineF(B, to_->pos()));
        QRectF rect((from_->x() + to_->x()) / 2 - 10,
            (from_->y() + to_->y()) / 2 - 10, 20, 20);
        QFont font;
        font.setPointSize(12);
        QString weight = QString::number(weight_);
        painter->setPen(pen());
        painter->setFont(font);
        painter->drawText(rect, Qt::AlignCenter, weight);
    }
    else {
        painter->setPen(pen());
        setLine(QLineF(from_->pos(), to_->pos()));
        painter->drawLine(QLineF(from_->pos(), to_->pos()));
    }
}
