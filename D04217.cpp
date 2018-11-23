#include "LinearList.h"
#include <iostream>
using namespace std;


void print(int i)
{
	cout << i << " ";
}




// void ListMerge(LinearList &L1, LinearList &L2, LinearList &L3)
// {
// 	ListInit(L3);
// 	Node lnode1, lnode2, temp1, temp2, prenode;
// 	lnode1 = L1->head->next;
// 	lnode2 = L2->head->next;
// 	while (lnode1 != NULL && lnode2 != NULL)
// 	{
// 		temp1 = lnode1->next;
// 		temp2 = lnode2->next;

// 		lnode1->next = lnode2;
// 		lnode2->next = temp1;

// 		prenode = lnode1;
// 		lnode1 = temp1;
// 		lnode2 = temp2;
// 	}
// 	if (lnode1 == NULL && lnode2 != NULL)
// 	{
// 		prenode->next = lnode2;
// 	}

// 	L3->length = L1->length + L2->length;
// 	L3->head->next = L1->head->next;


// 	L2->length = 0;
// 	L2->head->next = NULL;
// 	L1->length = 0;
// 	L1->head->next = NULL;

// }


void ListMerge(LinearList &L1, LinearList &L2, LinearList &L3)
{
	ListInit(L3);

	Node lnode1, lnode2, lnode3, temp1, temp2;
	lnode1 = L1->head->next;
	lnode2 = L2->head->next;
	lnode3 = L3->head;
	while (lnode1 != NULL && lnode2 != NULL)
	{
		temp1 = lnode1->next;
		temp2 = lnode2->next;
		lnode3->next = lnode1;
		lnode3->next->next = lnode2;
		lnode3 = lnode3->next->next;

		lnode1 = temp1;
		lnode2 = temp2;
	}

	if (lnode2 == NULL)
	{
		lnode3->next = lnode1;
	}



	L3->length = L1->length + L2->length;
	L3->head->next = L1->head->next;


	L2->length = 0;
	L2->head->next = NULL;
	L1->length = 0;
	L1->head->next = NULL;

}

int main(int argc, char const *argv[])
{
	int a[] = {1, 2, 3};
	int b[] = {4, 5, 6, 7, 8};

	LinearList L1, L2, L3;
	ListCreatWithArray(L1, 3, a);
	ListCreatWithArray(L2, 5, b);
	ListMerge(L1, L2, L3);
	cout << "after change" << endl;
	ListTraverse(L3, print);
	ListDestroy(L1);
	ListDestroy(L2);
	ListDestroy(L3);
	return 0;
}