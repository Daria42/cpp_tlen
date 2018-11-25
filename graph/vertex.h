#ifndef VERTEX_H
#define VERTEX_H

#include <QGraphicsPixmapItem>
#include <QList>

class QGraphicsItem;
class Edge;

class Vertex : public QGraphicsEllipseItem {
 public:
    enum { Type = UserType + 41 };
    Vertex(QGraphicsItem *parent = 0);
    int type() const override { return Type; }
    int number() { return number_; }
    void setName(QString &str) { name_ = str; }
    void removeEdge(Edge *edge);
    void removeEdges();
    void addEdge(Edge *edge);
    static int getNumber() { return counter_++; }
    static void resertCounter() { counter_ = 0; }

 protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

 private:
    static int counter_;
    QString name_{ "" };
    int number_{ 0 };  // Номер вершины
    QList<Edge *> edges_;  // Список смежности
};

#endif  // VERTEX_H
