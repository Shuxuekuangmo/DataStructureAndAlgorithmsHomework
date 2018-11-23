
#include <iostream>
using namespace std;

typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	LNode *next;

}*LStack;

bool StackInit(LStack &S)
{
	S = new LNode;
	if (S == NULL)return false;
	S->next = NULL;
	return true;
}
bool StackEmpty(LStack S)
{
	return S->next == NULL;
}
bool Push(LStack &S, ElemType e)
{
	LStack p = S->next;
	LStack l = new LNode;
	if (l == NULL)return false;
	l->data = e;
	S->next = l;
	l->next = p;
	return true;
}
bool Pop(LStack &S, ElemType &e)
{
	if (S->next == NULL)return false;
	e = S->next->data;
	S->next = S->next->next;
	return true;
}

void LStackDestroy(LStack &S)
{
	LStack l0 = S, l1 = S;
	while (l1 != NULL)
	{
		l1 = l1->next;
		delete l0;
		l0 = l1;
	}
}
bool Matched(char a[], int n)
{
	int i;
	LStack S;
	StackInit(S);
	ElemType e;
	for (i = 0; i < n; ++i)
	{

		if (a[i] == '{' || a[i] == '(' || a[i] == '[')
		{
			Push(S, a[i]);
		}
		else if (a[i] == '}')
		{
			if (!Pop(S, e) || e != '{')
				return false;
		}
		else if (a[i] == ']')
		{
			if (!Pop(S, e) || e != '[')
				return false;
		}
		else if (a[i] == ')')
		{
			if (!Pop(S, e) || e != '(')
				return false;
		}
	}
	bool s = StackEmpty(S);
	LStackDestroy(S);
	return s;

}


int main()
{

	char a[] = "((((([]{}{})))))--asnjc{}[]";
	if (Matched(a, 27))
		cout << "pipei" << endl;
	else
		cout << "bupipei" << endl;

	return 0;
}