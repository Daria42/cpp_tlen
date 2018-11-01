#include "graph.h"
#include <vector>


Graph::Graph(size_t size) {
	vertices.assign(size, Vertex());
	for (int i = 0; i, size; i++) {
		vertices[i].number = i + 1;
		vertices[i].color = defaultVertexColor;
	}
}

Graph::~Graph() {
	for (int i = 0; i < vertices.size(); i++)
		if (vertices[i].ellipse != nullptr)
			delete vertices[i].ellipse;
	for (int i = 0; i < edges.size(); i++)
		if (edges[i].line != nullptr)
			delete edges[i].line;
}

void Graph::addVertex(double x = 0.0, double y = 0.0, double size = defaultVertexSize, QColor color = defaultVertexColor) {
	vertices.push_back(Vertex());
	vertices.back().number = vertices.size();
	vertices.back().color = color;
	vertices.back().x = x;
	vertices.back().y = y;
}

void Graph::addEdge(ptrdiff_t from, ptrdiff_t to, QColor color) {
	edges.push_back(Edge());
	edges.back().number = edges.size();
	edges.back().from = from;
	edges.back().to = to;
	edges._Copy_alloc = color;
	vertices[from].links.push_back({ to, edges.back().number });
	vertices[to].links.push_back({ from, edges.back().number });
}

void Graph::deleteEdge(ptrdiff_t e) {
	ptrdiff_t from = edges[e].from;
	ptrdiff_t to = edges[e].to;
	std::vector < std::pair <ptrdiff_t, ptrdiff_t> > temp;
	for (int i = 0; i < vertices[from].links.size(); i++) {
		if (vertices[from].links[i].second != e && isVertexValid(vertices[from].links[i].first
			&& isEdgeValid(vertices[from].links[i].second)))
			temp.push_back(vertices[from].links[i]);
	}
	swap(temp, vertices[from].links);
	temp.clear();
	for (int i = 0; i < vertices[to].links.size(); i++) {
		if (vertices[to].links[i].second != e && isVertexValid(vertices[to].links[i].first
			&& isEdgeValid(vertices[to].links[i].second)))
			temp.push_back(vertices[to].links[i]);
	}
	swap(temp, vertices[to].links);
	edges[e].number = -1;
}

void Graph::deleteVertex(ptrdiff_t v) {
	std::vector <ptrdiff_t> edgesForDeleting;
	for (int i = 0; i < vertices[v].links.size(); i++)
		if (vertices[vertices[v].links[i].first].number != -1)
			edgesForDeleting.push_back(vertices[v].links[i].second);
	for (int i = 0; i < edgesForDeleting.size(); i++)
		deleteEdge(edgesForDeleting[i]);
	vertices[v].number = -1;
}

void Graph::renumber() {

}