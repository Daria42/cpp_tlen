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
	void drawVertex(ptrdiff_t index, double x = 0.0, double y = 0.0);
	void drawEdge(ptrdiff_t index);
	void drawGraph();

private:
    Ui::MainWindow *ui;
	QGraphicsScene *scene;
	Graph *graph{ nullptr };
};

#endif // MAINWINDOW_H
