#include <iostream>
using namespace std;

typedef char TElemType;
typedef struct TNode
{
	TElemType data;
	TNode *left;
	TNode *right;
}*BiTree;

// bool BiTreeInit(BiTree BT, TElemType e)
// {
// 	BT = new TNode;
// 	if (BT == NULL)return false;
// 	BT->data = e;
// 	BT->left = BT->right = NULL;
// 	return true;
// }
void BiTreeCreatWithCharArray(BiTree &BT, TElemType a[], int &n)
{
	++n;
	if (a[n] == '#')
	{
		BT = NULL; return;
	}
	BT = new TNode;
	BT->data = a[n];
	BiTreeCreatWithCharArray(BT->left, a, n);
	BiTreeCreatWithCharArray(BT->right, a, n);

}
void BiTreeCreatWithCharArray(BiTree &BT, TElemType a[])
{
	int n = -1;
	BiTreeCreatWithCharArray(BT, a, n);
}

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

void visit(TElemType e)
{
	cout << e;
}

void Sub_BiTreeSataistics(BiTree &BT, int &a0, int &a1, int &a2 )
{

	if (BT == NULL)return;

	if (BT->left != NULL && BT->right != NULL)
	{
		++a2;
	}
	else if (BT->left != NULL || BT->right != NULL)
	{
		++a1;
	}
	else
	{
		++a0;
		return;
	}
	Sub_BiTreeSataistics(BT->left, a0, a1, a2);
	Sub_BiTreeSataistics(BT->right, a0, a1, a2);

}
void BiTreeSataistics(BiTree &BT, int &a0, int &a1, int &a2)
{
	a0 = a1 = a2 = 0;
	Sub_BiTreeSataistics(BT, a0, a1, a2);
}


int main(int argc, char const *argv[])
{
	BiTree BT;
	char a[] = "abc###de##f##";
	BiTreeCreatWithCharArray(BT, a);
	BiTreeLists(BT, visit);

	int a0, a1, a2;
	BiTreeSataistics(BT, a0, a1, a2);
	cout << endl << "degree == 0 : " << a0 << endl << "degree == 1 : " << a1 << endl << "degree == 2 : " << a2 << endl;;
	return 0;
}