#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <string>

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
typedef struct Times
{
	int compared;
	int assignment;
} times;


int compare(ElemType a, ElemType b) {return a->key - b->key;}
times InsertSort(SList &list, int compare(ElemType a, ElemType b))
{
	int i, j; ElemType x;
	int compared = 0, assignment = 0;

	for (i = 1; i < list->length; ++i)
	{
		for (x = list->data[i], assignment += 1, j = i - 1; compared += 1, j >= 0 && compare(x, list->data[j]) < 0; --j)
		{
			list->data[j + 1] = list->data[j];
			assignment += 1;

		}
		list->data[j + 1] = x;
		assignment += 1;
	}
	return {compared, assignment};
}

times SelectSort(SList &list, int compare(ElemType a, ElemType b))
{
	int compared = 0;
	int assignment = 0;

	int i, j;
	int  mindata;
	ElemType temp;
	for (i = 0; i < list->length; ++i)
	{
		mindata = i;
		for (j = i + 1; j < list->length; ++j)
		{

			if ((compared += 1, compare(list->data[mindata], list->data[j]) > 0))
			{
				mindata = j;
			}

		}
		if (mindata > i)
		{
			temp = list->data[i];
			list->data[i] = list->data[mindata];
			list->data[mindata] = temp;
			assignment += 3;
		}
	}
	return {compared, assignment};
}

int partition(ElemType * L, int a, int b, int compare(ElemType a, ElemType b), times &t)
{
	ElemType x = L[a];
	while (a < b)
	{
		while (a < b && (t.compared += 1, compare(L[b], x) >= 0))
		{
			--b;
		}
		L[a] = L[b];
		while (a < b && (t.compared += 1, compare(L[a], x) <= 0))
		{
			++a;
		}
		L[b] = L[a];
		t.assignment += 2;

	}
	L[a] = x;
	t.assignment += 2;
	return a;
}

times QuickSort(SList &list, int a, int b, int compare(ElemType a, ElemType b))
{
	int p;
	times t = {0, 0};
	if (a >= b)return t;
	p = partition(list->data, a, b, compare, t);
	// cout << " " << t.compared << " " << t.assignment << endl;
	times t1 = QuickSort(list, a, p - 1, compare);
	times t2 = QuickSort(list, p + 1, b, compare);
	return {t.compared + t1.compared + t2.compared, t.assignment + t1.assignment + t2.assignment};
}

times QuickSort(SList &list, int compare(ElemType a, ElemType b))
{
	return QuickSort(list, 0, list->length - 1, compare);
}





times HeapAdjust(SList &H, int start, int end, int compare(ElemType a, ElemType b))
{
	times t = {0, 0};

	int minchild;
	ElemType temp;

	temp = H->data[start];
	t.assignment += 1;

	minchild = 2 * start + 1;

	while (minchild <= end)
	{
		if (minchild < end && (t.compared += 1, compare(H->data[minchild], H->data[minchild + 1]) < 0))++minchild;
		if ((t.compared += 1, compare(temp, H->data[minchild]) >= 0))break;

		t.assignment += 1;

		H->data[start] = H->data[minchild];
		start = minchild;
		minchild = 2 * minchild + 1;
	}
	t.assignment += 1;
	H->data[start] = temp;
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
		t.compared += t1.compared;
		t.assignment += t1.assignment;
	}
	for (i = H->length - 1; i >= 1; --i)
	{
		temp = H->data[0];
		H->data[0] = H->data[i];
		H->data[i] = temp;
		t1 = HeapAdjust(H, 0, i - 1, compare);
		t.compared += t1.compared;
		t.assignment += t1.assignment + 3;
	}
	return t;
}

times Merge(SList &list, int start, int middle, int end, int compare(ElemType a, ElemType b))
{
	times t = {0, 0};

	int i, j, k;
	ElemType *temp;

	temp = new ElemType[middle - start + 1];
	for (i = start; i <= middle; ++i)
	{
		t.assignment += 1;

		temp[i - start] = list->data[i];
	}
	i = 0;
	k = start - 1;
	j = middle + 1;
	while (i <= middle - start && j <= end)
	{
		++k;
		if ((t.compared += 1, compare(temp[i], list->data[j]) <= 0))
		{
			t.assignment += 1;
			list->data[k] = temp[i];
			++i;
		}
		else
		{
			t.assignment += 1;
			list->data[k] = list->data[j];
			++j;
		}
	}
	// cout << k << endl;
	while (i <= middle - start)
	{
		t.assignment += 1;
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

	int start, middle, end;
	int i;
	for (i = 1; i < list->length - 1; i *= 2)
	{
		for (start = 0;; start += 2 * i)
		{
			middle = start + i - 1;
			if (middle >= list->length - 1)break;
			end = middle + i;
			if (end > list->length - 1)end = list->length - 1;
			// cout << start << " " << middle << " " << end << endl;
			t1 = Merge(list, start, middle, end, compare);

			t.compared += t1.compared;
			t.assignment += t1.assignment;

		}
	}
	return t;
}

bool SListGenerate(SList &list, ElemType a, int n)
{
	list = new struct list;
	list->length = n;
	int i;
	list->data = new ElemType[n];
	for (i = 0; i < n; ++i)
	{
		list->data[i] = a++;
	}
	return true;
}

int main(int argc, char const *argv[])
{

	string a[5] = {"InsertSort", "SelectSort", "QuickSort", "HeapSort", "MergeSort"};
	times (*func[5])(SList & list, int compare(ElemType a, ElemType b)) = {InsertSort, SelectSort, QuickSort, HeapSort, MergeSort};



	int n = 5;
	ElemType datas = new struct Data[1000];
	srand(time(0));
	int i;
	for (i = 0; i < 1000; ++i)
	{
		datas[i] = {(rand() % 1000)};
	}



	int time;
	for (time = 1; time <= n; ++time)
	{
		cout << " the " << time << " time" << endl;

		times t[5];
		SList list[5];
		int j;
		cout << " sort method :" << "\tcompared times \t" << "assignment times" << endl;
		for (j = 0; j < 5; ++j)
		{
			SListGenerate(list[j], datas, 1000);
			t[j] = func[j](list[j], compare);
			cout << " " << a[j] << "\t:\t" << t[j].compared << "\t\t\t" << t[j].assignment << endl;
		}

		cout << endl;

	}

	return 0;


}