#include "Graph.h"
#include "EagerPrim.h"

#define FILE "tinyEWG.txt"

int main()
{
	Graph* EWG = new Graph(FILE);

	new EagerPrim(*EWG);

	delete EWG;
}




