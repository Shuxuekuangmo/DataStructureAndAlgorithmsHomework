#include <iostream>
#include <cmath>
using namespace std;

typedef char FTElemType;
#include "Trees.h"


int degreeOfTreeNode(Tree T)
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

int degreeOfTree(Tree T, int maxdegree = 0)
{
	if (T == NULL)return maxdegree;
	return degreeOfTree(T->firstchild, max(maxdegree, max(degreeOfTreeNode(T), degreeOfTree(T->nextsibling, maxdegree))));
}


int main(int argc, char const *argv[])
{
	Tree T;
	char a[] = "ABCF#J###DH#I##EG####";
	char b[] = "#";
	FTreeCreatWithArray(T, a);
	FTreeShowOut(T, visit);

	cout << degreeOfTree(T) << endl;
	return 0;
}

