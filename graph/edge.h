#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"
#include <QGraphicsPixmapItem>
#include <QList>

class Edge : public QGraphicsLineItem {
 public:
    enum { Type = UserType + 29 };
    Edge(Vertex *from, Vertex *to, QGraphicsItem *parent = 0);
    int type() const override { return Type; }
    Vertex *from() const { return from_; }
    Vertex *to() const { return to_; }
    void updatePos();  // Изменяет положение ребра на экране

 protected:
    void paint(QPainter *painter, 
        const QStyleOptionGraphicsItem *option,
        QWidget *widget = 0) override;

 private:
    int number_;  // Номер ребра
    Vertex *from_{ nullptr };  // Откуда идёт ребро
    Vertex *to_{ nullptr };  // Куда идёт ребро
};

#endif  // EDGE_H
