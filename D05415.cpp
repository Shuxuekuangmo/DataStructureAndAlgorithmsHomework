#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>


typedef int KeyType;
typedef struct Data
{
	KeyType key;
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
typedef struct LNode
{
	SElemType data;
	LNode *next;

}*Stack;

bool StackInit(Stack &S)
{
	S = new LNode;
	if (!S )return false;
	S->next = NULL;
	return true;
}

bool Push(Stack &S, SElemType e)
{
	Stack tempnode = S->next;
	Stack lnode = new LNode;
	if (lnode == NULL)return false;
	lnode->data = e;
	S->next = lnode;
	lnode->next = tempnode;
	return true;
}
bool Pop(Stack &S, SElemType &e)
{
	if (S->next == NULL)return false;
	e = S->next->data;
	S->next = S->next->next;
	return true;
}



int compare(ElemType a, ElemType b)
{
	return a->key - b->key;
}



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
		while (a < b && compare(L[b], x) >= 0)b--;
		L[a] = L[b];
		while (a < b && compare(L[a], x) <= 0)a++;
		L[b] = L[a];
	}
	L[a] = x;
	return a;
}


void Sort(SList &list, int compare(ElemType a, ElemType b))
{
	Stack S;
	StackInit(S);
	Push(S, {0, list->length - 1});
	SElemType temp;
	while (Pop(S, temp))
	{
		if (temp.tail - temp.head > 8)
		{
			int a = partition(list->data, temp.head, temp.tail, compare);
			if ((a - temp.head) < (temp.tail - a))
			{
				Push(S, {a + 1, temp.tail});
				Push(S, {temp.head, a - 1});
			}
			else
			{
				Push(S, {temp.head, a - 1});
				Push(S, {a + 1, temp.tail});
			}
		}
	}
	InsertSort(list->data, list->length, compare);
}



bool CreatSlist(SList& list, ElemType a, int n)
{
	if (n <= 0)return false;
	int i;
	list->data = new ElemType[n];
	for (i = 0; i < n; i++)
	{
		list->data[i] = a++;
	}
	list->length = n;
	return true;
}

int main()
{
	struct Data a[100];
	srand(time(0));
	int i;
	for (i = 0; i < 100; ++i)a[i] = {(rand() % 100)};

	SList list;
	CreatSlist(list, a, 100);
	Sort(list, compare);
	for (i = 0; i < 100; ++i)
	{
		cout << list->data[i]->key << endl;
	}
	return 0;
}