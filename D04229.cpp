

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
typedef CQueue*  CQUEUE;
bool CQueueInit(CQUEUE &Q, int n)
{
	Q = new CQueue;
	if (Q == NULL)return false;

	Q->data = new QElemType [n];
	if (Q->data == NULL)return false;

	Q->length = 0;
	Q->rare = 0;
	Q->size = n;
	return true;
}

// void CQueueDestroy(CQUEUE &Q)
// {
// 	delete [](Q->data);
// 	delete Q;
// }


int CQueueLength(CQUEUE Q)
{
	return Q->length;
}

bool CQueueEmpty(CQUEUE Q)
{
	return (Q->length) == 0;
}
bool CQueueFull(CQUEUE Q)
{
	return (Q->length) == (Q->size - 1);
}
bool EnCQueue(CQUEUE &Q, QElemType  e)
{
	if (CQueueFull(Q))return false;
	Q->data[Q->rare] = e;
	Q->rare = (Q->rare + 1) % Q->size;
	Q->length += 1;
	return true;
}

bool DeCQueue(CQUEUE &Q, QElemType &e)
{
	if (CQueueEmpty(Q))return false;
	e = Q->data[(Q->rare + (Q->size - Q->length)) % (Q->size)];
	Q->length -= 1;
	return true;
}


void showCQueue(CQUEUE &Q)
{
	int i;
	for (i = 0; i < (Q->size); ++i)
	{
		cout << Q->data[i] << " ";
	}
	cout << endl << "the length of queue is " << Q->length << endl;;
	cout << "the rare is at " << Q->rare << endl;
	int front = (Q->rare + (Q->size - Q->length)) % (Q->size);
	cout << "the head is at " << front << endl << endl;;
}
int main(int argc, char const *argv[])
{
	CQUEUE Q;
	CQueueInit(Q, 5);
	showCQueue(Q);
	// cout << Q->length << endl;
	int i = 1;

	EnCQueue(Q, i);
	i++;
	showCQueue(Q);
	EnCQueue(Q, i);
	i++;
	showCQueue(Q);
	EnCQueue(Q, i);
	i++;
	showCQueue(Q);
	EnCQueue(Q, i);
	i++;
	showCQueue(Q);
	EnCQueue(Q, i);
	i++;
	showCQueue(Q);

	int a, *b = &a; //for test;

	DeCQueue(Q, a);
	showCQueue(Q);
	DeCQueue(Q, a);
	showCQueue(Q);
	DeCQueue(Q, a);
	showCQueue(Q);
	DeCQueue(Q, a);
	showCQueue(Q);
	DeCQueue(Q, a);
	showCQueue(Q);



	EnCQueue(Q, i);
	i++;
	showCQueue(Q);
	EnCQueue(Q, i);
	i++;
	showCQueue(Q);
	EnCQueue(Q, i);
	i++;
	showCQueue(Q);


	DeCQueue(Q, a);
	showCQueue(Q);
	DeCQueue(Q, a);
	showCQueue(Q);
	DeCQueue(Q, a);
	showCQueue(Q);
	return 0;
}