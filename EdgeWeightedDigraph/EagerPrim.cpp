#include "EagerPrim.h"
#include <iostream>

//Vertex comparator for inTree
inline bool operator==(const Vertex& l, const Vertex& r) { return l.id == r.id; }
//Edge comparator for inTree
inline bool operator==(const Edge& l, const Edge& r) {
	return l.tail == r.tail && l.head == r.head;
}

inline bool EagerPrim::inTree(Vertex* v) { return this->leaves.find(v) != this->leaves.end(); }
inline bool EagerPrim::inTree(Edge* e) { return this->branches.find(e) != this->branches.end(); }

EagerPrim::EagerPrim(Graph* EWG) {
	//initialize data structures
	Vertex *node;
	node = EWG->GetRandomVertex();
	this->EWG = EWG;
	this->leaves = { node };
	this->branches = {};
	this->branchPQ = {};
	this->branchPQ.push({ node, 0.00f });
	
	std::set<Vertex*>* vertices = EWG->GetAllVertices();
	for (auto it = (*vertices).begin(); it != (*vertices).end(); ++it) {
		this->distanceTo.insert({ *it, INFINITY });
	}

	this->distanceTo[node] = 0.0f;

	//visit(branchPQ.top().first);
	//branchPQ.pop();

	while (branchPQ.size() > 0) {
		debug();
		node  = this->branchPQ.top().first;
		this->branchPQ.pop();
		
		visit(node);
	}

	float distance = 0.0f;
	for (auto i = this->distanceTo.begin(); i != this->distanceTo.end(); ++i) {
		std::cout << i->first->id << ", " << i->second << "\n";
		distance += i->second;
	}
	std::cout << distance;

}

void EagerPrim::visit(Vertex* v) {
	Vertex* next;
	std::set<Edge*> edges;

	this->leaves.insert(v);
	edges = EWG->GetEdges(v);

	for (auto e = edges.begin(); e != edges.end(); ++e) {
		if (!this->inTree(*e)) {
			next = (*e)->other(v);
			if (this->distanceTo[next] > (*e)->weight) {
				//shortest edge to node next
				this->branches.insert(*e);
				this->distanceTo[next] = (*e)->weight;
				this->branchPQ.push({ next, (*e)->weight });
			}
		}
	}
}

void EagerPrim::debug() {
	std::cout << "Leaves: ";
	for (auto i = this->leaves.begin(); i != this->leaves.end(); ++i) {
		std::cout << (*i)->id << ", ";
	}
	std::cout << "\n";

	std::cout << "Branches: ";
	for (auto i = this->branches.begin(); i != this->branches.end(); ++i) {
		std::cout << "{" << (*i)->tail->id << ", " << (*i)->head->id << ", " << (*i)->weight << "}, ";
	}
	std::cout << "\n";

	//std::cout << "PQ Top: " << "{" << (this->branchPQ.top())->tail->id << ", " << (this->branchPQ.top())->head->id << ", " << (this->branchPQ.top())->weight << "}, ";
	//std::cout << "\n";
}


bool PQComparator::operator()(weightTo n1, weightTo n2) {
	return n1.second > n2.second;
}