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
\brief Класс, реализующий непосредственно работу с графом
Позволяет пользователю удалять, добавлять, перемещать вершины и создавать рёбра
*/
class GraphScene : public QGraphicsScene {
    Q_OBJECT

 public:
     /// Набор возможных режимов сцены
    enum Mode {
        InsertVertex, /// Добавление вершины
        InsertEdge, /// Добавление ребра
        MoveVertex /// Перемещение вершины
    };
    explicit GraphScene(QObject *parent = 0)
        : QGraphicsScene(parent) { }
    /*!
    Уставляет цвет вершины по умолчанию
    \param &color Ссылка на нужный цвет
    */
    void setVertexBrushColor(const QColor &color) {
        vertexPen_.setColor(color);
    }
    /*!
    Уставляет цвет обводки вершнины по умолчанию
    \param &color Ссылка на нужный цвет
    */
    void setVertexPenColor(const QColor &color) {
        vertexBrush_.setColor(color);
    }
    /*!
    Уставляет цвет ребра по умолчанию
    \param &color Ссылка на нужный цвет
    */
    void setEdgeColor(const QColor &color) {
        edgePen_.setColor(color);
    }
    /*!
    Уставляет размер вершнины по умолчанию
    \param &size Ссылка на значение размера
    */
    void setVertexSize(const qreal &size) {
        vertexRect_.setRect(-size / 2, -size / 2, size, size);
    }
    /*!
    Уставляет толщину ребра по умолчанию
    \param &width Ссылка на значение размера
    */
    void setLineWidth(const int &width) {
        vertexPen_.setWidth(width); edgePen_.setWidth(width);
    }
    /*!
    Уставляет режим сцены
    \param mode Необходимый режим
    */
    void setMode(Mode mode) { mode_ = mode; }
    /*!
    Располагает все вершины по кругу
    */
    void replaceAll();
    /*!
    Пытается открыть файл формата .dot
    \param &file ссылка на файл (объект типа QFile)
    \return true, если открытие файла и его парсинг завершается успешно, иначе - false
    */
    bool openGraph(QFile &file);
    /*!
    Пытается сохраняет граф в формате .dot
    \param &path ссылка на строку, содержащую путь к файлу
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
