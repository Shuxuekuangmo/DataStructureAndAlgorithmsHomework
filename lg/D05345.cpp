#include <iostream>
using namespace std;


typedef char FTElemType;
#include "Trees.h"
typedef Tree ElemType;
#include "LQueue.h"

void sequanceTrvalOfForest(Forest F, void visit(FTElemType a))
{
	LQueue LQ;
	LQueueInit(LQ);

	Tree tnode = F;
	while (tnode != NULL)
	{
		EnLQueue(LQ, tnode);
		tnode = tnode->nextsibling;
	}

	Tree node;
	while (DeLQueue(LQ, node))
	{
		visit(node->data);
		node = node->firstchild;
		while (node != NULL)
		{
			EnLQueue(LQ, node);
			node = node->nextsibling;
		}
	}
}
int main(int argc, char const *argv[])
{
	Forest F;
	char a[] = "ABCF#J###DH#I##EG###O##";
	char b[] = "#";
	FTreeCreatWithArray(F, a);
	FTreeShowOut(F, visit);
	sequanceTrvalOfForest(F, visit);
	return 0;
}