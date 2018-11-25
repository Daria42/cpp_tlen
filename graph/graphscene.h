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
    enum Mode { InsertVertex, InsertEdge, MoveVertex }; // –ежимы работы сцены
    explicit GraphScene(QObject *parent = 0) : QGraphicsScene(parent) { }
    void setVertexBrushColor(const QColor &color) { vertexPen_.setColor(color); }
    void setVertexPenColor(const QColor &color) { vertexBrush_.setColor(color); }
    void setEdgeColor(const QColor &color) { edgePen_.setColor(color); }
    void setVertexSize(const qreal &size)
        { vertexRect_.setRect(-size / 2, -size / 2, size, size); }
    void setLineWidth(const int &width)
        { vertexPen_.setWidth(width); edgePen_.setWidth(width); }
    void setMode(Mode mode) { mode_ = mode; }
    void replaceAll();

 signals:
    void vertexInserted(Vertex *vertex);

 protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void keyPressEvent(QKeyEvent *keyEvent);
    void keyReleaseEvent(QKeyEvent *keyEvent);

 private:
    Mode mode_{ MoveVertex };  // –ежим сцены
    QBrush vertexBrush_{ QBrush(Qt::white) };  // ÷вет вершины
    QPen vertexPen_{ QPen(Qt::black, 2) };  // ÷вет границы эллипса вершины
    QPen edgePen_{ QPen(Qt::black, 2) };  // ÷вет рЄбер
    QRectF vertexRect_{ QRectF(-25, -25, 50, 50) };
    QGraphicsLineItem *line_{ nullptr };  // –ебро в процессе создани€
};

#endif  // GRAPHSCENE_H
