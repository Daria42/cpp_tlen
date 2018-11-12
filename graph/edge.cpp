#include "edge.h"
#include <QPainter>

Edge::Edge(Vertex *from, Vertex *to, QGraphicsItem *parent) : QGraphicsLineItem(parent) {
	first = from;
	second = to;
	setFlag(QGraphicsItem::ItemIsSelectable, true);
	setZValue(-100);
}

void Edge::updatePos() {
	QLineF line(mapFromItem(first, 0, 0), mapFromItem(second, 0, 0));
	setLine(line);
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
	if (first->collidesWithItem(second)) return;
	QPen myPen = pen();
	myPen.setColor(Qt::black);
	painter->setPen(myPen);
	QLineF centerLine(first->pos(), second->pos());
	setLine(QLineF(first->pos(), second->pos()));
	painter->drawLine(line());
}