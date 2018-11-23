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



bool same(char a, char b)
{
	return a == b;
}

BiTree BiTreeFind(BiTree BT, TElemType e, bool same(TElemType, TElemType))
{

	if (BT == NULL)
	{
		return NULL;
	}
	if (same(e, BT->data))
	{
		return BT;
	}
	BiTree T = BiTreeFind(BT->lc, e, same);
	if (T != NULL)
	{
		return T;
	}
	return BiTreeFind(BT->rc, e, same);
}

int BiTreeDepth(BiTree BT)
{
	if (BT == NULL)return 0;;
	int a, b;
	a = BiTreeDepth(BT->lc);
	b = BiTreeDepth(BT->rc);
	return a > b ? a + 1 : b + 1;
}


int BiTreeDepthFind(BiTree BT, TElemType e, bool same(TElemType, TElemType))
{
	return BiTreeDepth(BiTreeFind(BT, e, same));
}


int main()
{
	char a[] = "ab##cdfj##k##g##eh##i##";
	BiTree BT;

	CreateBiTree(BT, a);
	BiTreeLists(BT, visit);
	cout << endl;
	cout << "depth of 'a'  :  " << BiTreeDepthFind(BT, 'a', same) << endl;
	cout << "depth of 'b'  :  " << BiTreeDepthFind(BT, 'b', same) << endl;
	cout << "depth of 'c'  :  " << BiTreeDepthFind(BT, 'c', same) << endl;
	cout << "depth of 'p'  :  " << BiTreeDepthFind(BT, 'p', same) << " , 'p' are not in this tree" << endl;
	return 0;
}







