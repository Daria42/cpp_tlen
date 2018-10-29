#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

	scene = new QGraphicsScene(this);
	ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::drawGraph() {
	//QGraphicsEllipseItem ellipse;
	QColor vertexMainColor(0, 51, 153);
	QBrush vertexMainBrush(vertexMainColor);
	QPen edgeMainPen(Qt::black, 5);
	double vertexSize(50.0);
	scene->addEllipse(0, 0, vertexSize, vertexSize, QPen(vertexMainColor), vertexMainBrush);
}