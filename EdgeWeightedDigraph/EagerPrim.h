#pragma once

#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include <memory>
#include <set>
#include <queue>
#include <unordered_map>

class EagerPrim
{
private:
	std::set<Vertex*>* vertices;
	std::set<Edge*>* edges;
	std::set<Vertex*> leaves;
	std::set<Edge*> branches;
	std::priority_queue<Edge*> branchPQ;
	std::unordered_map<Vertex*, float> distance;

	void visit();
public:
	EagerPrim(Graph& EWG);
};

