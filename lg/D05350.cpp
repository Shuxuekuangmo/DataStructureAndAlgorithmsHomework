#include <iostream>
using namespace std;

typedef char FTElemType;
#include "Trees.h"

bool degreejudge(Tree T, int k)

{
	if (T == NULL)return 0;

	Tree tnode = T->firstchild;
	int n = 0;
	while (tnode != NULL && n < k + 1)
	{
		tnode = tnode->nextsibling;
		++n;
	}
	return n == k;
}
int statisticsOfTreeNode(Tree T, int k)
{
	if (T == NULL)return 0;
	return statisticsOfTreeNode(T->firstchild, k) + statisticsOfTreeNode(T->nextsibling, k) + degreejudge(T, k);
}
int main(int argc, char const *argv[])
{
	Tree T;
	char a[] = "ABCF#J###DH#I##EG####";
	char b[] = "#";
	FTreeCreatWithArray(T, a);
	FTreeShowOut(T, visit);
	cout << "number of node degree = 1 : " << statisticsOfTreeNode(T, 1) << endl;
	cout << "number of node degree = 2 : " << statisticsOfTreeNode(T, 2) << endl;
	return 0;
}