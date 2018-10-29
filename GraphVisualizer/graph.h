#ifndef GRAPH_H
#define GRAPH_H

#include <iosfwd>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>

const QColor vertexColor(0, 51, 153);
const QColor edgesColor = Qt::black;
const double vertexSize = 50;

class Graph {
public:
	Graph() = default;
	Graph(size_t size);
	Graph(Graph &args);
	~Graph() = default;
	int verticesCount() { return vertices.size(); }
	int edgesCount() { return edges.size(); }
	void addVertex(QColor color, double size);
	void addVertex(QColor color) { addVertex(color, vertexSize); }
	void addVertex(double size = vertexSize) { addVertex(vertexColor, size); }
	void addEdge(ptrdiff_t from, ptrdiff_t to, QColor color = edgesColor);
	//void addVertex(QColor color = Qt::black);
	//void addVertex(Vertex &v);
	//void addEdge(Vertex &v, Vertex &u);
	//void addEdge(const ptrdiff_t i, const ptrdiff_t j);
	//void deleteVertex(Vertex &v);
	//void deleteVertex(int i);
	//void deleteEdge(Edge &e);
	//void deleteEdge(int i);

private:

	struct Vertex {
		Vertex() = default;
		int number;
		std::vector < std::pair <ptrdiff_t, ptrdiff_t> > links;
		QColor color;
		double size;
		void connect(ptrdiff_t v, ptrdiff_t e) { links.push_back({ v, e }); }
	};

	struct Edge {
		Edge(ptrdiff_t from, ptrdiff_t to, QColor color) : from(from), to(to), color(color) { }
		int number;
		ptrdiff_t from, to;
		QColor color;
	};

	std::vector<Vertex> vertices;
	std::vector<Edge> edges;

};

#endif
