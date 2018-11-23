#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>


typedef int KeyType;
typedef struct Data
{
	KeyType key;
	// int other;
	//......
} *ElemType;

typedef struct list
{
	ElemType* data;
	int length;
} *SList;

typedef struct headandtail
{
	int head;
	int tail;
} SElemType;
#include "LStack.h"



int compare(ElemType a, ElemType b) {return a->key - b->key;}



void InsertSort(ElemType* L, int n, int compare(ElemType a, ElemType b))
{
	int i, j; ElemType x;
	for (i = 1; i < n; ++i)
	{
		for (x = L[i], j = i - 1; j >= 0 && compare(x, L[j]) < 0; --j)
			L[j + 1] = L[j];
		L[j + 1] = x;
	}
}

int partition(ElemType * L, int a, int b, int compare(ElemType a, ElemType b))
{
	ElemType x = L[a];
	while (a < b)
	{
		while (a < b && compare(L[b], x) >= 0)--b;
		L[a] = L[b];
		while (a < b && compare(L[a], x) <= 0)++a;
		L[b] = L[a];
	}
	L[a] = x;
	return a;
}


void QuickSort(SList &list, int compare(ElemType a, ElemType b))
{
	LStack LS;
	LStackInit(LS);
	// ElemType *pointer = list->data;
	LStackPush(LS, {0, list->length - 1});
	SElemType temp;
	while (LStackPop(LS, temp))
	{
		if (temp.tail - temp.head > 8)
		{
			int a = partition(list->data, temp.head, temp.tail, compare);
			if ((a - temp.head) < (temp.tail - a))
			{
				LStackPush(LS, {a + 1, temp.tail});
				LStackPush(LS, {temp.head, a - 1});
			}
			else
			{
				LStackPush(LS, {temp.head, a - 1});
				LStackPush(LS, {a + 1, temp.tail});
			}
		}
	}
	InsertSort(list->data, list->length, compare);
}



bool SlistGenerate(SList& list, ElemType a, int n)
{
	if (n <= 0)return false;
	int i;
	list->data = new ElemType[n];
	for (i = 0; i < n; ++i)
	{
		list->data[i] = a++;
	}
	list->length = n;
	return true;
}

int main(int argc, char const *argv[])
{
	struct Data a[100];
	srand(time(0));
	int i;
	for (i = 0; i < 100; ++i)a[i] = {(rand() % 100)};

	SList list;
	SlistGenerate(list, a, 100);
	QuickSort(list, compare);
	for (i = 0; i < 100; ++i)
	{
		cout << list->data[i]->key << endl;
	}
	return 0;
}