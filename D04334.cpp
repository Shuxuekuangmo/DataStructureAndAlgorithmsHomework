#include <iostream>
using namespace std;
#include "BinaryTree.h"

void BiTreeFindAndDelete(BiTree &BT, TElemType e, bool same(TElemType, TElemType))
{

	if (BT == NULL)return;
	if (same(e, BT->data))
	{
		BiTreeDelete(BT);
		BT = NULL;
		return;
	}
	BiTreeFindAndDelete(BT->left, e, same);
	BiTreeFindAndDelete(BT->right, e, same);
}
bool same(TElemType a, TElemType b)
{
	return a == b;
}


int main(int argc, char const *argv[])
{
	BiTree BT;
	char a[] = "abxe##f##d##cxh##x##g##";
	BiTreeCreatWithCharArray(BT, a);
	BiTreeLists(BT, visit);
	cout << endl;

	BiTreeFindAndDelete(BT, 'x', same);
	BiTreeLists(BT, visit);
	cout << endl;
	return 0;
}