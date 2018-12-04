#include "mainwindow.h"
#include <qapplication>
#include <iostream> //test

int main(int args, char* argv[]) {
    using namespace std;
    QApplication app(args, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
