#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <list>
#include <algorithm>
#include <iostream>
#include "Edge.h"
#include "Vertex.h"

#define FILE "tinyEWG.txt"

void addEdge(std::set<Edge*>& edges, Vertex* t, Vertex* h, int weight);
Vertex* addVertex(std::set<Vertex*>& vertices, int id);
void FileReader(std::set<Vertex*>& vertices, std::set<Edge*>& edges);

inline bool operator==(const Vertex& l, const Vertex& r) { return l.id == r.id; }

int main()
{
	std::set<Vertex*> vertices;
	std::set<Edge*> edges;

	FileReader(vertices, edges);

	std::cout << "Read " << vertices.size() << " vertices and " << edges.size() << " edges";
}

void FileReader(std::set<Vertex*>& vertices, std::set<Edge*>& edges) {
	std::ifstream fileStream;
	std::string line;
	int tail, head, weight;
	Vertex *h, *t;

	fileStream.open(FILE);

	//do not need vertex count or edge count
	std::getline(fileStream, line);
	std::getline(fileStream, line);

	if (fileStream.is_open()) {
		while (std::getline(fileStream, line)) {
			std::istringstream ss(line);

			if (ss >> tail >> head >> weight) {
				t = addVertex(vertices, tail);
				h = addVertex(vertices, head);
				addEdge(edges, t, h, weight);
			}
		}
	}
}

void addEdge(std::set<Edge*>& edges, Vertex* t, Vertex* h, int weight) {
	std::set<Edge*>::iterator e;
	bool in = false;

	for (e = edges.begin(); !in && e != edges.end(); ++e) {
		in = (*t == *(*e)->tail) && (*h == *(*e)->head);
	}
	if (!in) {
		Edge* edge = new Edge(t, h, weight);
		edges.insert(edge);
	}
}

Vertex* addVertex(std::set<Vertex*>& vertices, int id) {
	std::set<Vertex*>::iterator v;
	bool in = false;

	for (v = vertices.begin(); !in && v != vertices.end(); ++v) {
		if ((*v)->id == id) {
			return *v;
		}
	}
	Vertex* vert = new Vertex(id);
	vertices.insert(vert);
	return vert;

}


