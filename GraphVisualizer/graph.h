#ifndef GRAPH_H
#define GRAPH_H

#include <iosfwd>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>

const QColor defaultVertexColor(0, 51, 153);
const QColor defaultEdgeColor = Qt::black;
const double defaultVertexSize = 50.0;

class Graph {
public:
	Graph() = default;
	Graph(size_t size);
	~Graph();
	int verticesCount() { return vertices.size(); }
	int edgesCount() { return edges.size(); }
	void addVertex(double x = 0.0, double y = 0.0, double size = defaultVertexSize, QColor color = defaultVertexColor);
	void addEdge(ptrdiff_t from, ptrdiff_t to, QColor color = defaultEdgeColor);
	bool isVertexValid(ptrdiff_t v) { return (vertices[v].number >= 0); }
	bool isEdgeValid(ptrdiff_t e) { return (edges[e].number >= 0); }
	void deleteEdge(ptrdiff_t e);
	void deleteVertex(ptrdiff_t v);
	void renumber();

private:

	struct Vertex {
		Vertex() = default;
		void connect(ptrdiff_t v, ptrdiff_t e) { links.push_back({ v, e }); }
		int number;
		std::vector < std::pair <ptrdiff_t, ptrdiff_t> > links;
		double x, y;
		QColor color;
		QGraphicsEllipseItem* ellipse;
	};

	struct Edge {
		Edge() = default;
		int number; 
		ptrdiff_t from, to;
		QColor color;
		QGraphicsItem *line;
	};

	std::vector<Vertex> vertices;
	std::vector<Edge> edges;

};

#endif
