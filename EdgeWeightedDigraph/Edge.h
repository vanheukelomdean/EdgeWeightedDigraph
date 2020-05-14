#pragma once

#include "Vertex.h"
#include <memory>

class Edge
{
	public:
		Vertex* tail;
		Vertex* head;
		float weight;
		Edge(Vertex* tail, Vertex* head, float weight);
		Vertex* other(Vertex* v);
};

