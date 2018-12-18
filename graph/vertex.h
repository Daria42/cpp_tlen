#ifndef VERTEX_H
#define VERTEX_H

#include <QGraphicsPixmapItem>
#include <QList>

class QGraphicsItem;
class Edge;

/*!
\brief �����, ����������� ������� �����
��������� ������� ����� �������, � ��� � ������ ��������� ����
*/
class Vertex : public QGraphicsEllipseItem {
 public:
    enum { Type = UserType + 41 };
    Vertex(QGraphicsItem *parent = 0);
    int type() const override { return Type; }
    /*!
    \return ����� �������
    */
    int number() { return number_; }
    /*!
    \return ��� �������
    */
    QString name() { return name_; }
    /*!
    \return ���������� ����, ��������� � ��������
    */
    int edgesCount() { return edges_.size(); }
    /*!
    ������������� ��� �������
    \param str ����������� ���
    */
    void setName(QString str) { name_ = str; }
    /*!
    ������� �����, ��������� � ��������
    \param *edge ��������� �� �������
    */
    void removeEdge(Edge *edge);
    /*!
    ������� ��� ����, ��������� � ��������
    */
    void removeEdges();
    /*!
    ��������� ����� � ������ ��������� �������
    \param *edge ��������� �� �������
    */
    void addEdge(Edge *edge);
    /*!
    ������� ���������� ��� ��������� ������
    \return ����� ��������� �������
    */
    static int getNumber() { return counter_++; }
    /*!
    ���������� ������� ������
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
