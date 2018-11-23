
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
		if (lnode == NULL)return false;
		lnode = lnode->next;
		lnode->data = a[i];
	}
	lnode->next = NULL;
	return true;
}


int Compare(int a, int b)
{
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}
void LListAdd(LList &L1, LList &L2, int Compare(ElemType a, ElemType b))
{
	LNode l3;
	LList L3 = &l3;
	L3->next = NULL;



	LList lnode1 = L1->next, lnode2 = L2->next;
	LList prenode;

	delete L2;

	while (lnode1 != NULL && lnode2 != NULL)
	{
		prenode = L3->next;
		if (Compare(lnode1->data, lnode2->data) < 0)
		{
			L3->next = lnode1;
			lnode1 = lnode1->next;
		}
		else
		{
			L3->next = lnode2;
			lnode2 = lnode2->next;
		}
		L3->next->next = prenode;
	}
	if (lnode1 == NULL)
		lnode1 = lnode2;
	while (lnode1 != NULL)
	{
		prenode = L3->next;
		L3->next = lnode1;
		lnode1 = lnode1->next;
		L3->next->next = prenode;
	}
	L1->next = L3->next;
}
void ListTraverse(LList L, void visit(ElemType e))
{

	L = L->next;
	while (L != NULL)
	{
		visit(L->data);
		L = L->next;
	}

}
void show(int l)
{
	cout << l << " ";
}

int main()
{


	int A[] = {1, 2, 3, 4, 5};
	int B[] = {4, 5, 6, 7, 8};

	LList L1, L2;
	ListInit(L1);
	ListInit(L2);
	LListNewArray(L1, 5, A);
	LListNewArray(L2, 5, B);

	LListAdd(L1, L2, Compare);
	ListTraverse(L1, show);
	return 0;
}