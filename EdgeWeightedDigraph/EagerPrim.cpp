#include "EagerPrim.h"

EagerPrim::EagerPrim(Graph& EWG) {
	//initialize data structures
	this->leaves = { EWG.GetRandomVertex() };
	this->branches = {};
	this->branchPQ = {};
	
	std::set<Vertex*>* vertices = EWG.GetAllVertices();
	for (auto it = (*vertices).begin(); it != (*vertices).end(); ++it) {
		this->distance.insert({ *it, INFINITY });
	}

	while (branchPQ.size() > 0) {
		//visit();
	}
}
