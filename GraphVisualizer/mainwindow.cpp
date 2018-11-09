#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

const QColor vertexColor(0, 51, 153);
const QBrush vertexBrush(vertexColor);

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
	double vertexSize(50.0);
	double r = 200.0;
	double alpha = asin(1.0) * 4 / graph->verticesCount();
	double x0 = -r;
	double y0 = 0;
	for (int i = 0; i < graph->verticesArraySize(); i++) {
		double xcur = x0 * cos(alpha) - y0 * sin(alpha);
		double ycur = x0 * sin(alpha) + y0 * cos(alpha);
		Vertex& current = graph->getVertex(i);
		if (current.type_ == -1) continue;
		current.ellipse_ = scene->addEllipse(xcur, ycur, vertexSize, vertexSize, QPen(vertexColor), vertexBrush);
		current.ellipse_->setFlag(QGraphicsItem::ItemIsMovable);
		x0 = xcur; y0 = ycur;
	}
}

void MainWindow::drawVertex(ptrdiff_t index) {
	Vertex& current = graph->getVertex(index);
	if (current.ellipse_ != nullptr) return;
	double vertexSize(50.0);
	if (current.type_ != -1) {
		current.ellipse_ = scene->addEllipse(0.0, 0.0, vertexSize, vertexSize, QPen(vertexColor), vertexBrush);
		current.ellipse_->setFlag(QGraphicsItem::ItemIsMovable);
	}
}