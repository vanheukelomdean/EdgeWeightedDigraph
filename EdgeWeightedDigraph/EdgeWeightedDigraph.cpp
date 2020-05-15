#include "Graph.h"
#include "EagerPrim.h"

#define FILE "tinyEWG.txt"

int main()
{
	Graph* EWG = new Graph(FILE);

	EagerPrim* EP = new EagerPrim(EWG);

	delete EP;

	delete EWG;
}




