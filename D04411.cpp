#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef int KeyType;

typedef struct
{
	KeyType key;
	// int data
} TElemType;

typedef struct TNode
{
	TElemType data;
	int n;
	TNode *left;
	TNode *right;
}*BSTree;




int compare(KeyType a, KeyType b)
{
	return a - b;
}



void BSTreeInsert(BSTree &BST, TElemType data, int compare(KeyType a, KeyType b))
{
	if (BST == NULL)
	{
		BST = new TNode;
		BST->left = BST->right = NULL;
		BST->data = data;
		BST->n = 1;
		return;
	}
	else if (compare(BST->data.key, data.key) == 0)BST->n += 1;
	else if (compare(BST->data.key, data.key) > 0)BSTreeInsert(BST->left, data, compare);
	else BSTreeInsert(BST->right, data, compare);
}



void BSTCount(BSTree &BST, TElemType a[], int n, int compare(KeyType a, KeyType b))
{
	BST = NULL;
	int i;
	for (i = 0; i < n; ++i)
	{
		BSTreeInsert(BST, a[i], compare);
	}
}


int BSTGetCount(BSTree BST, KeyType a, int compare(KeyType a, KeyType b))
{
	if (BST == NULL)return 0;
	else if (compare(BST->data.key, a) == 0)return BST->n;

	else
	{
		int result = BSTGetCount(BST->left, a, compare);
		if (result > 0)return result;
		else return BSTGetCount(BST->right, a, compare);
	}
}


void BSTreeLists(BSTree BST, void show(TElemType))
{
	if (BST == NULL) {cout << "#"; return;}

	show(BST->data);
	if (BST->left || BST->right)
	{
		cout << "(";
		BSTreeLists(BST->left, show);
		cout << ',';
		BSTreeLists(BST->right, show);
		cout << ')';
	}

}
void show(TElemType a)
{
	cout << a.key;
}


void BSTDelete(BSTree &BST)
{
	if (BST == NULL)return;
	BSTDelete(BST->left);
	BSTDelete(BST->right);
	delete BST;
}
int main(int argc, char const *argv[])
{
	TElemType a[100];
	srand(time(0));
	int i;

	for (i = 0; i < 100; ++i)(a[i].key = rand() % 50 + 1);

	BSTree BST;
	BSTCount(BST, a, 100, compare);
	BSTreeLists(BST, show);
	cout << endl << "value   times" << endl;
	for (i = 1; i <= 50; ++i)
		cout << i << "     " << BSTGetCount(BST, i, compare) << endl;


	BSTDelete(BST);
	return 0;
}