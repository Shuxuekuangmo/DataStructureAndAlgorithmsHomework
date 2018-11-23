#include <iostream>
#include <cmath>
using namespace std;

typedef char FTElemType;
#include "Trees.h"

// figure the degree of node
int TreeNodeDegree(Tree T)
{
	if (T == NULL)return 0;
	int degree = 0;
	Tree tnode = T->firstchild;
	while (tnode != NULL)
	{
		degree += 1;
		tnode = tnode->nextsibling;
	}
	return degree;
}

// figure the degree of tree

// int FTreeDegree(Tree T)
// {
// 	// if (T == NULL)return 0;
// 	int maxdegree = 0;
// 	Tree tnode = T;
// 	int degree;
// 	while (tnode != NULL)
// 	{
// 		degree = max(FTreeDegree(tnode->firstchild), TreeNodeDegree(tnode));
// 		if (degree > maxdegree)maxdegree = degree;
// 		tnode = tnode->nextsibling;
// 	}
// 	return maxdegree;
// }

int FTreeDegree(Tree T, int maxdegree = 0)
{
	if (T == NULL)return maxdegree;
	return FTreeDegree(T->firstchild, max(maxdegree, max(TreeNodeDegree(T), FTreeDegree(T->nextsibling, maxdegree))));
}


int main(int argc, char const *argv[])
{
	Tree T;
	char a[] = "ABCF#J###DH#I##EG####";
	char b[] = "#";
	FTreeCreatWithArray(T, a);
	FTreeShowOut(T, visit);

	cout << FTreeDegree(T) << endl;
	return 0;
}

