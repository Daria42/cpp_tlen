#include "edge.h"
#include <QPainter>

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
	painter->setPen(pen());
	setLine(QLineF(from_->pos(), to_->pos()));
	painter->drawLine(line());
}