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
	enum Mode { InsertVertex, InsertEdge, MoveVertex }; //режимы работы сцены
	explicit GraphScene(QMenu *itemMenu, QObject *parent = 0);
	QColor vertexColor() const { return mainVertexColor; } //получение цвета вершины
	QColor edgeColor() const { return mainEdgeColor; } //получение цвета ребра
	void setVertexColor(const QColor &color) { mainVertexColor = color; } //установить дефолтный цвет вершины
	void setEdgeColor(const QColor &color) { mainEdgeColor = color; } //установить дефолтнй цвет ребра

private slots:
	void setMode(Mode mode) { mode = mode; } //изменить режим сцены

signals:
	void vertexInserted(Vertex *vertex);
	//void itemSelected(QGraphicsItem *item);

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
	Mode mode{ MoveVertex }; //режим
	QColor mainVertexColor{ Qt::black }; //основой цвет вершин
	QColor mainEdgeColor{ Qt::lightGray }; //основной цвет рёбер
	QGraphicsLineItem *edgeLine{ nullptr }; //ребро в процессе создания
	QMenu *itemMenu{ nullptr };


	//bool isItemChange(int type);
	//bool leftButtonDown{ false };
	//QPointF startPoint;
};

#endif //GRAPHSCENE_H