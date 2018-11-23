#include <iostream>
using namespace std;

typedef char TElemType;
typedef struct BiTNode
{
	TElemType data;
	BiTNode *lc;
	BiTNode *rc;
}*BiTree;

void CreateBiTree(BiTree &T, char s[], int &i)
{
	i++;
	if (s[i] == '#')
	{
		T = NULL; return;
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

void visit(char e)
{
	cout << e;
}
bool BiTreeStrict(BiTree T)
{
	if (T == NULL)
	{
		return true;
	}
	if (T->lc == NULL && T->rc == NULL)
	{
		return true;
	}
	if (T->lc != NULL && T->rc != NULL)
	{
		return BiTreeStrict(T->lc) && BiTreeStrict(T->rc);
	}
	return false;
}



int main()
{
	BiTree T1, T2;
	char A[] = "abc###de##f##";
	char B[] = "ab##cdfj##k##g##eh##i##";
	CreateBiTree(T1, A);
	CreateBiTree(T2, B);
	BiTreeLists(T1, visit);
	if (BiTreeStrict(T1))
		cout << "yan ge" << endl;
	else
		cout << " bu yan ge" << endl;
	BiTreeLists(T2, visit);
	if (BiTreeStrict(T2))
		cout << " yan ge" << endl;
	else
		cout << "bu yan ge" << endl;
	return 0;
}