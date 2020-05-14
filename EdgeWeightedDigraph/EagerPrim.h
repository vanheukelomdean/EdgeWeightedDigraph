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
	Graph* EWG;
	std::set<Vertex*> leaves;
	std::set<Edge*> branches;
	std::priority_queue <Edge*> branchPQ;
	std::unordered_map<Vertex*, float> distanceTo;

	//Add a node to the MST
	void visit(Vertex* v);

	inline bool inTree(Vertex* v);
	inline bool inTree(Edge* e);

	void debug();
public:
	EagerPrim(Graph* EWG);
};

