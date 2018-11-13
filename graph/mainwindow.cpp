#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphscene.h"
#include "edge.h"

#include <Qwidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui_(new Ui::MainWindow) {
    ui_->setupUi(this);
	scene_ = new GraphScene(this);
	ui_->graphicsView->setScene(scene_);
	connect(ui_->pushButtonMove, SIGNAL(released()), this, SLOT(moveClicked()));
	connect(ui_->pushButtonAddVertex, SIGNAL(released()), this, SLOT(addVertexClicked()));
	connect(ui_->pushButtonAddEdge, SIGNAL(released()), this, SLOT(addEdgeClicked()));
	connect(ui_->pushButtonClear, SIGNAL(released()), this, SLOT(clearClicked()));
}

MainWindow::~MainWindow() {
	delete ui_;
}

void MainWindow::moveClicked() {
	scene_->setMode(scene_->MoveVertex);
}

void MainWindow::addVertexClicked() {
	scene_->setMode(scene_->InsertVertex);
}

void MainWindow::addEdgeClicked() {
	scene_->setMode(scene_->InsertEdge);
}

void MainWindow::clearClicked() {
	scene_->clear();
	Vertex::resertCounter();
}

void MainWindow::renameAllClicked() {

}