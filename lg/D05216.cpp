//#include "LinearList.h"
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	LNode *next;
}*LList;

typedef struct ListHead
{
	LList head;
	int length;
} *LinearList;

bool  ListInit(LinearList &L)
{
	L = new ListHead;
	if (L == NULL)
	{
		return false;
	}
	L->length = 0;
	L->head = new LNode;
	if (L->head == NULL)
	{
		return false;
	}
	L->head->next = NULL;
	return false;
}

bool ListCreat(LinearList &L, int n, ElemType a[])
{
	L = new ListHead;
	if (L == NULL)
	{
		return false;
	}
	L->head = new LNode;
	if (L->head == NULL)
	{
		return false;
	}

	L->head->next = NULL;

	L->length = n;


	int i;
	LList p = L->head;
	for (i = 0; i < n; i++)
	{
		p->next = new LNode;
		if (p->next == NULL)
		{
			return false;
		}

		p->next->data = a[i];

		p = p->next;
	}
	p->next = NULL;
	return true;
}

bool ListDestroy(LinearList &L)
{
	LList temp;
	LList p = L->head->next;

	while (p != NULL)
	{
		temp = p;
		p = p->next;
		delete temp;
	}
	L->head->next = NULL;
	L->length = 0;

	delete L->head;
	delete L;
	return true;

}
void ListTraverse(LinearList L, void visit(ElemType e))
{
	LList p = L->head->next;
	while (p != NULL)
	{
		visit(p->data);
		p = p->next;
	}

}


void ListDeleteSame(LinearList &L, int compare(ElemType e1, ElemType e2))
{
	LinearList L0;
	ListInit(L0);

	LList Lnode0 = L->head->next, temp, Lnode1 = L0->head;
	LList tempnode;
	while (Lnode0 != NULL)
	{
		temp = Lnode0->next;

		if (temp == NULL || compare(temp->data, Lnode0->data) != 0)
		{

			Lnode1->next = Lnode0;
			Lnode1 = Lnode1->next;
		}
		else
		{
			delete Lnode0;

		}
		Lnode0 = temp;

	}
	Lnode1->next = NULL;
	L->head->next = L0->head->next;
	L0->head->next = NULL;
	ListDestroy(L0);

}

void show(int l)
{
	cout << l << " ";
}

int compare(int a, int b)
{
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}
int main()
{

	LinearList L;
	int A[] = {1, 1, 2, 3, 3, 4, 4, 4, 5, 6, 6, 7, 8};

	ListCreat(L, 13, A);
	ListTraverse(L, show);
	cout << endl;
	ListDeleteSame(L, compare);

	ListTraverse(L, show);
	cout << endl;
	return 0;
}