#include "graphscene.h"
#include "edge.h"
#include <QGraphicsSceneMouseEvent>


GraphScene::GraphScene(QMenu *itemMenu, QObject *parent) : QGraphicsScene(parent) {
	this->itemMenu = itemMenu;
}

void GraphScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
	if (mouseEvent->button() != Qt::LeftButton) return;
	if (mode == InsertVertex) {
		Vertex *vertex = new Vertex(itemMenu); 
		vertex->setBrush(mainVertexColor);
		addItem(vertex);
		vertex->setPos(mouseEvent->scenePos());
		//vertex->setColor(mainVertexColor);
		emit(vertexInserted(vertex));
	} //�������� ����� �������
	else if (mode == InsertEdge) {
		edgeLine = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(), mouseEvent->scenePos());
		edgeLine->setPen(QPen(mainEdgeColor, 1));
		addItem(edgeLine);
	} //������ �������� ������ �����
	QGraphicsScene::mousePressEvent(mouseEvent);
}

void GraphScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) {
	if (mode == MoveVertex) QGraphicsScene::mouseMoveEvent(mouseEvent);
	else if (mode == InsertEdge && edgeLine != 0) {
		QLineF movedLine(edgeLine->line().p1(), mouseEvent->scenePos()); //��������� ����������� �����
		edgeLine->setLine(movedLine);
	} //���� ������ ��������� ������ �����, ����������� �� ������ ��������������� �����
}

void GraphScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) {
	if (mode != InsertEdge || edgeLine == 0) return;
	QList<QGraphicsItem *> from = items(edgeLine->line().p1()); //����� ���� ��������� ������
	//if (from.count() && from.first() == edgeLine)
	from.removeFirst();
	QList<QGraphicsItem *> to = items(edgeLine->line().p2());
	//if (to.count() && to.first() == edgeLine)
	to.removeFirst();
	removeItem(edgeLine);
	delete edgeLine;
	if (from.count() && to.count() && from.first() != to.first() &&
		from.first()->type() == Vertex::Type && to.first()->type() == Vertex::Type) {
		Vertex *first = qgraphicsitem_cast<Vertex *>(from.first());
		Vertex *second = qgraphicsitem_cast<Vertex *>(to.first());
		//Edge *edge = new Edge(first, second);
		//edge.setColor(edgeColor);
		//first->addEdge(edge);
		//second->addEdge(edge);
		//addItem(edge);
		//edge->updatePos();
	} //�������� ������ �����, ���� ������������� ��������� ����������� ��������
	edgeLine = 0;
	QGraphicsScene::mouseReleaseEvent(mouseEvent);
}