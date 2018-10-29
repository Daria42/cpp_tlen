#include "test.h"
#include "ui_test.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	QObject::connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(FileClickAction()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FileClickAction() {
	std::cout << "Hello" << std::endl;
}
