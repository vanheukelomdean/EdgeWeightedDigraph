#pragma once

#include "Vertex.h"
#include <memory>

class Edge
{
	private: 
		Vertex* tail;
		Vertex* head;
		int weight;
public:
	Edge(Vertex* tail, Vertex* head, int weight);
};

