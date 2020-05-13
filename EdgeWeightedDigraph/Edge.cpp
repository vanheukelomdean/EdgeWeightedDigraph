#include "Edge.h"

Edge::Edge(Vertex* tail, Vertex* head, int weight) {
	this->tail = tail;
	this->head = head;
	this->weight = weight;
}
