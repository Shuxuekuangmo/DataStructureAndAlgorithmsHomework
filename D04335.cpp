#include <iostream>
using namespace std;
#include "BinaryTree.h"
#include "LQueue.h"

// typedef BiTree ElemType;
bool BiTreeCompelete(BiTree BT)
{
	bool MarkNULL = false;
	LQueue LQ;
	BiTree lnode;
	if (!BT)return true;
	LQueueInit(LQ);
	EnLQueue(LQ, BT);
	while (DeLQueue(LQ, lnode))
	{
		// if (lnode->left == NULL)MarkNULL = true;
		// else
		// {
		// 	if (MarkNULL == true)return false;
		// 	EnLQueue(LQ, lnode->left);
		// }

		// if (lnode->right == NULL)MarkNULL = true;
		// else
		// {
		// 	if (MarkNULL == true)return false;
		// 	EnLQueue(LQ, lnode->right);
		// }
		if (lnode == NULL)MarkNULL = true;
		else if (MarkNULL == true)return false;
		else
		{
			EnLQueue(LQ, lnode->left);
			EnLQueue(LQ, lnode->right);
		}
	}
	LQueueDestroy(LQ);
	return true;
}


void show(BiTree BT)
{
	BiTreeLists(BT, visit);

	cout << endl;
	if (BiTreeCompelete(BT))
	{
		cout << "This BiTree is compelete" << endl;
	}
	else
	{
		cout << "This BiTree is not compelete" << endl;
	}
	cout << endl;
}
int main(int argc, char const *argv[])
{
	BiTree BT1, BT2, BT3;
	char a[] = "abdh##i##e##cf##g##";
	char b[] = "ab#d##c##";
	char c[] = "#";
	BiTreeCreatWithCharArray(BT1, a);
	BiTreeCreatWithCharArray(BT2, b);
	BiTreeCreatWithCharArray(BT3, c);


	show(BT1);
	show(BT2);
	show(BT3);
	return 0;
}