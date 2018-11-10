#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphscene.h"
#include "edge.h"

#include <Qwidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
	scene = new GraphScene(this);
	ui->graphicsView->setScene(scene);
}

void MainWindow::deleteItem() {
	//foreach(QGraphicsItem *item, scene->selectedItems()) {
	//	if (item->type() == )
	//}
}

void MainWindow::vertexInserted(Vertex *vertex) {

}

MainWindow::~MainWindow() {
    delete ui;
}
