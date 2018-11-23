

#include <iostream>
using namespace std;

typedef int QElemType;
struct CQueue
{
	QElemType *data;
	int rare;
	int length;
	int size;
};
typedef CQueue*  NQ;
bool Init(NQ &q, int n)
{
	q = new CQueue;
	if (q == NULL)
	{
		return false;
	}
	q->data = new QElemType [n];
	if (q->data == NULL)
	{
		return false;
	}
	q->length = 0;
	q->rare = -1;
	q->size = n;
	return true;
}

int CQLength(NQ q)
{
	return q->length;
}

bool CQueueEmpty(NQ q)
{
	return (q->length) == 0;
}
bool CQueueFull(NQ q)
{
	return (q->length) == (q->size - 1);
}
bool DeCQueue(NQ &q, QElemType &e)
{
	if (CQueueEmpty(q))
	{
		return false;
	}
	e = q->data[(q->rare + 1 + (q->size - q->length)) % (q->size)];
	q->length -= 1;
	return true;
}
bool EnCQueue(NQ &q, QElemType  e)
{
	if (CQueueFull(q))
	{
		return false;
	}
	q->rare = (q->rare + 1) % q->size;
	q->data[q->rare] = e;
	q->length += 1;
	return true;
}


void show(NQ &q)
{
	int i;
	for (i = 0; i < (q->size); i++)
	{
		cout << q->data[i] << " ";
	}
	cout << endl << "length: " << q->length << endl;;
	cout << "rare: " << q->rare << endl;
	int front = (q->rare + 1 + (q->size - q->length)) % (q->size);
	cout << "head: " << front << endl << endl;;
}
int main()
{
	NQ q;
	Init(q, 7);
	show(q);
	int i = 1;

	EnCQueue(q, i);
	i++;
	show(q);
	EnCQueue(q, i);
	i++;
	show(q);

	int a, *b = &a;

	DeCQueue(q, a);
	show(q);
	DeCQueue(q, a);
	show(q);

	EnCQueue(q, i);
	i++;
	show(q);
	EnCQueue(q, i);
	i++;
	show(q);
	EnCQueue(q, i);
	i++;
	show(q);
	EnCQueue(q, i);
	i++;
	show(q);
	EnCQueue(q, i);
	i++;
	show(q);
	EnCQueue(q, i);
	i++;
	show(q);
	EnCQueue(q, i);
	i++;
	show(q);

	DeCQueue(q, a);
	show(q);
	DeCQueue(q, a);
	show(q);

	return 0;
}