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


// void BiTreeFind(BiTree BT, TElemType e, BiTree &P, bool same(TElemType, TElemType))
// {
// 	if (P != NULL)return;

// 	if (BT == NULL)return;
// 	else if (same(e, BT->data))
// 	{
// 		P = BT; return;
// 	}
// 	cout << BT->data << endl;
// 	BiTreeFind(BT->left, e, P, same);
// 	BiTreeFind(BT->right, e, P, same);
// }

// BiTree BiTreeFind(BiTree BT, TElemType e, bool same(TElemType, TElemType))
// {
// 	BiTree result = NULL;
// 	BiTreeFind(BT, e, result, same);
// 	return result;
// }
BiTree BiTreeFind(BiTree BT, TElemType e, bool same(TElemType, TElemType))
{

	if (BT == NULL)return NULL;
	if (same(e, BT->data)) return BT;
	BiTree  T = BiTreeFind(BT->left, e, same);
	if (T != NULL)return T;
	return BiTreeFind(BT->right, e, same);
}
bool same(TElemType a, TElemType b)
{
	return a == b;
}

int main(int argc, char const *argv[])
{
	BiTree BT;
	char a[] = "abc###de##f##";
	BiTreeCreatWithCharArray(BT, a);
	BiTreeLists(BT, visit);
	cout << endl;

	cout << "find \'c\' in this BiTree,the address is:" << endl;

	BiTree BTNODE = BiTreeFind(BT, 'c', same) ;
	cout << BTNODE << endl;
	cout << "try to access it : " << endl;
	cout << "value is : " << BTNODE->data << endl;

	cout << "now try to find something not in the BiTree,the address is:" << endl;
	cout << BiTreeFind(BT, 'z', same) << endl;

	return 0;
}