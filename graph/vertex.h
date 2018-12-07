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
    QString name() { return name_; }
    int edgesCount() { return edges_.size(); }
    void setName(QString str) { name_ = str; }
    void removeEdge(Edge *edge);  // Удаляет ребро из списка смежности
    void removeEdges();  // Удаляет все рёбра вершины
    void addEdge(Edge *edge);  // Добавляет ребро в список смежности
    static int getNumber() { return counter_++; }
    static void resertCounter() { counter_ = 0; }  // Сбрасывает счётчик

 protected:
    void paint(QPainter *painter,
        const QStyleOptionGraphicsItem *option,
        QWidget *widget = 0) override;
    QVariant itemChange(GraphicsItemChange change,
        const QVariant &value) override;

 private:
    static int counter_;  // счётчик вершин
    QString name_{ "" };  // Имя вершины (если имени нет, отображается номер)
    int number_{ 0 };  // Номер вершины
    QList<Edge *> edges_;  // Список смежности
};

#endif  // VERTEX_H
