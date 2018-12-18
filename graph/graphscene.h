#ifndef GRAPHSCENE_H
#define GRAPHSCENE_H

#include "vertex.h"
#include <QGraphicsScene>

class QPointF;
class QGraphicsEllipseItem;
class QGraphicsLineItem;
class QColor;
class QRectF;
class QFile;

/*!
\brief �����, ����������� ��������������� ������ � ������
��������� ������������ �������, ���������, ���������� ������� � ��������� ����
*/
class GraphScene : public QGraphicsScene {
    Q_OBJECT

 public:
     /// ����� ��������� ������� �����
    enum Mode {
        InsertVertex, /// ���������� �������
        InsertEdge, /// ���������� �����
        MoveVertex /// ����������� �������
    };
    explicit GraphScene(QObject *parent = 0)
        : QGraphicsScene(parent) { }
    /*!
    ��������� ���� ������� �� ���������
    \param &color ������ �� ������ ����
    */
    void setVertexBrushColor(const QColor &color) {
        vertexPen_.setColor(color);
    }
    /*!
    ��������� ���� ������� �������� �� ���������
    \param &color ������ �� ������ ����
    */
    void setVertexPenColor(const QColor &color) {
        vertexBrush_.setColor(color);
    }
    /*!
    ��������� ���� ����� �� ���������
    \param &color ������ �� ������ ����
    */
    void setEdgeColor(const QColor &color) {
        edgePen_.setColor(color);
    }
    /*!
    ��������� ������ �������� �� ���������
    \param &size ������ �� �������� �������
    */
    void setVertexSize(const qreal &size) {
        vertexRect_.setRect(-size / 2, -size / 2, size, size);
    }
    /*!
    ��������� ������� ����� �� ���������
    \param &width ������ �� �������� �������
    */
    void setLineWidth(const int &width) {
        vertexPen_.setWidth(width); edgePen_.setWidth(width);
    }
    /*!
    ��������� ����� �����
    \param mode ����������� �����
    */
    void setMode(Mode mode) { mode_ = mode; }
    /*!
    ����������� ��� ������� �� �����
    */
    void replaceAll();
    /*!
    �������� ������� ���� ������� .dot
    \param &file ������ �� ���� (������ ���� QFile)
    \return true, ���� �������� ����� � ��� ������� ����������� �������, ����� - false
    */
    bool openGraph(QFile &file);
    /*!
    �������� ��������� ���� � ������� .dot
    \param &path ������ �� ������, ���������� ���� � �����
    */
    void saveGraph(QString &path);

 signals:
    void vertexInserted(Vertex *vertex);

 protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void keyPressEvent(QKeyEvent *keyEvent);
    void keyReleaseEvent(QKeyEvent *keyEvent);

 private:
    Mode mode_{ MoveVertex };
    QBrush vertexBrush_{ QBrush(Qt::white) };
    QPen vertexPen_{ QPen(Qt::black, 2) };
    QPen edgePen_{ QPen(Qt::black, 2) };
    QRectF vertexRect_{ QRectF(-25, -25, 50, 50) };
    QGraphicsLineItem *line_{ nullptr };
};

#endif  // GRAPHSCENE_H
