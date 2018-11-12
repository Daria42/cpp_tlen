#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "vertex.h"

#include <QMainWindow>

class GraphScene;
class QPushButton;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:   
	void moveClicked();
	void addVertexClicked();
	void addEdgeClicked();
	void clearClicked();

private:
    Ui::MainWindow *ui;
	GraphScene *scene;
	QGraphicsView *view;
};

#endif // MAINWINDOW_H