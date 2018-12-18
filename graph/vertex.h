#ifndef VERTEX_H
#define VERTEX_H

#include <QGraphicsPixmapItem>
#include <QList>

class QGraphicsItem;
class Edge;

/*!
\brief Класс, реализующий вершину графа
Позволяет хранить номер вершины, её имя и список связанных рёбер
*/
class Vertex : public QGraphicsEllipseItem {
 public:
    enum { Type = UserType + 41 };
    Vertex(QGraphicsItem *parent = 0);
    int type() const override { return Type; }
    /*!
    \return Номер вершины
    */
    int number() { return number_; }
    /*!
    \return Имя вершины
    */
    QString name() { return name_; }
    /*!
    \return Количество рёбер, связанных с вершиной
    */
    int edgesCount() { return edges_.size(); }
    /*!
    Устанавливает имя вершины
    \param str Необходимое имя
    */
    void setName(QString str) { name_ = str; }
    /*!
    Удаляет ребро, связанное с вершиной
    \param *edge Указатель на вершину
    */
    void removeEdge(Edge *edge);
    /*!
    Удаляет все рёбра, связанные с вершиной
    */
    void removeEdges();
    /*!
    Добавляет ребро в список смежности вершины
    \param *edge Указатель на вершину
    */
    void addEdge(Edge *edge);
    /*!
    Функция необходима для нумерации вершин
    \return Номер следующей вершины
    */
    static int getNumber() { return counter_++; }
    /*!
    Сбрасывает счётчик вершин
    */
    static void resertCounter() { counter_ = 0; }

 protected:
    void paint(QPainter *painter,
        const QStyleOptionGraphicsItem *option,
        QWidget *widget = 0) override;
    QVariant itemChange(GraphicsItemChange change,
        const QVariant &value) override;

 private:
    static int counter_;
    QString name_{ "" };
    int number_{ 0 };
    QList<Edge *> edges_; 
};

#endif  // VERTEX_H
