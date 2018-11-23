#include <iostream>
using namespace std;
typedef char FTElemType;
#include "Trees.h"


int depthOfTree(Tree T, int maxdepth = 0)
{
	if (T == NULL)return maxdepth;
	return max(depthOfTree(T->firstchild, maxdepth + 1), depthOfTree(T->nextsibling, maxdepth));
}

int main(int argc, char const *argv[])
{
	Tree T;
	char a[] = "ABCF#J###DH#I##EG####";
	char b[] = "#";
	FTreeCreatWithArray(T, a);
	FTreeShowOut(T, visit);
	cout << "depth is " << depthOfTree(T) << endl;
	return 0;
}

