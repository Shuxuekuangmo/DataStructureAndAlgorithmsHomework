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

void show(char T)
{
	cout << T;
}
void DeleteBiTree(BiTree &T)
{
	if (!T)
	{
		return;
	}
	DeleteBiTree(T->lc);
	DeleteBiTree(T->rc);
	delete T;
}
void Deletex(BiTree &T, TElemType x)
{
	if (!T)
	{
		return;
	}
	if (x == T->data)
	{
		DeleteBiTree(T);
		T = NULL;
	}
	else
	{
		Deletex(T->lc, x);
		Deletex(T->rc, x);
	}
}


int main()
{
	BiTree T;
	char a[] = "ABXE##F##D##CXH##X##G##";
	CreateBiTree(T, a);
	BiTreeLists(T, show);
	cout << endl;
	Deletex(T, 'X');
	BiTreeLists(T, show);
	cout << endl;
	return 0;
}
