#include <iostream>
using namespace std;
#include <cstring>


typedef char TElemType;
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
void visit(TElemType a)
{
	cout << a;
}

void BiTreePreOrder(BiTree T, void visit(TElemType))
{
	if (T == NULL)return ;
	visit(T->data);
	BiTreePreOrder(T->lc, visit);
	BiTreePreOrder(T->rc, visit);
}
void BiTreeInOrder(BiTree T, void visit(TElemType))
{
	if (T == NULL)return ;
	BiTreeInOrder(T->lc, visit);
	visit(T->data);
	BiTreeInOrder(T->rc, visit);
}

BiTree CreateBiTreePreAndInOrder(char *p, char *i, int n)
{

	if (n <= 0)
	{
		return NULL;
	}
	BiTree T = new BiTNode;
	T->data = *p;

	char *middle;
	for (middle = i; middle < i + n; ++middle)
		if (*p == *middle)break;

	int n1 = middle - i;

	T->lc = CreateBiTreePreAndInOrder(p + 1, i, n1);
	T->rc = CreateBiTreePreAndInOrder(p + 1 + n1, middle + 1, n - n1 - 1);

	return T;

}

void CreateBiTreePreAndInOrder(BiTree &T, char *p, char *i)
{
	T = CreateBiTreePreAndInOrder(p, i, strlen(p));
}

void show(BiTree T)
{
	BiTreeLists(T, visit);
	cout << endl << "xianxu: " ;
	BiTreePreOrder(T, visit);
	cout << endl << "zhongxu : " ;
	BiTreeInOrder(T, visit);
	cout << endl;
}
int main()
{
	BiTree T;
	char a[] = "adghimbcelfjk";
	char b[] = "hgdmiaeclbjfk";
	CreateBiTreePreAndInOrder(T, a, b);
	show(T);

	return 0;
}