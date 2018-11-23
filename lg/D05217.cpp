
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
void show(int l)
{
	cout << l << " ";
}
void ListMerge(LinearList &L1, LinearList &L2, LinearList &L3)
{
	ListInit(L3);

	LList p1, p2, p3, temp1, temp2;
	p1 = L1->head->next;
	p2 = L2->head->next;
	p3 = L3->head;
	while (p1 != NULL && p2 != NULL)
	{
		temp1 = p1->next;
		temp2 = p2->next;
		p3->next = p1;
		p3->next->next = p2;
		p3 = p3->next->next;
		p1 = temp1;
		p2 = temp2;
	}
	if (
	    p2 == NULL)
	{

		p3->next = p1;
	}

	L3->length = L1->length + L2->length;
	L3->head->next = L1->head->next;
	L2->length = 0;
	L2->head->next = NULL;
	L1->length = 0;
	L1->head->next = NULL;

}

int main()
{
	int A[] = {1, 2, 3};
	int B[] = {4, 5, 6, 7, 8};

	LinearList L1, L2, L3;
	ListCreat(L1, 3, A);
	ListCreat(L2, 5, B);
	ListMerge(L1, L2, L3);
	ListTraverse(L3, show);
	cout << endl;
	return 0;
}