#include <iostream>
using namespace std;

// typedef char SElemType;

typedef struct LNode
{
	SElemType data;
	LNode *next;

}*LStack;

bool LStackInit(LStack &LS)
{
	LS = new LNode;
	if (LS == NULL)return false;
	LS->next = NULL;
	return true;
}
bool LStackEmpty(LStack LS)
{
	return LS->next == NULL;
}
bool LStackPush(LStack &LS, SElemType e)
{
	LStack tempnode = LS->next;
	LStack lnode = new LNode;
	if (lnode == NULL)return false;
	lnode->data = e;
	LS->next = lnode;
	lnode->next = tempnode;
	return true;
}
bool LStackPop(LStack &LS, SElemType &e)
{
	if (LS->next == NULL)return false;
	e = LS->next->data;
	LS->next = LS->next->next;
	return true;
}

void LStackDestroy(LStack &LS)
{
	LStack lnode0 = LS, lnode1 = LS;
	while (lnode1 != NULL)
	{
		lnode1 = lnode1->next;
		delete lnode0;
		lnode0 = lnode1;
	}
}