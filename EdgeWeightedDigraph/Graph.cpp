#include "Graph.h"
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <ctime>
#include <iostream>

inline bool operator==(const Vertex& l, const Vertex& r) { return l.id == r.id; }

Graph::Graph(std::string fileName) {
	this->fileName = fileName;
	FileReader();
	std::cout << "Read " << vertices.size() << " vertices and " << edges.size() << " edges \n";
}

Vertex* Graph::GetRandomVertex() {
	std::set<Vertex*>::iterator v = this->vertices.begin();
	srand(static_cast<unsigned int>(time(0)));
	int random = std::rand() % this->VertexCount();
	std::advance(v, random);
	return *v;
}

std::set<Vertex*>* Graph::GetAllVertices() {
	return &(this->vertices);
}

std::set<Edge*> Graph::GetEdges(Vertex* v) {
	std::set<Edge*> adj;
	std::set<Edge*>::iterator e;

	for (e = this->edges.begin(); e != this->edges.end(); ++e) {
		if ((*e)->tail == v || (*e)->head == v) {
			adj.insert(*e);
		}
	}
	return adj;
}



void Graph::FileReader() {
	std::ifstream fileStream;
	std::string line;
	int tail, head;
	float weight;
	Vertex* h, * t;

	fileStream.open(this->fileName);

	//do not need vertex count or edge count
	std::getline(fileStream, line);
	std::getline(fileStream, line);

	if (fileStream.is_open()) {
		while (std::getline(fileStream, line)) {
			std::istringstream ss(line);

			if (ss >> tail >> head >> weight) {
				t = addVertexToSet(tail);
				h = addVertexToSet(head);
				addEdgeToSet(t, h, weight);
			}
		}
	}
}

void Graph::addEdgeToSet(Vertex* t, Vertex* h, float weight) {
	std::set<Edge*>::iterator e;
	bool in = false;

	for (e = this->edges.begin(); !in && e != this->edges.end(); ++e) {
		in = (*t == *(*e)->tail) && (*h == *(*e)->head);
	}
	if (!in) {
		Edge* edge = new Edge(t, h, weight);
		this->edges.insert(edge);
	}
}

Vertex* Graph::addVertexToSet(int id) {
	std::set<Vertex*>::iterator v;
	bool in = false;

	for (v = this->vertices.begin(); !in && v != this->vertices.end(); ++v) {
		if ((*v)->id == id) {
			return *v;
		}
	}
	Vertex* vert = new Vertex(id);
	this->vertices.insert(vert);
	return vert;
}

int Graph::VertexCount() {
	return this->vertices.size();
}
int Graph::EdgeCount() {
	return this->edges.size();
}