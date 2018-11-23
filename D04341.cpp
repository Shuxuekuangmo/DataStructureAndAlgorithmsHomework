#include <iostream>
using namespace std;
typedef char TElemType;

#include "BinaryTree.h"
void visit(TElemType e)
{
	cout << e;
}
void BiTreeCreatWithGeneralTable(BiTree &BT, char *a)
{
	if (*a == '#')
	{
		BT = NULL;
		return;
	}

	BT = new TNode;
	BT->data = *a;
	if (*(a + 1) == '(')
	{
		BiTreeCreatWithGeneralTable(BT->left, (a + 2));


		int comma = 0;
		int brackets = 0;
		char *b = (a + 2);
		while (brackets != 0 || comma != 1)
		{

			switch (*b)
			{

			case '(': brackets += 1; break;
			case ')': brackets -= 1; break;
			case ',':
				if (brackets == 0)comma = 1;
				break;
			}
			b = b + 1;

		}
		BiTreeCreatWithGeneralTable(BT->right, b);
	}
	else
	{
		BT->left = NULL;
		BT->right = NULL;
	}
}

int main(int argc, char const *argv[])
{

	BiTree BT;
	char a[] = "a(e,b(c,d))";
	char b[] = "a(e(f,g(h,#)),b(c,d))";
	char c[] = "#";
	char d[] = "a(d(g(H,#),i(m,#)),b(c(e,l),f(j,k)))";
	char e[] = "a";
	BiTreeCreatWithGeneralTable(BT, d);
	BiTreeLists(BT, visit);
	return 0;
}