#include "vertex.h"
#include "edge.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QString>

int Vertex::counter_ = 0;

Vertex::Vertex(QGraphicsItem *parent) : QGraphicsEllipseItem(parent), number_(getNumber()) {
	setFlag(QGraphicsItem::ItemIsMovable, true);
}

void Vertex::removeEdge(Edge *edge) {
	int index = edges_.indexOf(edge);
	if (index != -1) edges_.removeAt(index);
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

QString convertToQString(int a) {
	QString finalRes;
	if (a == 0)
		finalRes = QString("0");
	else {
		QString res;
		while (a > 0) {
			res.append(QChar(int(a % 10 + '0')));
			a /= 10;
		}
		for (int i = res.size() - 1; i >= 0; i--)
			finalRes.append(res[i]);
	}
	return finalRes;
}

void Vertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
	painter->setPen(pen());
	painter->setBrush(brush());
	painter->drawEllipse(rect());
	qreal tx = pos().x();
	qreal ty = pos().y();
	QString numb = QString(convertToQString(number_));
	QFont font;
	font.setPointSize(rect().width() / 3);
	painter->setFont(font);
	painter->drawText(rect(), Qt::AlignCenter, numb);
}

QVariant Vertex::itemChange(GraphicsItemChange change, const QVariant &value) {
	if (change == QGraphicsEllipseItem::ItemPositionChange)
		for (auto edge : edges_)
			edge->updatePos();
	return value;
}