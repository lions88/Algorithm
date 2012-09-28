/*
 *	liliang 2011/3/16
 *	fileName:BinaryTree.cpp
 *	description: class BinTree implement
 */

#include "BinaryTree.h"

/* return root node of binary tree */
BinTreeNode * BinTree::getRootNode()
{
	return this->root;
}

/* return depth of binary tree */
int BinTree::depthBinTree()
{
	BinTreeNode *tempL=root, *tempR=root;
	if ( !tempL )
		return 0;
	
	return 1;
}

/* if binary tree is null */
bool BinTree::isEmpty()
{
	return this->root==NULL ? true:false;
}

/* get node value if it's in the binary */
DATATYPE BinTree::getValue(BinTreeNode *p)
{
	if (!p)
		return -1;
	
	return p->data;
}

/* return node's parent */
BinTreeNode * BinTree::getParentNode(BinTreeNode *cur)
{
	if (!cur)
		return NULL;

	if ( this.root == cur)
		return NULL;

	BinTreeNode *temp = this.root;
	if ((temp->leftChild&&temp->leftChild==cur) || (temp->rightChild&&temp->rightChild==cur) )
		return temp;

}

/* get node of left child */
BinTreeNode * BinTree::getLeftChild(BinTreeNode *cur)
{
	if (!cur->leftChild)
		return NULL;

	return cur->leftChild;
}

/* get node of right child */
BinTreeNode * BinTree::getRightChild(BinTreeNode *cur)
{
	if (!cur->rightChild)
		return NULL;

	return cur->rightChild;
}

/* find node which value equal to d */
BinTreeNode * BinTree::findNodeByValue(BinTreeNode *rootNode, DATATYPE d)
{
	BinTreeNode *temp = rootNode;
	if ( !rootNode )
		return NULL;

	if (temp->data == d)
		return temp;
	else
	{
		if (temp->leftChild)
			findNodeByValue(temp->leftChild, d);

		if (temp->rightChild)
			findNodeByValue(temp->rightChild, d);
	}
}