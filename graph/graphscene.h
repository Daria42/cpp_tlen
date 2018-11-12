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
	enum Mode { InsertVertex, InsertEdge, MoveVertex, DeleteVertex }; //режимы работы сцены
	explicit GraphScene(QObject *parent = 0) : QGraphicsScene(parent) { }
	void setVertexColor(const QColor &color) { mainVertexColor = color; } //установить дефолтный цвет вершины
	void setEdgeColor(const QColor &color) { mainEdgeColor = color; } //установить дефолтнй цвет ребра
	void setMode(Mode mode) { this->mode = mode; } //изменить режим сцены

												   //private slots:

signals:
	void vertexInserted(Vertex *vertex);

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
	Mode mode{ InsertVertex }; //режим
	QColor mainVertexColor{ Qt::blue }; //основой цвет вершин
	QColor mainEdgeColor{ Qt::black }; //основной цвет рёбер
	qreal mainVertexSize{ 50 };
	QGraphicsLineItem *edgeLine{ nullptr }; //ребро в процессе создания
};

#endif //GRAPHSCENE_H