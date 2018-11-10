#ifndef GRAPH_H
#define GRAPH_H

#include <iosfwd>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>

struct Vertex {
	Vertex() = default;
	Vertex(int number, int type) : number_(number), type_(type) { }
	int number_;
	int type_{ 0 };
	std::vector < std::pair <ptrdiff_t, ptrdiff_t> > links_;
	QGraphicsEllipseItem* ellipse_{ nullptr };
};

struct Edge {
	Edge() = default;
	Edge(int number, ptrdiff_t from, ptrdiff_t to, int type) : number_(number), from_(from), to_(to), type_(type) { }
	int number_;
	int type_{ -1 };
	ptrdiff_t from_, to_;
	QGraphicsLineItem* line_{ nullptr };
};

class Graph {
public:
	Graph() = default;
	Graph(const Graph &) = delete;
	void operator=(const Graph &) = delete;
	Graph(size_t size);
	~Graph() = default;
	int verticesCount();
	int edgesCount();
	int verticesArraySize() { return (int)vertices_.size(); }
	int edgesArraySize() { return (int)edges_.size(); }
	Vertex& getVertex(const ptrdiff_t index);
	Edge& getEdge(const ptrdiff_t index);
	void addVertex(int type = 0);
	void addEdge(ptrdiff_t from, ptrdiff_t to, int type = 0);
	bool isVertexValid(ptrdiff_t v) { return (vertices_[v].type_ >= 0); }
	bool isEdgeValid(ptrdiff_t e) { return (edges_[e].type_ >= 0); }
	//void deleteEdge(ptrdiff_t e);
	//void deleteVertex(ptrdiff_t v);
	//void renumber();

private:
	std::vector<Vertex> vertices_;
	std::vector<Edge> edges_;
};

#endif
