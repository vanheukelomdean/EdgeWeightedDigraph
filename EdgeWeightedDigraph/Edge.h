#pragma once

#include "Vertex.h"
#include <memory>

class Edge
{
	public:
		Vertex* tail;
		Vertex* head;
		int weight;
		Edge(Vertex* tail, Vertex* head, int weight);
};

