
#include <iostream>
using namespace std;


typedef int KeyType;

typedef struct
{
	KeyType key;
} TElemType;
typedef struct TNode
{
	TElemType data;
	TNode *lc;
	TNode *rc;
}*BiTree;

void BiTreeLists(BiTree T, void visit(TElemType))
{
	if (T == NULL) {cout << "#"; return;}

	visit(T->data);
	if (T->lc || T->rc)
	{
		cout << "(";
		BiTreeLists(T->lc, visit);
		cout << ',';
		BiTreeLists(T->rc, visit);
		cout << ')';
	}

}


void CreatBiTree(BiTree &T, TElemType a[], int &i)
{
	i++;
	if (a[i].key < 0)
	{
		T = NULL; return;
	}
	T = new TNode;
	T->data = a[i];
	CreatBiTree(T->lc, a, i);
	CreatBiTree(T->rc, a, i);

}
void CreatBiTree(BiTree &T, TElemType a[])
{
	int i = -1;
	CreatBiTree(T, a, i);
}







int compare(KeyType a, KeyType b)
{
	return a - b;
}
bool judge(BiTree &T, BiTree &pre, int compare(KeyType a, KeyType b))
{
	if (!T)
	{
		return true;
	}
	if (!judge(T->lc, pre, compare))
	{
		return false;
	}
	if (pre && pre->data.key >= T->data.key)
	{
		return false;
	}
	pre = T;
	return judge(T->rc, pre, compare);
}
bool judge(BiTree &T, int compare(KeyType a, KeyType b))
{
	BiTree pre = NULL;
	return judge(T, pre, compare);

}


void show(TElemType a)
{
	cout << a.key;
}
int main()
{

	BiTree BT;

	TElemType a[] = {7, 3, 1, -1, -1, 5, 4, -1, -1, -1, 11, 9, -1, 10, -1, -1, 13, -1, -1};
	CreatBiTree(BT, a);
	BiTreeLists(BT, show);
	cout << endl << judge(BT, compare) << endl;


	BiTree BT1;
	TElemType b[] = {6, 5, 4, -1, -1, 8, -1, -1, 7, -1, 9, 8, -1, -1, 10, -1, -1};
	CreatBiTree(BT1, b);
	BiTreeLists(BT1, show);
	cout << endl << judge(BT1, compare) << endl;

	BiTree BT2;
	TElemType c[] = {6, -1, 7, -1, 9, 5, -1, -1, 10, -1, -1};
	CreatBiTree(BT2, c);
	BiTreeLists(BT2, show);
	cout << endl << judge(BT2, compare) << endl;

	return 0;
}