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

void show(TElemType a)
{
	cout << a.key;
}

void sort(BiTree T, KeyType x, int compare(KeyType a, KeyType b))
{
	if (T == NULL)return;
	if (compare(T->data.key, x) < 0)sort(T->rc, x, compare);
	else
	{
		sort(T->rc, x, compare);
		cout << T->data.key << " ";
		sort(T->lc, x, compare);
	}

}
int main()
{
	BiTree T;
	TElemType a[] = {5, 3, 1, -1, -1, 2, -1, -1, 9, 7, -1, 8, -1, -1, 11, 10, -1, -1, -1};
	CreatBiTree(T, a);
	BiTreeLists(T, show);
	cout << endl;
	sort(T, 4, compare);
	return 0;
}