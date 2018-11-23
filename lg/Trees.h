#include <iostream>
using namespace std;


// define FTElemType in the main program


typedef struct FTNode
{
	FTElemType data;
	FTNode *firstchild;
	FTNode *nextsibling;
}*Tree, *Forest;

void FTreeCreatWithArray(Tree &BT, FTElemType a[], int &n)
{
	++n;
	if (a[n] == '#')
	{
		BT = NULL; return;
	}
	BT = new FTNode;
	BT->data = a[n];
	FTreeCreatWithArray(BT->firstchild, a, n);
	FTreeCreatWithArray(BT->nextsibling, a, n);

}
void FTreeCreatWithArray(Tree &BT, FTElemType a[])
{
	int n = -1;
	FTreeCreatWithArray(BT, a, n);
}

void FTreeLists(Tree FT, void visit(FTElemType))
{

	if (FT == NULL)return;
	cout << "(";
	visit(FT->data);
	FTreeLists(FT->firstchild, visit);
	Tree tnode = FT->nextsibling;


	while (tnode != NULL)
	{
		cout << ",";
		visit(tnode->data);
		FTreeLists(tnode->firstchild, visit);
		tnode = tnode->nextsibling;
	}
	cout << ")";
}
void visit(FTElemType a)
{
	cout << a;
}


void FTreeShow(Tree FT, void visit(FTElemType), int n = 0)
{
	if (FT == NULL)return;

	int i;
	Tree tnode = FT;
	while (tnode != NULL)
	{
		cout << endl;
		for (i = 0; i < 4 * n; ++i)	cout << " ";
		visit(tnode->data);
		FTreeShow(tnode->firstchild, visit, n + 1);
		tnode = tnode->nextsibling;
	}
}


void FTreeShowOut(Tree FT, void visit(FTElemType))
{
	cout << "general table style : " << endl;;
	FTreeLists(FT, visit);
	cout << endl << "indentation style: ";
	FTreeShow(FT, visit);
	cout << endl;
}

void FTreeDelete(Tree FT)
{
	if (FT == NULL)return;
	FTreeDelete(FT->firstchild);
	FTreeDelete(FT->nextsibling);
	delete FT;
}