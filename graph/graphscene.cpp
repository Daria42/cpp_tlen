#include "graphscene.h"
#include "edge.h"
#include <QGraphicsSceneMouseEvent>

void GraphScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
	if (mouseEvent->button() == Qt::RightButton) {
		QList<QGraphicsItem *> elements = items(mouseEvent->scenePos()); //����� ���� ��������� ������
		if (elements.count() != 0 && elements.first()->type() == Vertex::Type) {
			Vertex *vertex = qgraphicsitem_cast<Vertex *>(elements.first());
			vertex->removeEdges();
			removeItem(vertex);
			delete vertex;
		}
		else if (elements.count() != 0) {
			Edge *edge = qgraphicsitem_cast<Edge *>(elements.first());
			edge->from()->removeEdge(edge);
			edge->to()->removeEdge(edge);
			removeItem(edge);
			delete edge;
		}
	} //�������� ��������� ������ ������� ����
	else if (mouseEvent->button() == Qt::LeftButton) {
		if (mode == InsertVertex) {
			Vertex *vertex = new Vertex();
			vertex->setRect(-mainVertexSize / 2, -mainVertexSize / 2, mainVertexSize, mainVertexSize);
			vertex->setBrush(mainVertexColor);
			vertex->setPen(QPen(mainEdgeColor, 0));
			vertex->setPos(mouseEvent->scenePos());
			addItem(vertex);
			emit(vertexInserted(vertex));
		} //�������� ����� �������
		else if (mode == InsertEdge) {
			edgeLine = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(), mouseEvent->scenePos()));
			edgeLine->setPen(QPen(mainEdgeColor, 2));
			edgeLine->setZValue(-100);
			addItem(edgeLine);
		} //������ �������� ������ �����
		QGraphicsScene::mousePressEvent(mouseEvent);
	}
}

void GraphScene::mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	if (mode == MoveVertex) QGraphicsScene::mouseMoveEvent(mouseEvent);
	else if (mode == InsertEdge && edgeLine != 0) {
		QLineF movedLine(edgeLine->line().p1(), mouseEvent->scenePos()); //��������� ����������� �����
		edgeLine->setLine(movedLine);
	} //���� ������ ��������� ������ �����, ����������� �� ������ ��������������� �����
}

void GraphScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) {
	if (mode == InsertEdge && edgeLine != 0) {
		QList<QGraphicsItem *> from = items(edgeLine->line().p1()); //����� ���� ��������� ������
		if (from.count() && from.first() == edgeLine) from.removeFirst();
		QList<QGraphicsItem *> to = items(edgeLine->line().p2());
		if (to.count() && to.first() == edgeLine) to.removeFirst();
		removeItem(edgeLine);
		delete edgeLine;
		if (from.count() && to.count() && from.first() != to.first() &&
			from.first()->type() == Vertex::Type && to.first()->type() == Vertex::Type) {
			Vertex *first = qgraphicsitem_cast<Vertex *>(from.first());
			Vertex *second = qgraphicsitem_cast<Vertex *>(to.first());
			Edge *edge = new Edge(first, second);
			edge->setPen(QPen(mainEdgeColor, 2));
			first->addEdge(edge);
			second->addEdge(edge);
			addItem(edge);
			edge->updatePos();
		} //�������� ������ �����, ���� ������������� ��������� ����������� ��������
		edgeLine = 0;
	}
	QGraphicsScene::mouseReleaseEvent(mouseEvent);
}


