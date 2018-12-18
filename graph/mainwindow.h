#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "vertex.h"
#include <QMainWindow>

class GraphScene;
class QAction;

namespace Ui {
class MainWindow;
}

/*!
\brief Класс, реализующий возможность пользователя работы с графическим интерфейсом программы
Данный класс делает возможным работу с графическими инструментами, сохранение и создание файлов в формате .dot и доступ к справочной информации.
*/
class MainWindow : public QMainWindow {
    Q_OBJECT

 public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

 private slots:
    void newClicked();
    void openClicked();
    void saveClicked();
    void helpClicked();
    void exitClicked();

 private:
    Ui::MainWindow *ui_;
    GraphScene *scene_;
};

#endif  // MAINWINDOW_H
