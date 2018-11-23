#include <iostream>
using namespace std;

// typedef char TElemType;
typedef struct TNode
{
	TElemType data;
	TNode *left;
	TNode *right;
}*BiTree;


// void BiTreeCreatWithCharArray(BiTree &BT, TElemType a[], int &n)
// {
// 	++n;
// 	if (a[n] == '#')
// 	{
// 		BT = NULL; return;
// 	}
// 	BT = new TNode;
// 	BT->data = a[n];
// 	BiTreeCreatWithCharArray(BT->left, a, n);
// 	BiTreeCreatWithCharArray(BT->right, a, n);

// }
// void BiTreeCreatWithCharArray(BiTree &BT, TElemType a[])
// {
// 	int n = -1;
// 	BiTreeCreatWithCharArray(BT, a, n);
// }

void BiTreeLists(BiTree BT, void visit(TElemType))
{
	if (BT == NULL) {cout << "#"; return;}

	visit(BT->data);
	if (BT->left || BT->right)
	{
		cout << "(";
		BiTreeLists(BT->left, visit);
		cout << ',';
		BiTreeLists(BT->right, visit);
		cout << ')';
	}

}



void BiTreePreOrder(BiTree BT, void visit(TElemType))
{
	if (BT == NULL)return ;
	visit(BT->data);
	BiTreePreOrder(BT->left, visit);
	BiTreePreOrder(BT->right, visit);
}
void BiTreeInOrder(BiTree BT, void visit(TElemType))
{
	if (BT == NULL)return ;
	BiTreeInOrder(BT->left, visit);
	visit(BT->data);
	BiTreeInOrder(BT->right, visit);
}
void BiTreePostOrder(BiTree BT, void visit(TElemType))
{
	if (BT == NULL)return ;
	BiTreePostOrder(BT->left, visit);
	BiTreePostOrder(BT->right, visit);
	visit(BT->data);
}

void sub_BiTreeDelete(BiTree BT)
{
	if (BT == NULL)return;
	sub_BiTreeDelete(BT->left);
	sub_BiTreeDelete(BT->right);
	delete BT;
}
void BiTreeDelete(BiTree &BT)
{
	sub_BiTreeDelete(BT);
	BT = NULL;
}