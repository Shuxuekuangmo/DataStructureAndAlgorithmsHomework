#include <iostream>
using namespace std;
typedef char FTElemType;
#include "Trees.h"


// int FTreeDepth(Tree T)
// {
// 	if (T == NULL)return 0;

// 	int maxdepth = 0, temp = 0;
// 	Tree tnode = T;
// 	while (tnode != NULL)
// 	{
// 		temp = FTreeDepth(tnode->firstchild);
// 		if (temp > maxdepth)maxdepth = temp;
// 		tnode = tnode->nextsibling;
// 	}
// 	return maxdepth + 1;
// }

int FTreeDepth(Tree T, int maxdepth = 0)
{
	if (T == NULL)return maxdepth;
	return max(FTreeDepth(T->firstchild, maxdepth + 1), FTreeDepth(T->nextsibling, maxdepth));
}

int main(int argc, char const *argv[])
{
	Tree T;
	char a[] = "ABCF#J###DH#I##EG####";
	char b[] = "#";
	FTreeCreatWithArray(T, a);
	FTreeShowOut(T, visit);
	cout << FTreeDepth(T) << endl;
	return 0;
}

