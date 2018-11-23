#include <iostream>
using namespace std;
#include "Node.h"


typedef struct ListHead
{
	Node head;
	int length;
} *LinearList;


bool  ListInit(LinearList &L)
{
	L = new ListHead;
	if (L == NULL)return false;
	L->length = 0;
	L->head = new LNode;
	if (L->head == NULL)return false;
	L->head->next = NULL;
	return false;
}

bool ListCreatWithArray(LinearList &L, int n, ElemType *a)
{
	L = new ListHead;
	if (L == NULL)return false;
	L->head = new LNode;
	if (L->head == NULL)return false;

	L->head->next = NULL;

	L->length = n;


	int i;
	Node lnode = L->head;
	for (i = 0; i < n; ++i)
	{
		lnode->next = new LNode;
		if (lnode->next == NULL)return false;

		lnode->next->data = a[i];

		lnode = lnode->next;
	}
	lnode->next = NULL;
	return true;
}

bool ListDestroy(LinearList &L)
{
	Node temp;
	Node lnode = L->head->next;

	while (lnode != NULL)
	{
		temp = lnode;
		lnode = lnode->next;
		delete temp;
	}
	L->head->next = NULL;
	L->length = 0;

	delete L->head;
	delete L;
	return true;

}


bool SubListDestroy(LinearList L, int i)
{
	if (i <= 0 || i > L->length)
	{
		return false;
	}


	Node temp;
	Node lnode = L->head;
	int index;
	//different with listdestroy
	for (index = 1; index < i; ++index)
	{
		lnode = lnode->next;
	}


	Node end = lnode;
	lnode = lnode->next;


	while (lnode != NULL)
	{
		temp = lnode;
		lnode = lnode->next;
		delete temp;
	}

	end->next = NULL;
	L->length = i - 1;
	return true;
}



// void ListClear ();

bool ListEmpty(LinearList L)
{
	return L->head->next == NULL;
}

int ListLength(LinearList L)
{
	return L->length;
}

bool ListGetElem(LinearList L, int index, ElemType &elem)
{
	if (index < 0 || index > L->length)
	{
		return false;
	}
	Node temp = L->head->next;
	int i;
	for (i = 1; i < index; ++i)
	{
		temp = temp->next;
	}
	elem = temp->data;
	return true;
}

int ListLocateElem(LinearList L, ElemType e, int compare(ElemType e1, ElemType e2))
{
	int i = 1;
	Node lnode = L->head->next;
	while (lnode != NULL)
	{
		if (compare(e, lnode->data) == 0)
		{
			return i;
		}
		lnode = lnode->next;
		++i;
	}
	return 0;
}

bool ListInsert(LinearList &L, int i, ElemType e)
{
	if (i <= 0 || i > L->length + 1)
	{
		return false;
	}
	int index;
	Node lnode = L->head;
	for (index = 1; index != i; ++index)
	{
		lnode = lnode->next;
	}

	Node newnode = new LNode;
	if (!newnode)
	{
		return false;
	}

	newnode->next = lnode->next;
	lnode->next = newnode;

	++L->length;


	return true;

}

bool ListPriorElem(LinearList L, ElemType e, ElemType &pre, int compare(ElemType e1, ElemType e2))
{
	Node prenode = L->head;
	Node lnode = L->head->next;
	while (lnode != NULL && compare(e, lnode->data) != 0)
	{
		prenode = lnode;
		lnode = lnode->next;
	}
	if (lnode == NULL || prenode == L->head)
	{
		return false;
	}
	pre = prenode->data;
	return true;
}

bool ListNextElem(LinearList L, ElemType e, ElemType &next, int compare(ElemType e1, ElemType e2))
{

	Node lnode = L->head->next;
	while (lnode != NULL && compare(e, lnode->data) != 0)
	{
		lnode = lnode->next;
	}
	if (lnode->next == NULL)
	{
		return false;
	}
	next = lnode->next->data;
	return true;
}

bool ListDelete(LinearList &L, int i, ElemType &e)
{
	if (i <= 0 || i > L->length)
	{
		return false;
	}
	int index;
	Node lnode = L->head;
	for (index = 1; index != i; ++index)
	{
		lnode = lnode->next;
	}
	Node temp = lnode->next;
	lnode = lnode->next->next;
	delete temp;

	--L->length;


	return true;
}

void ListTraverse(LinearList L, void visit(ElemType e))
{
	Node lnode = L->head->next;
	while (lnode != NULL)
	{
		visit(lnode->data);
		lnode = lnode->next;
	}
}