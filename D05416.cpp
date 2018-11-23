#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

typedef int KeyType;
typedef struct Data
{
	KeyType key;
	//other data
	//
} *ElemType;

typedef struct list
{
	ElemType* data;
	int length;
} *SList;


int compare(ElemType a, ElemType b)
{
	return a->key - b->key;
}

typedef struct Times
{
	int c;//compare
	int a;//assignment
} times;

// ----------------------------------------------------------------------------------
times InsertSort(SList &list, int compare(ElemType, ElemType))
{
	int i, j; ElemType x;
	int c = 0, a = 0;

	for (i = 1; i < list->length; ++i)
	{
		for (x = list->data[i], a += 1, j = i - 1; c += 1, j >= 0 && compare(x, list->data[j]) < 0; --j)
		{
			list->data[j + 1] = list->data[j];
			a += 1;

		}
		list->data[j + 1] = x;
		a += 1;
	}
	return {c, a};
}
// ----------------------------------------------------------------------------------
times SelectSort(SList &list, int compare(ElemType a, ElemType b))
{
	int c = 0;
	int a = 0;

	int i, j;
	int  mindata;
	ElemType temp;
	for (i = 0; i < list->length; ++i)
	{
		mindata = i;
		for (j = i + 1; j < list->length; ++j)
		{

			if ((c += 1, compare(list->data[mindata], list->data[j]) > 0))
			{
				mindata = j;
			}

		}
		if (mindata > i)
		{
			temp = list->data[i];
			list->data[i] = list->data[mindata];
			list->data[mindata] = temp;
			a += 3;
		}
	}
	return {c, a};
}
// ----------------------------------------------------------------------------------
int partition(ElemType * L, int a, int b, int compare(ElemType a, ElemType b), times &t)
{
	ElemType x = L[a];
	while (a < b)
	{
		while (a < b && (t.c += 1, compare(L[b], x) >= 0))
		{
			b--;
		}
		L[a] = L[b];
		while (a < b && (t.c += 1, compare(L[a], x) <= 0))
		{
			a++;
		}
		L[b] = L[a];
		t.a += 2;

	}
	L[a] = x;
	t.a += 2;
	return a;
}

times QuickSort(SList &list, int a, int b, int compare(ElemType a, ElemType b))
{
	int p;
	times t = {0, 0};
	if (a >= b)return t;
	p = partition(list->data, a, b, compare, t);
	times t1 = QuickSort(list, a, p - 1, compare);
	times t2 = QuickSort(list, p + 1, b, compare);
	return {t.c + t1.c + t2.c, t.a + t1.a + t2.a};
}

times QuickSort(SList &list, int compare(ElemType a, ElemType b))
{
	return QuickSort(list, 0, list->length - 1, compare);
}

// ----------------------------------------------------------------------------------



times HeapAdjust(SList &H, int a, int b, int compare(ElemType a, ElemType b))
{
	times t = {0, 0};

	int minchild;
	ElemType temp;

	temp = H->data[a];
	t.a += 1;

	minchild = 2 * a + 1;

	while (minchild <= b)
	{
		if (minchild < b && (t.c += 1, compare(H->data[minchild], H->data[minchild + 1]) < 0))++minchild;
		if ((t.c += 1, compare(temp, H->data[minchild]) >= 0))break;

		t.a += 1;
		H->data[a] = H->data[minchild];
		a = minchild;
		minchild = 2 * minchild + 1;
	}
	t.a += 1;
	H->data[a] = temp;
	return t;
}

times HeapSort(SList &H, int compare(ElemType a, ElemType b))
{
	times t = {0, 0}, t1;
	int i;
	ElemType temp;
	for (i = H->length / 2 - 1; i >= 0; --i)
	{
		t1 = HeapAdjust(H, i, H->length - 1, compare);
		t.c += t1.c;
		t.a += t1.a;
	}
	for (i = H->length - 1; i >= 1; --i)
	{
		temp = H->data[0];
		H->data[0] = H->data[i];
		H->data[i] = temp;
		t1 = HeapAdjust(H, 0, i - 1, compare);
		t.c += t1.c;
		t.a += t1.a + 3;
	}
	return t;
}
// ----------------------------------------------------------------------------------
times Merge(SList &list, int a, int m, int b, int compare(ElemType a, ElemType b))
{
	times t = {0, 0};
	int i, j, k;
	ElemType *temp;

	temp = new ElemType[m - a + 1];
	for (i = a; i <= m; i++)
	{
		t.a += 1;

		temp[i - a] = list->data[i];
	}
	i = 0;
	k = a - 1;
	j = m + 1;
	while (i <= m - a && j <= b)
	{
		++k;
		if ((t.c += 1, compare(temp[i], list->data[j]) <= 0))
		{
			t.a += 1;
			list->data[k] = temp[i];
			++i;
		}
		else
		{
			t.a += 1;
			list->data[k] = list->data[j];
			++j;
		}
	}
	while (i <= m - a)
	{
		t.a += 1;
		++k;
		list->data[k] = temp[i];
		++i;
	}
	delete []temp;

	return t;
}

times MergeSort(SList &list, int compare(ElemType a, ElemType b))
{
	times t = {0, 0}, t1;

	int a, m, b;
	int i;
	for (i = 1; i < list->length - 1; i *= 2)
	{
		for (a = 0;; a += 2 * i)
		{
			m = a + i - 1;
			if (m >= list->length - 1)break;
			b = m + i;
			if (b > list->length - 1)b = list->length - 1;

			t1 = Merge(list, a, m, b, compare);

			t.c += t1.c;
			t.a += t1.a;

		}
	}
	return t;
}
// ----------------------------------------------------------------------------------
bool CreatSList(SList &list, ElemType a, int n)
{
	list = new struct list;
	list->length = n;
	int i;
	list->data = new ElemType[n];
	for (i = 0; i < n; i++)
	{
		list->data[i] = a++;
	}
	return true;
}

int main()
{


	int n = 5;
	ElemType datas = new struct Data[1000];
	srand(time(0));
	int i;
	for (i = 0; i < 1000; i++)
	{
		datas[i] = {(rand() % 1000)};
	}

	int time;
	for (time = 1; time <= n; ++time)
	{
		cout << " time " << time << endl;

		times t[5];
		SList list[5];

		cout << " METHOD" << "        C TIME    " << "A TIME" << endl;
		CreatSList(list[0], datas, 1000);
		CreatSList(list[1], datas, 1000);
		CreatSList(list[2], datas, 1000);
		CreatSList(list[3], datas, 1000);
		CreatSList(list[4], datas, 1000);
		t[0] = InsertSort(list[0], compare);
		t[1] = SelectSort(list[1], compare);
		t[2] = QuickSort(list[2], compare);
		t[3] = HeapSort(list[3], compare);
		t[4] = MergeSort(list[4], compare);
		cout << "INSERTSORT" << ":   " << t[0].c << "     " << t[0].a << endl;
		cout << "SELECTSORT" << ":   " << t[1].c << "     " << t[1].a << endl;
		cout << "QUICKSORT" << ":   " << t[2].c << "     " << t[2].a << endl;
		cout << "HEAPSORT" << ":   " << t[3].c << "     " << t[3].a << endl;
		cout << "MERGESORT" << ":   " << t[4].c << "     " << t[4].a << endl;


		cout << "--------------------------------------" << endl;

	}

	return 0;
}