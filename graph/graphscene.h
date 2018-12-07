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

class GraphScene : public QGraphicsScene {
    Q_OBJECT

 public:
    enum Mode { InsertVertex, InsertEdge, MoveVertex }; // Режимы работы сцены
    explicit GraphScene(QObject *parent = 0)
        : QGraphicsScene(parent) { }
    void setVertexBrushColor(const QColor &color) {
        vertexPen_.setColor(color);
    }
    void setVertexPenColor(const QColor &color) {
        vertexBrush_.setColor(color);
    }
    void setEdgeColor(const QColor &color) {
        edgePen_.setColor(color);
    }
    void setVertexSize(const qreal &size) {
        vertexRect_.setRect(-size / 2, -size / 2, size, size);
    }
    void setLineWidth(const int &width) {
        vertexPen_.setWidth(width); edgePen_.setWidth(width);
    }
    void setMode(Mode mode) { mode_ = mode; }
    void replaceAll();  // Располагает вершины на экране по кругу
    bool openGraph(QFile &file);  // Пытается открыть файл dot
    void saveGraph(QString &path);  // Сохраняет граф в файл

 signals:
    void vertexInserted(Vertex *vertex);

 protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void keyPressEvent(QKeyEvent *keyEvent);
    void keyReleaseEvent(QKeyEvent *keyEvent);

 private:
    Mode mode_{ MoveVertex };  // Режим сцены
    QBrush vertexBrush_{ QBrush(Qt::white) };  // Цвет вершины
    QPen vertexPen_{ QPen(Qt::black, 2) };  // Цвет границы эллипса вершины
    QPen edgePen_{ QPen(Qt::black, 2) };  // Цвет рёбер
    QRectF vertexRect_{ QRectF(-25, -25, 50, 50) };
    QGraphicsLineItem *line_{ nullptr };  // Ребро в процессе создания
};

#endif  // GRAPHSCENE_H
