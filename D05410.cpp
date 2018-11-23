#include <iostream>
using namespace std;


typedef int KeyType;

typedef struct
{
	KeyType key;
} TElemType;
typedef struct BiTNode
{
	TElemType data;
	BiTNode *lc;
	BiTNode *rc;
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
	T = new BiTNode;
	T->data = a[i];
	CreatBiTree(T->lc, a, i);
	CreatBiTree(T->rc, a, i);

}
void CreatBiTree(BiTree &T, TElemType a[])
{
	int i = -1;
	CreatBiTree(T, a, i);
}


void sub_BiTreeDelete(BiTree T)
{
	if (T == NULL)return;
	sub_BiTreeDelete(T->lc);
	sub_BiTreeDelete(T->rc);
	delete T;
}
void BiTreeDelete(BiTree &T)
{
	sub_BiTreeDelete(T);
	T = NULL;
}

int compare(KeyType a, KeyType b)
{
	return a - b;
}


void Delete(BiTree &T, KeyType x, int compare(KeyType a, KeyType b))
{
	if (T == NULL)return;
	if (compare(T->data.key, x) >= 0)
	{
		BiTree bt = T;
		T = T->lc;
		bt->lc = NULL;
		BiTreeDelete(bt);
		Delete(T, x, compare);
	} else Delete(T->rc, x, compare);
}
void show(TElemType a)
{
	cout << a.key;
}

int main()
{
	BiTree T;

	TElemType a[] = {5, 3, 1, -1, -1, 2, -1, -1, 9, 7, -1, 8, -1, -1, 11, 10, -1, -1, -1};
	CreatBiTree(T, a);
	BiTreeLists(T, show);
	Delete(T, 5, compare);
	cout << endl;
	BiTreeLists(T, show);

	return 0;
}
