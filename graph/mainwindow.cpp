#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphscene.h"
#include "edge.h"

#include <Qwidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
	scene = new GraphScene(this);
	view = ui->graphicsView;
	view->setScene(scene);
	connect(ui->pushButtonMove, SIGNAL(released()), this, SLOT(moveClicked()));
	connect(ui->pushButtonAddVertex, SIGNAL(released()), this, SLOT(addVertexClicked()));
	connect(ui->pushButtonAddEdge, SIGNAL(released()), this, SLOT(addEdgeClicked()));
	connect(ui->pushButtonClear, SIGNAL(released()), this, SLOT(clearClicked()));
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::moveClicked() {
	scene->setMode(scene->MoveVertex);
}

void MainWindow::addVertexClicked() {
	scene->setMode(scene->InsertVertex);
}

void MainWindow::addEdgeClicked() {
	scene->setMode(scene->InsertEdge);
}

void MainWindow::clearClicked() {

}