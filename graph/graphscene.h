#ifndef GRAPHSCENE_H
#define GRAPHSCENE_H

#include "vertex.h"
#include <QGraphicsScene>

class QPointF;
class QGraphicsEllipseItem;
class QGraphicsLineItem;
class QColor;

class GraphScene : public QGraphicsScene {
	Q_OBJECT

public:
	enum Mode { InsertVertex, InsertEdge, MoveVertex, DeleteVertex }; //������ ������ �����
	explicit GraphScene(QObject *parent = 0) : QGraphicsScene(parent) { }
	void setVertexColor(const QColor &color) { mainVertexColor = color; } //���������� ��������� ���� �������
	void setEdgeColor(const QColor &color) { mainEdgeColor = color; } //���������� �������� ���� �����
	void setMode(Mode mode) { this->mode = mode; } //�������� ����� �����

												   //private slots:

signals:
	void vertexInserted(Vertex *vertex);

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
	Mode mode{ InsertVertex }; //�����
	QColor mainVertexColor{ Qt::blue }; //������� ���� ������
	QColor mainEdgeColor{ Qt::black }; //�������� ���� ����
	qreal mainVertexSize{ 50 };
	QGraphicsLineItem *edgeLine{ nullptr }; //����� � �������� ��������
};

#endif //GRAPHSCENE_H