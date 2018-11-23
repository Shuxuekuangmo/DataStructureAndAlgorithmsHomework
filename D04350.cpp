#include <iostream>
using namespace std;

typedef char FTElemType;
#include "Trees.h"

bool FTreeDegreeJudge(Tree T, int k)

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


// int FTreeStatistics(Tree T, int k)
// {
// 	// if (T == NULL)return 0;

// 	Tree tnode = T;
// 	int Num = 0;
// 	while (tnode != NULL)
// 	{
// 		Num += FTreeDegreeJudge(tnode, k) + FTreeStatistics(tnode->firstchild, k);
// 		tnode = tnode->nextsibling;
// 	}
// 	return Num;
// }

int FTreeStatistics(Tree T, int k)
{
	if (T == NULL)return 0;
	return FTreeStatistics(T->firstchild, k) + FTreeStatistics(T->nextsibling, k) + FTreeDegreeJudge(T, k);
}
int main(int argc, char const *argv[])
{
	Tree T;
	char a[] = "ABCF#J###DH#I##EG####";
	char b[] = "#";
	FTreeCreatWithArray(T, a);
	FTreeShowOut(T, visit);
	cout << "number of node degree = 1 : " << FTreeStatistics(T, 1) << endl;
	cout << "number of node degree = 2 : " << FTreeStatistics(T, 2) << endl;
	return 0;
}