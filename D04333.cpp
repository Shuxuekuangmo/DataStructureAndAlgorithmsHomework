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

//---------------------------------------------------------

bool same(TElemType a, TElemType b)
{
	return a == b;
}

// void BiTreeFind(BiTree BT, TElemType e, BiTree &P, bool same(TElemType, TElemType))
// {
// 	if (P != NULL)return;

// 	if (BT == NULL)return;
// 	else if (same(e, BT->data))
// 	{
// 		P = BT; return;
// 	}
// 	BiTreeFind(BT->left, e, P, same);
// 	BiTreeFind(BT->right, e, P, same);
// }

// BiTree BiTreeFind(BiTree BT, TElemType e, bool same(TElemType, TElemType))
// {
// 	BiTree result = NULL;
// 	BiTreeFind(BT, e, result, same);
// 	return result;
// }
//
BiTree BiTreeFind(BiTree BT, TElemType e, bool same(TElemType, TElemType))
{

	if (BT == NULL)return NULL;
	if (same(e, BT->data)) return BT;
	BiTree T = BiTreeFind(BT->left, e, same);
	if (T != NULL)return T;
	return BiTreeFind(BT->right, e, same);
}

int BiTreeDepth(BiTree BT)
{
	if (BT == NULL)return 0;;
	int dl, dr;
	dl = BiTreeDepth(BT->left);
	dr = BiTreeDepth(BT->right);
	return dl > dr ? dl + 1 : dr + 1;
}


int BiTreeDepthFind(BiTree BT, TElemType e, bool same(TElemType, TElemType))
{
	return BiTreeDepth(BiTreeFind(BT, e, same));
}

/////find the depth of the element in this tree
// int BiTreeDepthFind(BiTree BT, TElemType e, int depth, bool same(TElemType, TElemType))
// {
// 	int a;
// 	if (BT == NULL)return 0;
// 	else if (same(e, BT->data))return depth;
// 	else
// 	{
// 		a = BiTreeDepthFind(BT->left, e, depth + 1, same);
// 		if (a > 0)return a;
// 		else return BiTreeDepthFind(BT->right, e, depth + 1, same);
// 	}

// }

// int BiTreeDepthFind(BiTree BT, TElemType e, bool same(TElemType, TElemType))
// {
// 	return BiTreeDepthFind(BT, e, 1, same);
// }
int main(int argc, char const *argv[])
{
	char a[] = "ab##cdfj##k##g##eh##i##";
	BiTree BT;

	BiTreeCreatWithCharArray(BT, a);
	BiTreeLists(BT, visit);
	cout << endl << "TEST : " << endl;
	cout << "the depth of \'a\' is  :  " << BiTreeDepthFind(BT, 'a', same) << endl;
	cout << "the depth of \'b\' is  :  " << BiTreeDepthFind(BT, 'b', same) << endl;
	cout << "the depth of \'c\' is  :  " << BiTreeDepthFind(BT, 'c', same) << endl;
	cout << "the depth of \'d\' is  :  " << BiTreeDepthFind(BT, 'd', same) << endl;
	cout << "the depth of \'e\' is  :  " << BiTreeDepthFind(BT, 'e', same) << endl;
	cout << "the depth of \'f\' is  :  " << BiTreeDepthFind(BT, 'f', same) << endl;
	cout << "the depth of \'g\' is  :  " << BiTreeDepthFind(BT, 'g', same) << endl;
	cout << "the depth of \'h\' is  :  " << BiTreeDepthFind(BT, 'h', same) << endl;

	cout << "the depth of \'p\' is  :  " << BiTreeDepthFind(BT, 'p', same) << " , cause \'p\' is not in this tree" << endl;
	return 0;
}







