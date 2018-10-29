#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
	void drawGraph();
    ~MainWindow();

private:
    Ui::MainWindow *ui;

	QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
