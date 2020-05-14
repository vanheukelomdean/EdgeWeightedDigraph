#include "Edge.h"

Edge::Edge(Vertex* tail, Vertex* head, float weight) {
	this->tail = tail;
	this->head = head;
	this->weight = weight;
}
Vertex* Edge::other(Vertex* v) {
	if (this->head == v) {
		return this->tail;
	}
	else {
		return this->head;
	}
}