#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <list>
#include <algorithm>
#include <iostream>
#include "Edge.h"
#include "Vertex.h"

#define FILE "graph.txt"

void addEdge(std::set<Edge*>& edges, Vertex* t, Vertex* h, int weight);
Vertex* addVertex(std::set<Vertex*>& vertices, int id);
void FileReader(std::set<Vertex*>& vertices, std::set<Edge*>& edges);

int main()
{
	std::set<Vertex*> vertices;
	std::set<Edge*> edges;

	FileReader(vertices, edges);

}

void FileReader(std::set<Vertex*>& vertices, std::set<Edge*>& edges) {
	std::ifstream fileStream;
	std::string line;
	int tail, head, weight;
	Vertex *h, *t;

	fileStream.open(FILE);

	if (fileStream.is_open()) {
		while (std::getline(fileStream, line)) {
			std::istringstream ss(line);

			if (!(ss >> tail >> head >> weight)) {
				t = addVertex(vertices, tail);
				h = addVertex(vertices, head);
				addEdge(edges, t, h, weight);
			}
		}
	}
}

void addEdge(std::set<Edge*>& edges, Vertex* t, Vertex* h, int weight) {
	std::pair<std::set<Edge*>::iterator, bool> p;
	Edge* e;

	e = new Edge(t, h, weight);
	p = edges.insert(e);
	if (!p.second) {
		delete e;
	}
}

Vertex* addVertex(std::set<Vertex*>& vertices, int id) {
	std::pair<std::set<Vertex*>::iterator, bool> p;
	Vertex* v;

	v = new Vertex(id);
	p = vertices.insert(v);
	if (!p.second) {
		delete v;
	}
	return *(p.first);
}
