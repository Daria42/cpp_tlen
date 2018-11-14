#ifndef GRAPHSCENE_H
#define GRAPHSCENE_H

#include "vertex.h"
#include <QGraphicsScene>

class QPointF;
class QGraphicsEllipseItem;
class QGraphicsLineItem;
class QColor;
class QRectF;

class GraphScene : public QGraphicsScene {
	Q_OBJECT

public:
	enum Mode { InsertVertex, InsertEdge, MoveVertex }; //режимы работы сцены
	explicit GraphScene(QObject *parent = 0) : QGraphicsScene(parent) { }
	void setVertexBrushColor(const QColor &color) { vertexPen_.setColor(color); }
	void setVertexPenColor(const QColor &color) { vertexBrush_.setColor(color); }
	void setEdgeColor(const QColor &color) { edgePen_.setColor(color); }
	void setVertexSize(const qreal &size) { vertexRect_.setRect(-size / 2, -size / 2, size, size); }
	void setLineWidth(const int &width) { vertexPen_.setWidth(width); edgePen_.setWidth(width); }
	void setMode(Mode mode) { mode_ = mode; }

signals:
	void vertexInserted(Vertex *vertex);

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	//void wheelEvent(QWheelEvent* event) override;
	//void wheelEvent(QWheelEvent* event) override;

private:
	Mode mode_{ InsertVertex }; //режим сцены
	QBrush vertexBrush_{ QBrush(Qt::white) }; //цвет вершины
	QPen vertexPen_{ QPen(Qt::black, 2) }; //цвет границы эллипса вершины
	QPen edgePen_{ QPen(Qt::black, 2) }; //цвет рёбер
	QRectF vertexRect_{ QRectF(-25, -25, 50, 50) };
	QGraphicsLineItem *line_{ nullptr }; //ребро в процессе создания
};

#endif //GRAPHSCENE_H