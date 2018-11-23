
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	LNode *next;

}*LList;
bool ListInit(LList &L)
{
	L = new LNode;
	if (L == NULL)return false;
	L->next = NULL;
	return true;
}
bool LListNewArray(LList &L, int n, ElemType a[])
{
	int i;
	LList lnode = L;
	for (i = 0; i < n; ++i)
	{
		lnode->next = new LNode;
		if (lnode == NULL)
		{
			return false;
		}
		lnode = lnode->next;
		lnode->data = a[i];
	}
	lnode->next = NULL;
	return true;
}


void LListSplit(LList &L1, LList &L2)
{
	LList lnode = L1->next;
	ListInit(L2);
	LList tempnode, lnode2 = L2;
	while (lnode != NULL && lnode->next != NULL)
	{
		tempnode = lnode->next;
		lnode->next = lnode->next->next;
		lnode = lnode->next;

		lnode2->next = tempnode;
		lnode2 = lnode2->next;
	}

	lnode2->next = NULL;
}
void ListTraverse(LList L, void visit(ElemType e))
{
	LList p = L->next;
	while (p != NULL)
	{
		visit(p->data);
		p = p->next;
	}

}
void show(int l)
{
	cout << l << " ";
}
int main()
{
	int A[] = {1, 2, 3, 4, 5, 6, 7};

	LList L1, L2;

	ListInit(L1);


	LListNewArray(L1, 7, A);
	LListSplit(L1, L2);

	cout << "A "  ;
	ListTraverse(L1, show);
	cout << endl;

	cout << "B " ;
	ListTraverse(L2, show);


	return 0;
}