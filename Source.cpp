#include<iostream>
#include"BinaryTree.h"
#include<list>

template <typename T>
bool BinaryTree<T>::datacomparison(Node* T1, Node* T2)//function to check if two Trees are similar or not
{
	if (T1 == NULL && T2 == NULL)//if both Trees are NULL or becomes NULL
		return true;

	else if (T1 == NULL || T2 == NULL)//if only one Tree becomes NULL
		return false;

	/*
	comparing data of current nodes and recursive calls for left and
	right subtrees and similarly comparing their data
	*/
	else
		return ((T1->data == T2->data) && datacomparison(T1->left, T2->left)
			&& datacomparison(T1->right, T2->right));
}

template <typename T>
bool BinaryTree<T>::isSubTree(Node* T1, Node* T2)//function to check if second Tree is a subtree of first one or not
{
	if (T1 == T2)//if both trees are equal or becomes equal while traversing 
		return true;

	else if (T1 == NULL)//if we reached end of first tree
		return false;

	else if (T2 == NULL)//if second Tree is initially NULL as empty set is a subset of all sets
		return true;

	else if (datacomparison(T1, T2))//comparing both trees and returning true if they are equal
		return true;

	/*
	recursive calls: if reached here then repeat the same process above
	for left subtree of T1, if left subtree is similar to T2 returning true otherwise
	repeat the process for right subtree of T1 and will continue to do so until
	we found our subtree or when T1 reached the bottom and no similar tree was found in T1
	*/
	else
		return (isSubTree(T1->left, T2) || isSubTree(T1->right, T2));
}

int main()
{
	BinaryTree<int> BT;

	for (int i = 0; i < 15; i++)
		BT.Insert(i + 1);

	cout << "test 1:\nBinary Tree: ";
	BinaryTree<int>::BFIterator it;
	for (it = BT.begin(); !it.end(); it++)
		cout << *it << endl;

	cout << "\nChecking if root's left subtree is a subtree of root or not\n";
	if (BinaryTree<int>::isSubTree(BT.begin(), BT.begin()->left))
		cout << "root's left is a subtree of root\n\n";
	else
		cout << "root's left is not a subtree of root\n\n";

	cout << endl << endl;

	BinaryTree<int> BT1;
	for (int i = 0; i < 3; i++)
		BT1.Insert((i + 1) * 10);

	cout << "test 2:\nBinary Tree 1: ";
	for (it = BT.begin(); !it.end(); it++)
		cout << *it << endl;

	cout << endl;

	cout << "Binary Tree 2: ";
	for (it = BT1.begin(); !it.end(); it++)
		cout << *it << endl;

	cout << "\nChecking if Binary Tree 2 is a subtree Binary Tree 1 or not\n";
	if (BT.isSubTree(BT.begin(), BT1.begin()))
		cout << "Binary Tree 2 is a subtree of Binary Tree 1\n\n";
	else
		cout << "Binary Tree 2 is not a subtree of Binary Tree 1\n\n";

}