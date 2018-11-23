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


void SortedBiTreeDeleteNotLessThanX(BiTree &BT, KeyType x, int compare(KeyType a, KeyType b))
{
	if (BT == NULL)return;
	if (compare(BT->data.key, x) >= 0)
	{
		BiTree bt = BT;
		BT = BT->left;
		bt->left = NULL;
		BiTreeDelete(bt);
		SortedBiTreeDeleteNotLessThanX(BT, x, compare);
	} else SortedBiTreeDeleteNotLessThanX(BT->right, x, compare);
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
	// cout<<endl;
	// BiTreeShowNotLessThanX(BT, 5, compare);
	SortedBiTreeDeleteNotLessThanX(BT, 5, compare);
	cout << endl;
	BiTreeLists(BT, show);

	return 0;
}