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
	enum Mode { InsertVertex, InsertEdge, MoveVertex }; //������ ������ �����
	explicit GraphScene(QMenu *itemMenu, QObject *parent = 0);
	QColor vertexColor() const { return mainVertexColor; } //��������� ����� �������
	QColor edgeColor() const { return mainEdgeColor; } //��������� ����� �����
	void setVertexColor(const QColor &color) { mainVertexColor = color; } //���������� ��������� ���� �������
	void setEdgeColor(const QColor &color) { mainEdgeColor = color; } //���������� �������� ���� �����

private slots:
	void setMode(Mode mode) { mode = mode; } //�������� ����� �����

signals:
	void vertexInserted(Vertex *vertex);
	//void itemSelected(QGraphicsItem *item);

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
	Mode mode{ MoveVertex }; //�����
	QColor mainVertexColor{ Qt::black }; //������� ���� ������
	QColor mainEdgeColor{ Qt::lightGray }; //�������� ���� ����
	QGraphicsLineItem *edgeLine{ nullptr }; //����� � �������� ��������
	QMenu *itemMenu{ nullptr };


	//bool isItemChange(int type);
	//bool leftButtonDown{ false };
	//QPointF startPoint;
};

#endif //GRAPHSCENE_H