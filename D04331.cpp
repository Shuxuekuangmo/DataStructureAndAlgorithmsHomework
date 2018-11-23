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
bool BiTreeStrict(BiTree BT)
{
	if (BT == NULL)return true;
	if (BT->left == NULL && BT->right == NULL)return true;
	if (BT->left != NULL && BT->right != NULL)
	{
		return BiTreeStrict(BT->left) && BiTreeStrict(BT->right);
	}
	return false;
}



int main(int argc, char const *argv[])
{
	BiTree BT1, BT2;
	char a[] = "abc###de##f##";
	char b[] = "ab##cdfj##k##g##eh##i##";
	BiTreeCreatWithCharArray(BT1, a);
	BiTreeCreatWithCharArray(BT2, b);
	BiTreeLists(BT1, visit);
	if (BiTreeStrict(BT1))
		cout << " is strict" << endl;
	else
		cout << " is not strict" << endl;
	BiTreeLists(BT2, visit);
	if (BiTreeStrict(BT2))
		cout << " is strict" << endl;
	else
		cout << " is not strict" << endl;
	return 0;
}