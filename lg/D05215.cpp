
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
/*
int length(LList L)
{
	LList p;
	int i;
	for (i = 0; p = L->next; i++)
	{
		p = p->next;
	}
	return i;
}
*/
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

void show(int l)
{
	cout << l << " ";
}

void exchange(LinearList &L)
{
	LinearList L0;
	ListInit(L0);


	LList temp;
	while (L->head->next != NULL)
	{
		temp = L0->head->next;
		L0->head->next = L->head->next;
		L->head->next = L->head->next->next;
		L0->head->next->next = temp;
	}

	L->head->next = L0->head->next;
	L0->head->next = NULL;
	ListDestroy(L0);

}
int main()
{

	LinearList L;
	int A[] = {1, 2, 3, 4, 5};
	ListCreat(L, 5, A);
	cout << "A[";
	ListTraverse(L, show);
	cout << "]" << endl;
	exchange(L);
	cout << "A'[";
	ListTraverse(L, show);
	cout << "]" << endl;
	return 0;
}