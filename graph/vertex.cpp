#include "vertex.h"
#include "edge.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QString>

int Vertex::counter_ = 0;

Vertex::Vertex(QGraphicsItem *parent)
        : QGraphicsEllipseItem(parent), number_(getNumber()) {
    setFlag(QGraphicsItem::ItemIsMovable, true);
}

void Vertex::removeEdge(Edge *edge) {
    int index = edges_.indexOf(edge);
    if (index != -1) {
        edges_.removeAt(index);
    }
}

void Vertex::removeEdges() {
    for (auto edge : edges_) {
        edge->from()->removeEdge(edge);
        edge->to()->removeEdge(edge);
        scene()->removeItem(edge);
        delete edge;
    }
}

void Vertex::addEdge(Edge *edge) {
    edges_.append(edge);
}

void Vertex::paint(QPainter *painter,
        const QStyleOptionGraphicsItem *, QWidget *) {
    painter->setPen(pen());
    painter->setBrush(brush());
    painter->drawEllipse(rect());
    qreal tx = pos().x();
    qreal ty = pos().y();
    QFont font;
    font.setPointSize(rect().width() / 3);
    painter->setFont(font);
    if (name_ == "") {
        QString number = QString::number(number_);
        painter->drawText(rect(), Qt::AlignCenter, number);
    }
    else {
        painter->drawText(rect(), Qt::AlignCenter, name_);
    }
}

QVariant Vertex::itemChange(GraphicsItemChange change,
        const QVariant &value) {
    if (change == QGraphicsEllipseItem::ItemPositionChange) {
        for (auto edge : edges_) {
            edge->updatePos();
        }
    }
    return value;
}
