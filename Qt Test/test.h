#ifndef TEST_H
#define TEST_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
	void FileClickAction();

private:
    Ui::MainWindow *ui;
};

#endif // TEST_H
