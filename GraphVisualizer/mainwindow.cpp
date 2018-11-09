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

void MainWindow::drawGraph() {
	scene->clear();
	double r = 200.0;
	double alpha = asin(1.0) * 4 / graph->verticesCount();
	double x0 = -r;
	double y0 = 0;
	for (int i = 0; i < graph->verticesArraySize(); i++) {
		double xcur = x0 * cos(alpha) - y0 * sin(alpha);
		double ycur = x0 * sin(alpha) + y0 * cos(alpha);
		drawVertex(i, xcur, ycur);
		x0 = xcur; y0 = ycur;
	}
	for (int i = 0; i < graph->edgesArraySize(); i++) drawEdge(i);
}

void MainWindow::drawVertex(ptrdiff_t index, double x, double y) {
	Vertex& current = graph->getVertex(index);
	if (current.ellipse_ != nullptr || current.type_ == -1) return;
	current.ellipse_ = scene->addEllipse(x, y, vertexSize, vertexSize, QPen(vertexColor), vertexBrush);
	current.ellipse_->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::drawEdge(ptrdiff_t index) {
	Edge& current = graph->getEdge(index);
	if (current.line_ != nullptr || current.type_ == -1) return;
	Vertex& from = graph->getVertex(current.from_);
	Vertex& to = graph->getVertex(current.to_);
	double x1 = from.ellipse_->x;
	double y1 = from.ellipse_->y;
	double x2 = to.ellipse_->x;
	double y2 = to.ellipse_->y;
	current.line_ = scene->addLine(x1, y1, x2, y2, edgePen);
}