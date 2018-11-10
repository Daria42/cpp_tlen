#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "vertex.h"

#include <QMainWindow>

class GraphScene;

class QAction;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
	void deleteItem();
	void vertexInserted(Vertex *vertex);

private:
    Ui::MainWindow *ui;
	GraphScene *scene;
	QGraphicsView *view;

	QAction *exitAction;
	QAction *addAction;
	QAction *deleteAction;
};

#endif // MAINWINDOW_H
