#pragma once

#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include "GreaterEdgeSpec.cpp"
#include <memory>
#include <set>
#include <queue>
#include <unordered_map>

typedef std::pair<Vertex*, float> weightTo;

class PQComparator
{
public:
	bool operator()(weightTo n1, weightTo n2);
};

class EagerPrim
{
private:
	Graph* EWG;
	std::set<Vertex*> leaves;
	std::set<Edge*> branches;

	std::priority_queue <weightTo, std::vector<weightTo>, PQComparator> branchPQ;
	std::unordered_map<Vertex*, float> distanceTo;

	//Add a node to the MST
	void visit(Vertex* v);

	inline bool inTree(Vertex* v);
	inline bool inTree(Edge* e);

	void debug();
public:
	EagerPrim(Graph* EWG);
};

