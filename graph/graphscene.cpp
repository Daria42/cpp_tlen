#include "graphscene.h"
#include "edge.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QtMath>
#include <QTextStream>
#include <map>

void GraphScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    if (mouseEvent->button() == Qt::RightButton) {
        QList<QGraphicsItem *> elements = items(mouseEvent->scenePos());
        if (elements.count() != 0 && elements.first()->type() == Vertex::Type) {
            Vertex *vertex = qgraphicsitem_cast<Vertex *>(elements.first());
            vertex->removeEdges();
            removeItem(vertex);
            delete vertex;
        } else if (elements.count() != 0) {
            Edge *edge = qgraphicsitem_cast<Edge *>(elements.first());
            edge->from()->removeEdge(edge);
            edge->to()->removeEdge(edge);
            removeItem(edge);
            delete edge;
        }
    } else if (mouseEvent->button() == Qt::LeftButton) {
        if (mode_ == InsertVertex) {
            Vertex *vertex = new Vertex();
            vertex->setRect(vertexRect_);
            vertex->setBrush(vertexBrush_);
            vertex->setPen(vertexPen_);
            vertex->setPos(mouseEvent->scenePos());
            addItem(vertex);
            emit(vertexInserted(vertex));
        } else if (mode_ == InsertEdge) {
            line_ = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(),
                mouseEvent->scenePos()));
            line_->setPen(edgePen_);
            line_->setZValue(-100);
            addItem(line_);
        }
        QGraphicsScene::mousePressEvent(mouseEvent);
    }
}

void GraphScene::mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent) {
    if (mouseEvent->button() != Qt::RightButton) {
        if (mode_ == MoveVertex) {
            QGraphicsScene::mouseMoveEvent(mouseEvent);
        } else if (mode_ == InsertEdge && line_ != 0) {
            QLineF movedLine(line_->line().p1(),
                mouseEvent->scenePos());
            line_->setLine(movedLine);
        }
    }
}

void GraphScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    if (mouseEvent->button() != Qt::RightButton) {
        if (mode_ == InsertEdge && line_ != 0) {
            QList<QGraphicsItem *> from = items(line_->line().p1());
            if (from.count() && from.first() == line_) from.removeFirst();
            QList<QGraphicsItem *> to = items(line_->line().p2());
            if (to.count() && to.first() == line_) to.removeFirst();
            removeItem(line_);
            delete line_;
            if (from.count() && to.count() && from.first() != to.first() &&
                from.first()->type() == Vertex::Type &&
                to.first()->type() == Vertex::Type) {
                Vertex *first = qgraphicsitem_cast<Vertex *>(from.first());
                Vertex *second = qgraphicsitem_cast<Vertex *>(to.first());
                Edge *edge = new Edge(first, second);
                edge->setPen(edgePen_);
                first->addEdge(edge);
                second->addEdge(edge);
                addItem(edge);
                edge->updatePos();
            }
            line_ = 0;
        }
        QGraphicsScene::mouseReleaseEvent(mouseEvent);
    }
}

void GraphScene::keyPressEvent(QKeyEvent *keyEvent) {
    if (keyEvent->key() == Qt::Key_Control) { setMode(InsertVertex); }
    if (keyEvent->key() == Qt::Key_Shift) { setMode(InsertEdge); }
    if (keyEvent->key() == Qt::Key_R) { replaceAll(); }
}

void GraphScene::keyReleaseEvent(QKeyEvent *keyEvent) {
    if (keyEvent->key() == Qt::Key_Control || 
        keyEvent->key() == Qt::Key_Shift) { setMode(MoveVertex); }
}

QPoint rotate(QPoint &a, qreal &u) {
    return QPoint(a.x() * qCos(u) - a.y() * qSin(u),
        a.x() * qSin(u) + a.y() * qCos(u));
}

