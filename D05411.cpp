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
	int n;
	BiTNode *lc;
	BiTNode *rc;
}*BiTree;




int compare(KeyType a, KeyType b)
{
	return a - b;
}



void BiTreeInsert(BiTree &T, TElemType data, int compare(KeyType a, KeyType b))
{
	if (T == NULL)
	{
		T = new BiTNode;
		T->lc = T->rc = NULL;
		T->data = data;
		T->n = 1;
		return;
	}
	else if (compare(T->data.key, data.key) == 0)T->n += 1;
	else if (compare(T->data.key, data.key) > 0)BiTreeInsert(T->lc, data, compare);
	else BiTreeInsert(T->rc, data, compare);
}



void BiTCount(BiTree &T, TElemType a[], int n, int compare(KeyType a, KeyType b))
{
	T = NULL;
	int i;
	for (i = 0; i < n; ++i)
	{
		BiTreeInsert(T, a[i], compare);
	}
}


int BiTGetCount(BiTree T, KeyType a, int compare(KeyType a, KeyType b))
{
	if (T == NULL)return 0;
	else if (compare(T->data.key, a) == 0)return T->n;

	else
	{
		int result = BiTGetCount(T->lc, a, compare);
		if (result > 0)return result;
		else return BiTGetCount(T->rc, a, compare);
	}
}


void BiTreeLists(BiTree T, void show(TElemType))
{
	if (T == NULL) {cout << "#"; return;}

	show(T->data);
	if (T->lc || T->rc)
	{
		cout << "(";
		BiTreeLists(T->lc, show);
		cout << ',';
		BiTreeLists(T->rc, show);
		cout << ')';
	}

}
void show(TElemType a)
{
	cout << a.key;
}


void BiTreeDelete(BiTree &T)
{
	if (T == NULL)return;
	BiTreeDelete(T->lc);
	BiTreeDelete(T->rc);
	delete T;
}
int main()
{

	TElemType a[] = {5, 3, 2, 10, 15, 1, 3, 7, 11, 13, 5, 14, 1, 15, 8, 9, 4, 4, 4, 6};
	BiTree T;
	BiTCount(T, a, 20, compare);
	BiTreeLists(T, show);
	int i;
	for (i = 1; i <= 20; ++i)
		cout << i << "     " << BiTGetCount(T, i, compare) << endl;

	BiTreeDelete(T);
	return 0;
}