#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphscene.h"
#include "edge.h"

#include <Qwidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QString>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui_(new Ui::MainWindow) {
    ui_->setupUi(this);
    scene_ = new GraphScene(this);
    ui_->graphicsView->setScene(scene_);
    connect(ui_->actionNew, &QAction::triggered, [this](bool checked) { newClicked(); });
    connect(ui_->actionHelp, &QAction::triggered, [this](bool checked) { helpClicked(); });
    connect(ui_->actionOpen, &QAction::triggered, [this](bool checked) { openClicked(); });
    connect(ui_->actionSave, &QAction::triggered, [this](bool checked) { saveClicked(); });
    connect(ui_->actionExit, &QAction::triggered, [this](bool checked) { exitClicked(); });
}

MainWindow::~MainWindow() {
    delete ui_;
}

void MainWindow::newClicked() {
    scene_->clear();
    Vertex::resertCounter();
}

void MainWindow::openClicked() {
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"));
    QFile file(path);
    if (!scene_->openGraph(file))
        QMessageBox::warning(this, "Warning!", "Invalid file or graph description.");
}  // Красивое диалоговое окно для выбора файла

void MainWindow::saveClicked() {

}

void MainWindow::helpClicked() {
    QMessageBox::information(this, "Hotkeys",
        QString("Create new vertex:	Ctrl + mouse click\nCreate edge:		Shift + mouse click\nDelete element:	right button mouse click\nReplace everything:	R"));
}

void MainWindow::exitClicked() {
    exit(0);
}