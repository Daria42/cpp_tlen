//#include "GraphVisualizer.h"
//#include "GraphVisualizer.cpp"
//#include <iostream>
//#include <sstream>
#include <qapplication>
#include "test.h"

int main(int args, char* argv[]) {
	using namespace std;
	QApplication app(args, argv);
	MainWindow mainwindow;
	mainwindow.show();
	return app.exec();
}