#include "Node.h"

#include "LinearList.h"
typedef struct ListHead *LinkedStack;

bool InitLinkedStack(LinkedStack &S)
{
	S->size = 0;
	S->top = new LNode;
	if (S->top == NULL)
	{
		return false;
	}

	S->top->next = NULL;
	return true;
}

