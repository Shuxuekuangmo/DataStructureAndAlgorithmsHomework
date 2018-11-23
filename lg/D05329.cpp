#include <iostream>
using namespace std;

typedef char TElemType;
typedef struct BiTNode
{
	TElemType data;
	BiTNode *lc, *rc;
}*BiTree;
void preorder(BiTree T, void visit(TElemType))
{
	if (!T)
	{
		return;
	}
	visit(T->data);
	preorder(T->lc, visit); preorder(T->rc, visit);
}
void BiTreeLists(BiTree T, void visit(TElemType))
{
	if (!T)
	{
		cout << '#';
		return;
	}
	visit(T->data);
	if (T->lc || T->rc)
	{
		cout << '(';
		BiTreeLists(T->lc, visit);
		cout << ',';
		BiTreeLists(T->rc, visit);
		cout << ')';
	}

}
void CreateBiTree(BiTree &T, char s[], int &i)
{
	i++;
	if (s[i] == '#')
	{
		T = NULL;
		return;
	}
	T = new BiTNode;
	T->data = s[i];
	CreateBiTree(T->lc, s, i);
	CreateBiTree(T->rc, s, i);
}
void CreateBiTree(BiTree &T, char s[])
{
	int i = -1;
	CreateBiTree(T, s, i);
}
void find(BiTree &T, int &i, int &j, int &k)
{

	if (!T)
	{
		return;
	}
	if (T->lc && T->rc)
	{
		i++;
	}
	else if (T->lc || T->rc)
	{
		j++;
	}
	else
	{
		k++;
	}
	find(T->lc, i, j, k);
	find(T->rc, i, j, k);
}
void count(BiTree &T, int &i, int &j, int &k)
{
	i = 0;
	j = 0;
	k = 0;
	find (T, i, j, k);
}
void show(char T)
{
	cout << T;
}
int main()
{
	BiTree T;
	char a[] = "abd##eg##h##cf###";
	CreateBiTree(T, a);
	BiTreeLists(T, show);
	int i, j, k;
	count(T, i, j, k);
	cout << endl;
	cout << "shuanghaizijiedianshu " << i << endl;
	cout << "danhaizijiedanshu " << j << endl;
	cout << "yezijiedanshu " << k << endl;
	return 0;
}
