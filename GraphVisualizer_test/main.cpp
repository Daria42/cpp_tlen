#include "mainwindow.h"
#include "graph.h"
#include <qapplication>
#include <iostream> //test

int main(int args, char* argv[]) {
	using namespace std;
	QApplication app(args, argv);
	MainWindow mainwindow;
	mainwindow.show();
	Graph g(5);
	mainwindow.setGraph(g);
	g.addEdge(0, 1);
	g.addEdge(2, 1);
	mainwindow.drawGraph();
	//g.addVertex();
	//mainwindow.drawVertex(g.verticesArraySize() - 1);
	/*

		�������� ��� ������������ ������� ���� � ������

		������� �������� ������� � ������ ����

		�������� � ��������� �����:
			����� �������
			����� �����
			������� ��������� ������� � �����
			����� �����
			����������������� ���� (������������)
			����������������� ����� (������������)
			����������� ���� ����
			������� �������� ����� �� �������� ����������

		�������������� �����:
			�������� ����� ������� / �����
			������� ������� / �����
			����������� ������� ��� �����
			�������������� �������
			������������� ��� ������� �� ������� �� n
	
	*/

	return app.exec();
}