#include "LinearList.h"
#include <iostream>
using namespace std;



// void ListDeleteSameElem(LinearList &L, int compare(ElemType e1, ElemType e2))
// {
// 	Node lnode = L->head;
// 	ElemType temp;
// 	Node nodetemp;
// 	while (lnode->next != NULL)
// 	{
// 		lnode = lnode->next;
// 		temp = lnode->data;
// 		while (lnode->next != NULL && compare(temp, lnode->next->data) == 0)
// 		{
// 			nodetemp = lnode->next;
// 			lnode->next = lnode->next->next;
// 			delete nodetemp;
// 			--(L->length);
// 		}
// 	}

// }
void ListDeleteSameElem(LinearList &L, int compare(ElemType e1, ElemType e2))
{
	LinearList L0;
	ListInit(L0);

	Node lnode0 = L->head->next, temp, lnode1 = L0->head;
	Node tempnode;
	while (lnode0 != NULL)
	{
		temp = lnode0->next;

		//different element or at the end
		if (temp == NULL || compare(temp->data, lnode0->data) != 0)
		{

			lnode1->next = lnode0;
			lnode1 = lnode1->next;
		}
		else
		{
			delete lnode0;

		}
		lnode0 = temp;

	}
	lnode1->next = NULL;
	L->head->next = L0->head->next;
	L0->head->next = NULL;
	ListDestroy(L0);

}

void print(int i)
{
	cout << i << " ";
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
int main(int argc, char const *argv[])
{


	LinearList L;
	int a[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5};

	ListCreatWithArray(L, 12, a);
	ListTraverse(L, print);
	cout << endl;
	ListDeleteSameElem(L, compare);

	ListTraverse(L, print);
	cout << endl;
	ListDestroy(L);
	return 0;
}