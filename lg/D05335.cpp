#include <iostream>
using namespace std;

typedef char TElemType;
typedef struct BiTNode
{
	TElemType data;
	BiTNode *lc;
	BiTNode *rc;
}*BiTree;

typedef BiTree ElemType;
typedef struct LNode
{
	ElemType data;
	LNode *next;

}*LQueue;

bool QueueInit(LQueue &q)
{
	q = new LNode;
	if (q == NULL)
	{
		return false;
	}
	q->next = q;
	return true;
}
bool LQueueEmpty(LQueue q)
{
	return q->next == q;
}
bool Enqueue(LQueue &q, ElemType e)
{
	LQueue tempnode = q->next;
	LQueue lnode = new LNode;
	if (lnode == NULL)
	{
		return false;
	}
	q->data = e;
	q->next = lnode;
	lnode->next = tempnode;
	q = lnode;
	return true;
}
bool DeLQueue(LQueue &q, ElemType &e)
{
	if (q->next == q)return false;
	e = q->next->data;
	LQueue lnode = q->next;
	q->next = q->next->next;
	delete lnode;
	return true;
}

void QueueDestroy(LQueue &q)
{
	LQueue lnode0 = q, lnode1 = q;
	while (lnode1 != q)
	{
		lnode1 = lnode1->next;
		delete lnode0;
		lnode0 = lnode1;
	}
	delete q;
}

void CreatBiTree(BiTree &T, char s[], int &i)
{
	i++;
	if (s[i] == '#')
	{
		T = NULL; return;
	}
	T = new BiTNode;
	T->data = s[i];
	CreatBiTree(T->lc, s, i);
	CreatBiTree(T->rc, s, i);

}
void CreatBiTree(BiTree &T, char s[])
{
	int i = -1;
	CreatBiTree(T, s, i);
}

void BiTreeLists(BiTree T, void visit(TElemType))
{
	if (!T) {cout << "#"; return;}

	visit(T->data);
	if (T->lc || T->rc)
	{
		cout << "(";
		BiTreeLists(T->lc, visit);
		cout << ',';
		BiTreeLists(T->rc, visit);
		cout << ')';
	}

}


void visit(TElemType a)
{
	cout << a;
}
bool LevelOrder(BiTree T)
{
	bool MarkNULL = false;
	LQueue q;
	BiTree lnode;
	if (!T)return true;
	QueueInit(q);
	Enqueue(q, T);
	while (DeLQueue(q, lnode))
	{
		if (lnode == NULL)MarkNULL = true;
		else if (MarkNULL == true)return false;
		else
		{
			Enqueue(q, lnode->lc);
			Enqueue(q, lnode->rc);
		}

	}
	QueueDestroy(q);
	return true;
}


void show(BiTree T)
{
	BiTreeLists(T, visit);

	cout << endl;
	if (LevelOrder(T))
	{
		cout << "compelete" << endl;
	}
	else
	{
		cout << "not compelete" << endl;
	}
	cout << endl;
}
int main()
{
	BiTree T1, T2;
	char s[] = "abdh##i##ej##k##cf##g##";
	char b[] = "ab#de###c##";
	CreatBiTree(T1, s);
	CreatBiTree(T2, b);
	show(T1);
	show(T2);
	return 0;
}
