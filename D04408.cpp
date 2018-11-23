#include <iostream>
using namespace std;


typedef int KeyType;

typedef struct
{
	KeyType key;
	// int data
} TElemType;
#include "BinaryTree.h"






void BiTreeCreatWithArray(BiTree &BT, TElemType a[], int &n)
{
	++n;
	if (a[n].key < 0)
	{
		BT = NULL; return;
	}
	BT = new TNode;
	BT->data = a[n];
	BiTreeCreatWithArray(BT->left, a, n);
	BiTreeCreatWithArray(BT->right, a, n);

}
void BiTreeCreatWithArray(BiTree &BT, TElemType a[])
{
	int n = -1;
	BiTreeCreatWithArray(BT, a, n);
}


int compare(KeyType a, KeyType b)
{
	return a - b;
}

bool SortedBiTreeJudge(BiTree BT, int compare(KeyType a, KeyType b), BiTree &pre)
{
	return BT == NULL
	       || (SortedBiTreeJudge(BT->left, compare, pre))
	       && (pre == NULL || compare(BT->data.key, pre->data.key) > 0)
	       && (pre = BT,
	           // if (pre != NULL)cout << pre->data << "      " << compare(BT->data, pre->data) << "   " << res << endl,
	           SortedBiTreeJudge(BT->right, compare, pre));
}



bool SortedBiTreeJudge(BiTree BT, int compare(KeyType a, KeyType b))
{
	BiTree pre = NULL;
	return SortedBiTreeJudge(BT, compare, pre);
}


void show(TElemType a)
{
	cout << a.key;
}
int main(int argc, char const *argv[])
{

	BiTree BT;
	// just for convenient
	//
	//
	//
	TElemType a[] = {7, 3, 1, -1, -1, 5, 4, -1, -1, -1, 11, 9, -1, 10, -1, -1, 13, -1, -1};
	BiTreeCreatWithArray(BT, a);
	BiTreeLists(BT, show);
	cout << endl << SortedBiTreeJudge(BT, compare) << endl;


	BiTree BT1;
	TElemType b[] = {6, 5, 4, -1, -1, 8, -1, -1, 7, -1, 9, 8, -1, -1, 10, -1, -1};
	BiTreeCreatWithArray(BT1, b);
	BiTreeLists(BT1, show);
	cout << endl << SortedBiTreeJudge(BT1, compare) << endl;

	BiTree BT2;
	TElemType c[] = {6, -1, 7, -1, 9, 5, -1, -1, 10, -1, -1};
	BiTreeCreatWithArray(BT2, c);
	BiTreeLists(BT2, show);
	cout << endl << SortedBiTreeJudge(BT2, compare) << endl;

	return 0;
}