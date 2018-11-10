#ifndef VERTEX_H
#define VERTEX_H

#include <QGraphicsPixmapItem>
#include <QList>

//class QPixmap;
class QGraphicsItem;
class QGraphicsScene;
class QGraphicsSceneMouseEvent;
class QMenu;
//class QGraphicsSceneContextMenuEvent;
//class QPainter;
//class QStyleOptionGraphicsItem;
//class QWidget;
class Edge;

class Vertex : public QGraphicsEllipseItem {
public:
	enum { Type = UserType + 41 };
	Vertex(QMenu *contextMenu, QGraphicsItem *parent = 0);
	int type() const override { return Type; }
	void removeEdge(Edge *edge);
	void removeEdges();
	void addEdge(Edge *edge);
	//QGraphicsEllipseItem ellipse() const { return ellipseItem; }
protected:
	void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
	//QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
private:
	//Сделать цвет и размер, добавить установку размера
	//QGraphicsEllipseItem ellipseItem;
	QMenu *contextMenu;
	QList<Edge *> edges;
};

#endif //VERTEX_H