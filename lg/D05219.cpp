
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	LNode *next;

}*LList;

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

void LListDeleteDouble(LList &L)
{
	LList lnode = L->next;
	LList tempnode;
	while (lnode != NULL && lnode->next != NULL)
	{
		tempnode = lnode->next;
		lnode->next = lnode->next->next;
		delete tempnode;
		lnode = lnode->next;
	}
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
	int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
	LNode l1;
	LList L1 = &l1;
	LListNewArray(L1, 8, A);
	LListDeleteDouble(L1);
	ListTraverse(L1, show);

	return 0;
}