#include <iostream>
#include "Node.h"
using namespace std;




typedef struct CListHead
{
	Node head;
	int length;
} *CLinearList;


CLinearList CListInit()
{
	CLinearList L = new struct CListHead;
	L->length = 0;
	L->head = new LNode;
	L->head->next = L->head;
	return L;
}

bool CListDestroy(CLinearList L)
{
	Node temp;
	Node lnode = L->head->next;

	while (lnode != L->head)
	{
		temp = lnode;
		lnode = lnode->next;
		delete temp;
	}
	L->head->next = L->head;
	L->length = 0;
	return true;

}


bool CSubListDestroy(CLinearList L, int i)
{
	if (i <= 0 || i > L->length)
	{
		return false;
	}


	Node temp;
	Node lnode = L->head;
	int index;
	for (index = 1; index < i; ++index)
	{
		lnode = lnode->next;
	}


	Node end = lnode;
	lnode = lnode->next;


	while (lnode != L->head)
	{
		temp = lnode;
		lnode = lnode->next;
		delete temp;
	}

	end->next = L->head;
	L->length = i - 1;
	return true;
}



// void ListClear ();

bool CListEmpty(CLinearList L)
{
	return L->head->next == L->head;
	//return L->length==0
}

int CListLength(CLinearList L)
{
	return L->length;
}

bool CListGetElem(CLinearList L, int index, ElemType &elem)
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

int CListLocateElem(CLinearList L, ElemType e, int compare(ElemType e1, ElemType e2))
{
	int i = 1;
	Node lnode = L->head->next;
	while (lnode != L->head)
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

bool CListInsert(CLinearList &L, int i, ElemType e)
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

bool CListPriorElem(CLinearList L, ElemType e, ElemType &pre, int compare(ElemType e1, ElemType e2))
{
	Node prenode = L->head;
	Node lnode = L->head->next;
	while (lnode != L->head && compare(e, lnode->data) != 0)
	{
		prenode = lnode;
		lnode = lnode->next;
	}
	if (lnode == L->head || prenode == L->head)
	{
		return false;
	}
	pre = prenode->data;
	return true;
}

bool CListNextElem(CLinearList L, ElemType e, ElemType &next, int compare(ElemType e1, ElemType e2))
{

	Node lnode = L->head->next;
	while (lnode != L->head && compare(e, lnode->data) != 0)
	{
		lnode = lnode->next;
	}
	if (lnode->next == L->head)
	{
		return false;
	}
	next = lnode->next->data;
	return true;
}

bool CListDelete(CLinearList &L, int i, ElemType &e)
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

void CListTraverse(CLinearList L, void visit(ElemType e))
{
	Node lnode = L->head->next;
	while (lnode != L->head)
	{
		visit(lnode->data);
	}
}