#ifndef VERTEX_H
#define VERTEX_H

#include <QGraphicsPixmapItem>
#include <QList>

class QGraphicsItem;
class QGraphicsScene;
class QGraphicsSceneMouseEvent;
class QMenu;
class QGraphicsSceneContextMenuEvent;
class QWidget;
class Edge;

class Vertex : public QGraphicsEllipseItem {
public:
	enum { Type = UserType + 41 };
	Vertex(QGraphicsItem *parent = 0); //QMenu *contextMenu
	int type() const override { return Type; }
	void removeEdge(Edge *edge);
	void removeEdges();
	void addEdge(Edge *edge);

protected:
	QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
	QList<Edge *> edges;
};

#endif //VERTEX_H