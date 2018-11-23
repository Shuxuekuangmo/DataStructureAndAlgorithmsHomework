
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	LNode *next;

}*LinearList;
bool ListInit(LinearList &L)
{
	L = new LNode;
	if (L == NULL)return false;
	L->next = NULL;
	return true;
}

bool LinearListCreatWithArray(LinearList &L, int n, ElemType a[])
{
	int i;
	ListInit(L);
	LinearList lnode = L;
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
void LinearListTraverse(LinearList L, void visit(ElemType))
{
	LinearList lnode = L;
	while (lnode->next != NULL)
	{
		visit(lnode->next->data);
		lnode = lnode->next;
	}
	cout << endl;
}
void show(int a)
{
	cout << a << " ";
}



void LinearListResort(LinearList &L)
{
	LinearList lnode = L->next;;

	LinearList templnode1, templnode2;;

	while (lnode != NULL && lnode->next != NULL)
	{
		templnode1 = L->next;
		templnode2 = lnode->next->next;

		L->next = lnode->next;
		L->next->next = templnode1;
		lnode->next = templnode2;
		lnode = lnode->next;

	}
	// lnode->next = NULL;

}

int main(int argc, char const *argv[])
{

	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	LinearList L;
	// ListInit(L);
	LinearListCreatWithArray(L, 8, a);
	LinearListTraverse(L, show);
	LinearListResort(L);
	LinearListTraverse(L, show);

	return 0;
}