#include "vertex.h"
#include "edge.h"
#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QPainter>

Vertex::Vertex(QGraphicsItem *parent) : QGraphicsEllipseItem(parent) {
	this->setFlag(QGraphicsItem::ItemIsMovable, true);
	//this->setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void Vertex::removeEdge(Edge *edge) {
	int index = edges.indexOf(edge);
	if (index != -1) edges.removeAt(index);
}

void Vertex::removeEdges() {
	for (auto edge : edges) {
		edge->from()->removeEdge(edge);
		edge->to()->removeEdge(edge);
		scene()->removeItem(edge);
		delete edge;
	}
}

void Vertex::addEdge(Edge *edge) {
	edges.append(edge);
}

QVariant Vertex::itemChange(GraphicsItemChange change, const QVariant &value) {
	if (change == QGraphicsEllipseItem::ItemPositionChange)
		for (auto edge : edges) edge->updatePos();
	return value;
}