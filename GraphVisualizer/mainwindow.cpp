#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

const double vertexSize(50.0);
const QColor vertexColor(0, 51, 153);
const QBrush vertexBrush(vertexColor);
const QColor edgeColor(Qt::black);
const QPen edgePen(edgeColor);

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
	scene = new QGraphicsScene(this);
	ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow() {
    delete ui;
	delete scene;
}

void MainWindow::drawVertex(ptrdiff_t index, qreal x, qreal y) {
	Vertex& current = graph->getVertex(index);
	if (current.ellipse_ != nullptr || current.type_ == -1) return;
	current.ellipse_ = scene->addEllipse(-vertexSize / 2, -vertexSize / 2, vertexSize, vertexSize, QPen(vertexColor), vertexBrush);
	current.ellipse_->setPos(x, y);
	current.ellipse_->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::drawEdge(ptrdiff_t index) {
	Edge& current = graph->getEdge(index);
	if (current.line_ != nullptr || current.type_ == -1) return;
	Vertex& from = graph->getVertex(current.from_);
	Vertex& to = graph->getVertex(current.to_);
	qreal x1 = from.ellipse_->x();
	qreal y1 = from.ellipse_->y();
	qreal x2 = to.ellipse_->x();
	qreal y2 = to.ellipse_->y();
	//qreal x1 = 0, y1 = 0, x2 = 100, y2 = 100;
	current.line_ = scene->addLine(x1, y1, x2, y2, edgePen);
}

void MainWindow::drawGraph() {
	scene->clear();
	qreal r = 200.0;
	qreal alpha = asin(1.0) * 4 / graph->verticesCount();
	qreal x0 = -r;
	qreal y0 = 0;
	for (int i = 0; i < graph->verticesArraySize(); i++) {
		qreal xcur = x0 * cos(alpha) - y0 * sin(alpha);
		qreal ycur = x0 * sin(alpha) + y0 * cos(alpha);
		drawVertex(i, xcur, ycur);
		x0 = xcur; y0 = ycur;
	}
	for (int i = 0; i < graph->edgesArraySize(); i++) drawEdge(i);
}