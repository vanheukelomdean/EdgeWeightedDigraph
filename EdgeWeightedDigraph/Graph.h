#pragma once
#include <set>
#include <string>
#include "Vertex.h"
#include "Edge.h"

class Graph
{
public:
	Graph(std::string fileName);
	
	//Get pointer to graph's vertice list
	std::set<Vertex*>* GetAllVertices();

	//Get pointer to a vertex in graph
	Vertex* GetRandomVertex();

	//get set of pointers to edges that are adjacent to passed vertex
	std::set<Edge*> GetEdges(Vertex*);

	int VertexCount();
	int EdgeCount();

private:
	std::string fileName;
	std::set<Vertex*> vertices;
	std::set<Edge*> edges;

	//initialize graph components from text file
	void FileReader();

	//manage memory correctly with edge set
	void addEdgeToSet(Vertex* t, Vertex* h, float weight);

	//manage memory correctly with vertice set
	Vertex* addVertexToSet(int id);


};

