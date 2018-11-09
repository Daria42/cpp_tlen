#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graph.h"
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
	void setGraph(Graph &g) { graph = &g; };
	void drawGraph();
	void drawVertex(ptrdiff_t index);

private:
    Ui::MainWindow *ui;
	QGraphicsScene *scene;
	Graph *graph{ nullptr };
};

#endif // MAINWINDOW_H
