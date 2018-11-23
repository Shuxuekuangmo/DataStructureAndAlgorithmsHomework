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

BiTree Find(BiTree T1, TElemType e, bool same(TElemType, TElemType))
{

	if (T1 == NULL)
	{
		return NULL;
	}
	if (same(e, T1->data))
	{
		return T1;
	}



	BiTree  T = Find(T1->lc, e, same);
	if (T != NULL)
	{
		return T;
	}
	return Find(T1->rc, e, same);
}
bool same(char a, char b)
{
	return a == b;
}

int main()
{
	BiTree BT;
	char A[] = "abc###de##f##";
	CreateBiTree(BT, A);
	BiTreeLists(BT, visit);
	cout << endl;

	cout << "'c' address :" << endl;

	BiTree BTNODE = Find(BT, 'c', same) ;
	cout << BTNODE << endl;
	cout << "value is : " << BTNODE->data << endl;

	cout << "if can not find the address is:" << endl;
	cout << Find(BT, 'g', same) << endl;

	return 0;
}