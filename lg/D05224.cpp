
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

bool LListCreatNew(LList &L, ElemType a[], int n )
{
	int i;
	ListInit(L);
	LList lnode = L;
	for (i = 0; i < n; i++)
	{
		lnode->next = new LNode;
		if (lnode == NULL)return false;
		lnode = lnode->next;
		lnode->data = a[i];
	}
	lnode->next = NULL;
	return true;
}
void LListResort(LList &L)
{
	LList lnode = L->next;

	LList templnode1, templnode2;

	while (lnode != NULL && lnode->next != NULL)
	{
		templnode1 = L->next;
		templnode2 = lnode->next->next;

		L->next = lnode->next;
		L->next->next = templnode1;
		lnode->next = templnode2;
		lnode = lnode->next;
	}
}
void ListTraverse(LList L, void visit(ElemType))
{
	LList lnode = L;
	while (lnode->next != NULL)
	{
		visit(lnode->next->data);
		lnode = lnode->next;
	}
	cout << endl;
}
void show(int l)
{
	cout << l << " ";
}

int main()
{

	int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
	LList L;
	LListCreatNew(L, A, 8);
	ListTraverse(L, show);
	LListResort(L);
	ListTraverse(L, show);

	return 0;
}