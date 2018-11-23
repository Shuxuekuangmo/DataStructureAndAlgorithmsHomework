
#include <iostream>
using namespace std;

typedef char ElemType;

typedef struct LNode
{
	ElemType data;
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
bool LStackPush(LStack &LS, ElemType e)
{
	LStack tempnode = LS->next;
	LStack lnode = new LNode;
	if (lnode == NULL)return false;
	lnode->data = e;
	LS->next = lnode;
	lnode->next = tempnode;
	return true;
}
bool LStackPop(LStack &LS, ElemType &e)
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
bool Matched(char a[], int n)
{
	int i;
	LStack LS;
	// LStack  lnode;
	LStackInit(LS);
	ElemType e;
	for (i = 0; i < n; ++i)
	{
		// lnode = LS;
		// while (lnode->next != NULL)
		// {
		// 	cout << lnode->next->data;
		// 	lnode = lnode->next;
		// }
		// cout << endl;


		switch (a[i])
		{
		case '{':
		case '[':
		case '(': LStackPush(LS, a[i]); break;
		case '}':
			if (!LStackPop(LS, e) || e != '{')
				return false;
			break;
		case ']':
			if (!LStackPop(LS, e) || e != '[')
				return false;
			break;
		case ')':
			if (!LStackPop(LS, e) || e != '(')
				return false;
			break;
		default:;
		}
	}
	bool res = LStackEmpty(LS);
	LStackDestroy(LS);
	return res;

}


int main(int argc, char const * argv[])
{

	char a[] = "((((([]{}{})))))--asnjc{}[]";
	if (Matched(a, 27))
		cout << "pairs matched" << endl;
	else
		cout << "pairs do not matched" << endl;

	return 0;
}