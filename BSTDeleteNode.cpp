#include <iostream>
using namespace std;

typedef int KeyType;

typedef struct Data
{
	KeyType key;
	// int data
} *TElemType;
#include "BinaryTree.h"




int compare(KeyType a, KeyType b)
{
	return a - b;
}
void BSTreeInsert(BiTree &BST, TElemType data, int compare(KeyType a, KeyType b))
{
	if (BST == NULL)
	{
		BST = new TNode;
		BST->left = BST->right = NULL;
		BST->data = data;
		return;
	}
	else if (compare(BST->data->key, data->key) == 0)return;
	else if (compare(BST->data->key, data->key) > 0)BSTreeInsert(BST->left, data, compare);
	else BSTreeInsert(BST->right, data, compare);
}
BiTree BSTGenerate(TElemType data, int n, int compare(KeyType a, KeyType b))
{
	BiTree BST = NULL;
	int i;
	for (i = 0; i < n; ++i, ++data)
	{
		// cout << i << endl;
		BSTreeInsert(BST, data, compare);
	}
	return BST;
}

void visit(TElemType a)
{
	cout << a->key;
}
void zhongxubianli(BiTree BST, void visit(TElemType a))
{
	if (BST == NULL)return;
	zhongxubianli(BST->left, visit);
	visit(BST->data);
	zhongxubianli(BST->right, visit);
}



bool BSTDeleteTopNode1(BiTree &BT, int compare(KeyType, KeyType))
{
	if (BT == NULL)return false;
	if (BT->left == NULL)BT = BT -> right;
	else if (BT->right == NULL)BT = BT->left;
	else
	{
		BiTree bnode = BT->left;
		while (bnode->right != NULL)bnode = bnode->right;
		bnode->right = BT->right;

		bnode = BT;
		BT = BT->left;
		delete bnode;
	}
	return true;
}
bool BSTDeleteTopNode2(BiTree &BT, int compare(KeyType, KeyType))
{
	if (BT == NULL)return false;
	if (BT->left == NULL)BT = BT -> right;
	else if (BT->right == NULL)BT = BT->left;
	else
	{
		BiTree bnode = BT->left, prenode = bnode;
		while (bnode->right != NULL)
		{
			prenode = bnode;
			bnode = bnode->right;
		}
		prenode->right = bnode->left;
		bnode->right = BT->right;
		bnode->left = BT->left;

		prenode = BT;
		BT = bnode;
		delete prenode;
	}
	return true;
}

// BiTree BSTSearch(BiTree &BST,KeyType key,int compare(KeyType,KeyType))
// {

// }

bool BSTSearchAndDelete(BiTree &BST, KeyType key, int compare(KeyType, KeyType))
{
	if (BST == NULL)return false;
	if (compare(BST->data->key, key) == 0)
	{
		// cout << BST->data->key << endl;
		BSTDeleteTopNode2(BST, compare);
		return true;
	}
	else if (BSTSearchAndDelete(BST->left, key, compare))return true;
	return BSTSearchAndDelete(BST->right, key, compare);

}



int main(int argc, char const *argv[])
{
	Data a[] = {5, 1, 2, 3, 4, 6, 7, 8, 9};
	BiTree BST = BSTGenerate(a, 9, compare);
	BiTreeLists(BST, visit);
	cout << endl;
	zhongxubianli(BST, visit);
	cout << endl;


	BSTSearchAndDelete(BST, 8, compare);


	BiTreeLists(BST, visit);
	cout << endl;
	zhongxubianli(BST, visit);
	cout << endl;
	return 0;
}