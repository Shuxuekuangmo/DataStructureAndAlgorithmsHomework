#include <iostream>
using namespace std;


typedef char TElemType;
typedef struct BiTNode
{
	TElemType data;
	BiTNode *lc;
	BiTNode *rc;
}*BiTree;

void BiTreeLists(BiTree T, void visit(TElemType))
{
	if (!T) {cout << "#"; return;}

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

void CreateBiTreeGeneralTable(BiTree &T, char *a)
{
	if (*a == '#')
	{
		T = NULL;
		return;
	}

	T = new BiTNode;
	T->data = *a;
	if (*(a + 1) == '(')
	{
		CreateBiTreeGeneralTable(T->lc, (a + 2));


		int comma = 0;
		int brackets = 0;
		char *b = (a + 2);
		while (brackets != 0 || comma != 1)
		{

			if (*b == '(')brackets += 1;
			else if (*b == ')')brackets -= 1;
			else if (*b == ',' && brackets == 0)comma = 1;
			b = b + 1;

		}
		CreateBiTreeGeneralTable(T->rc, b);
	}
	else
	{
		T->lc = NULL;
		T->rc = NULL;
	}
}

int main()
{

	BiTree T;
	char d[] = "a(d(g(H,#),i(m,#)),b(c(e,l),f(j,k)))";
	CreateBiTreeGeneralTable(T, d);
	BiTreeLists(T, visit);
	return 0;
}