void GraphScene::replaceAll() {
    QList<QGraphicsItem *> it = items();
    QList<Vertex *> vertex;
    QPoint center(0, 0);
    for (int i = 0; i < it.size(); i++) {
        if (it[i]->type() == Vertex::Type) {
            vertex.push_back(qgraphicsitem_cast<Vertex *>(it[i]));
            center.setX((center.x() + it[i]->x()));
            center.setY((center.y() + it[i]->y()));
        }
    }
    center.setX(center.x() / vertex.size());
    center.setY(center.y() / vertex.size());
    qreal angle = M_PI * 2 / vertex.size();
    QPoint vector(-250, 0);
    for (int i = 0; i < vertex.size(); i++) {
        vertex[i]->setPos(center + vector);
        vector = rotate(vector, angle);
    }
}

bool checkFirstString(QString &str) {
    return (str.back() == '{');
}

bool checkLastString(QString &str) {
    return (str == "}");
}

bool addEdge(std::map < QString, QList <QString> > &g, QString &str) {
    QString from = "";
    int i = 0;
    while (i < str.size() && str[i] != '-' && str[i] != ';') {
        from.push_back(str[i]);
        i++;
    }
    if (i == str.size() - 1 && str[i] == ';') {
        g[from];
        return true;
    } else if (i < str.size() - 1 && str[i] == '-' && str[i + 1] == '-') {
        i += 2;
        QString to = "";
        while (i < str.size() && str[i] != ';' && str[i] != '[') {
            to.push_back(str[i]);
            i++;
        }
        if (i == str.size()) { return false; }
        g[from].push_back(to);
        g[to];
        return true;
    } else {
        return false;
    }
}

bool GraphScene::openGraph(QFile &file) {
    QList<QString> list;
    if (!file.open(QIODevice::ReadOnly)) { return false;  }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        line.replace(" ", "");
        list.push_back(line);
    }
    file.close();
    if (list.size() >= 2 && checkFirstString(list[0]) && checkLastString(list.back())) {
        std::map < QString, QList <QString> > g;
        for (int i = 1; i < list.size() - 1; i++) {
            if (!addEdge(g, list[i])) {
                return false;
            }
        }
        std::map <QString, Vertex *> v;
        clear();
        Vertex::resertCounter();
        for (auto it : g) {
            v[it.first] = new Vertex;
            v[it.first]->setRect(vertexRect_);
            v[it.first]->setBrush(vertexBrush_);
            v[it.first]->setPen(vertexPen_);
            v[it.first]->setPos(0, 0);
            addItem(v[it.first]);
            emit(vertexInserted(v[it.first]));
        }
        for (auto it : g) {
            for (auto to : it.second) {
                Edge *edge = new Edge(v[it.first], v[to]);
                edge->setPen(edgePen_);
                v[it.first]->addEdge(edge);
                v[to]->addEdge(edge);
                addItem(edge);
            }
        }
        replaceAll();
        return true;
    }
    return false;
}

void GraphScene::saveGraph(QString &path) {
    QFile file(path);
    if (file.open(QFile::WriteOnly)) {
        QString spaces("    ");
        QString output("graph MyGraph {");
        output.push_back('\n');
        QList<QGraphicsItem *> elements = items();
        for (int i = 0; i < elements.size(); i++) {
            if (elements[i]->type() == Vertex::Type) {
                Vertex *vertex = qgraphicsitem_cast<Vertex *>(elements[i]);
                if (vertex->edgesCount() != 0) { continue; }
                output.push_back(spaces);
                if (vertex->name() == "") {
                    output.push_back("a" + QString::number(vertex->number()));
                } else {
                    output.push_back(vertex->name());
                }
                output.push_back(";\n");
            }
        }
        for (int i = 0; i < elements.size(); i++) {
            if (elements[i]->type() == Edge::Type) {
                Edge *edge = qgraphicsitem_cast<Edge *>(elements[i]);
                output.push_back(spaces);
                Vertex *from = edge->from();
                Vertex *to = edge->to();
                if (from->name() == "") {
                    output.push_back("a" + QString::number(from->number()));
                } else {
                    output.push_back(from->name());
                }
                output.push_back(" -- ");
                if (to->name() == "") {
                    output.push_back("a" + QString::number(to->number()));
                } else {
                    output.push_back(to->name());
                }
                output.push_back(";\n");
            }
        }
        output.push_back("}");
        file.write(output.toLocal8Bit());
        file.close();
    }
}