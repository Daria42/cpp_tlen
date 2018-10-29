#include "graph.h"
#include <vector>

//Graph::~Graph() {
//	for (int i = 0; i < edges.size(); i++) {
//		Edge* old = edges[i];
//		edges[i] = nullptr;
//		delete old;
//	}
//	for (int i = 0; i < vertices.size(); i++) {
//		Vertex* old = vertices[i];
//		vertices[i] = nullptr;
//		delete old;
//	}
//}

Graph::Graph(size_t size) {
	vertices.assign(size, Vertex());
	for (int i = 0; i, size; i++) {
		vertices[i].number = i + 1;
		vertices[i].color = vertexColor;
		vertices[i].size = vertexSize;
	}
}

Graph::Graph(Graph &args) {
	vertices = args.vertices;
	edges = args.edges;
}

void Graph::addVertex(QColor color, double size) {
	vertices.push_back(Vertex());
	vertices.back().number = vertices.size();
	vertices.back().color = color;
	vertices.back().size = size;
}

void Graph::addEdge(ptrdiff_t from, ptrdiff_t to, QColor color) {
	edges.push_back(Edge(from, to, color));
	edges.back().number = edges.size();
	
}