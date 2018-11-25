#include "graphscene.h"
#include "edge.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QtMath>

void GraphScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    if (mouseEvent->button() == Qt::RightButton) {
        QList<QGraphicsItem *> elements = items(mouseEvent->scenePos());
        if (elements.count() != 0 && elements.first()->type() == Vertex::Type) {
            Vertex *vertex = qgraphicsitem_cast<Vertex *>(elements.first());
            vertex->removeEdges();
            removeItem(vertex);
            delete vertex;
        }
        else if (elements.count() != 0) {
            Edge *edge = qgraphicsitem_cast<Edge *>(elements.first());
            edge->from()->removeEdge(edge);
            edge->to()->removeEdge(edge);
            removeItem(edge);
            delete edge;
        }
    }  // Удаление элементов правой кнопкой мыши
    else if (mouseEvent->button() == Qt::LeftButton) {
        if (mode_ == InsertVertex) {
            Vertex *vertex = new Vertex();
            vertex->setRect(vertexRect_);
            vertex->setBrush(vertexBrush_);
            vertex->setPen(vertexPen_);
            vertex->setPos(mouseEvent->scenePos());
            addItem(vertex);
            emit(vertexInserted(vertex));
        }  // Создание новой вершины
        else if (mode_ == InsertEdge) {
            line_ = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(), mouseEvent->scenePos()));
            line_->setPen(edgePen_);
            line_->setZValue(-100);
            addItem(line_);
        }  // Начало создания нового ребра
        QGraphicsScene::mousePressEvent(mouseEvent);
    }
}

void GraphScene::mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent) {
    if (mouseEvent->button() == Qt::RightButton) return;
    if (mode_ == MoveVertex) QGraphicsScene::mouseMoveEvent(mouseEvent);
    else if (mode_ == InsertEdge && line_ != 0) {
        QLineF movedLine(line_->line().p1(), mouseEvent->scenePos()); //временное изображение ребра
        line_->setLine(movedLine);
    }  // Если начато рисование нового ребра, отображение на экране соответствующей линии
}

void GraphScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    if (mouseEvent->button() == Qt::RightButton) return;
    if (mode_ == InsertEdge && line_ != 0) {
        QList<QGraphicsItem *> from = items(line_->line().p1()); //поиск всех возможных вершин
        if (from.count() && from.first() == line_) from.removeFirst();
        QList<QGraphicsItem *> to = items(line_->line().p2());
        if (to.count() && to.first() == line_) to.removeFirst();
        removeItem(line_);
        delete line_;
        if (from.count() && to.count() && from.first() != to.first() &&
            from.first()->type() == Vertex::Type && to.first()->type() == Vertex::Type) {
            Vertex *first = qgraphicsitem_cast<Vertex *>(from.first());
            Vertex *second = qgraphicsitem_cast<Vertex *>(to.first());
            Edge *edge = new Edge(first, second);
            edge->setPen(edgePen_);
            first->addEdge(edge);
            //second->addEdge(edge);
            addItem(edge);
            edge->updatePos();
        }  // Создание нового ребра, если пользователем выполнены необходимые действия
        line_ = 0;
    }
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void GraphScene::keyPressEvent(QKeyEvent *keyEvent) {
    if (keyEvent->key() == Qt::Key_Control) setMode(InsertVertex);
    if (keyEvent->key() == Qt::Key_Shift) setMode(InsertEdge);
    if (keyEvent->key() == Qt::Key_R) replaceAll();
}

void GraphScene::keyReleaseEvent(QKeyEvent *keyEvent) {
    if (keyEvent->key() == Qt::Key_Control) setMode(MoveVertex);
    if (keyEvent->key() == Qt::Key_Shift) setMode(MoveVertex);
}

QPoint rotate(QPoint &a, qreal &u) {
    return QPoint(a.x() * qCos(u) - a.y() * qSin(u),
        a.x() * qSin(u) + a.y() * qCos(u));
}

void GraphScene::replaceAll() {
    QList<QGraphicsItem *> it = items();
    QList<Vertex *> vertex;
    QPoint center(0, 0);
    for (int i = 0; i < it.size(); i++)
        if (it[i]->type() == Vertex::Type) {
            vertex.push_back(qgraphicsitem_cast<Vertex *>(it[i]));
            center.setX((center.x() + it[i]->x()));
            center.setY((center.y() + it[i]->y()));
        }
    center.setX(center.x() / vertex.size());
    center.setY(center.y() / vertex.size());
    qreal angle = M_PI * 2 / vertex.size();
    QPoint vector(-250, 0);
    for (int i = 0; i < vertex.size(); i++) {
        vertex[i]->setPos(center + vector);
        vector = rotate(vector, angle);
    }
}  // Расположение вершин на сцене
