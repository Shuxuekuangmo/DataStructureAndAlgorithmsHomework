#include <iostream>
using namespace std;

// define QElemType in the main program

typedef struct LNode
{
	QElemType data;
	LNode *next;

}*LQueue;

bool LQueueInit(LQueue &LQ)
{
	LQ = new LNode;
	if (LQ == NULL)return false;
	LQ->next = LQ;
	return true;
}
bool LQueueEmpty(LQueue LQ)
{
	return LQ->next == LQ;
}
bool EnLQueue(LQueue &LQ, QElemType e)
{
	LQueue tempnode = LQ->next;
	LQueue lnode = new LNode;
	if (lnode == NULL)return false;
	LQ->data = e;
	LQ->next = lnode;
	lnode->next = tempnode;


	LQ = lnode;


	return true;
}
bool DeLQueue(LQueue &LQ, QElemType &e)
{
	if (LQ->next == LQ)return false;
	e = LQ->next->data;
	LQueue lnode = LQ->next;


	LQ->next = LQ->next->next;

	delete lnode;
	return true;
}

void LQueueDestroy(LQueue &LQ)
{
	LQueue lnode0 = LQ, lnode1 = LQ;
	while (lnode1 != LQ)
	{
		lnode1 = lnode1->next;
		delete lnode0;
		lnode0 = lnode1;
	}
	delete LQ;
}

void ShowLQueue(LQueue LQ)
{
	LQueue lnode = LQ->next;
	while (lnode != LQ)
	{
		cout << lnode->data << " ";
		lnode = lnode->next;
	}
	cout << endl;
}