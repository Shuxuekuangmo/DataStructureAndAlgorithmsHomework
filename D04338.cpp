#include <iostream>
using namespace std;
typedef char TElemType;
#include "BinaryTree.h"
#include <cstring>

void visit(TElemType e)
{
	cout << e;
}
BiTree BiTreeCreatWithPreAndInOrder(char *PreOrder, char *InOrder, int n)//wit different element in BiTree
{

	if (n <= 0)return NULL;

	BiTree BT = new TNode;
	BT->data = *PreOrder;

	char *middle;
	for (middle = InOrder; middle < InOrder + n; ++middle)
		if (*PreOrder == *middle)break;

	int n1 = middle - InOrder;

	BT->left = BiTreeCreatWithPreAndInOrder(PreOrder + 1, InOrder, n1);
	BT->right = BiTreeCreatWithPreAndInOrder(PreOrder + 1 + n1, middle + 1, n - n1 - 1);

	return BT;

}

void BiTreeCreatWithPreAndInOrder(BiTree &BT, char *PreOrder, char *InOrder)
{
	BT = BiTreeCreatWithPreAndInOrder(PreOrder, InOrder, strlen(PreOrder));
}

void showBT(BiTree BT)
{
	cout << "BTList : " ;
	BiTreeLists(BT, visit);
	cout << endl << "PreOrder : " ;
	BiTreePreOrder(BT, visit);
	cout << endl << "InOrder : " ;
	BiTreeInOrder(BT, visit);
	cout << endl << "PostOrder : ";
	BiTreeInOrder(BT, visit);
	cout << endl;
}
int main(int argc, char const *argv[])
{
	BiTree BT;
	char a[] = "adghimbcelfjk";
	char b[] = "hgdmiaeclbjfk";
	BiTreeCreatWithPreAndInOrder(BT, a, b);
	showBT(BT);

	return 0;
}