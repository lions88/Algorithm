/*
2010�� 10��18������ July
--------------------------------
1.�Ѷ�Ԫ������ת��������˫������
 ��Ŀ��
����һ�ö�Ԫ�����������ö�Ԫ������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ����ָ���ָ��
   
   10
   / \
  6  14
 / \ / \
4  8 12 16
   
 ת����˫������
 4=6=8=10=12=14=16��
   
 �������Ƕ���Ķ�Ԫ������ �ڵ�����ݽṹ���£�
 struct BSTreeNode
{
  int m_nValue; // value of node
  BSTreeNode *m_pLeft; // left child of node
  BSTreeNode *m_pRight; // right child of node
};
*/

#include <stdio.h>
#include <iostream.h>

struct BSTreeNode
{
    int m_nValue; // value of node
    BSTreeNode *m_pLeft; // left child of node
    BSTreeNode *m_pRight; // right child of node
};

typedef BSTreeNode DoubleList;
DoubleList * pHead;
DoubleList * pListIndex;

void convertToDoubleList(BSTreeNode * pCurrent);


// ������Ԫ������
void addBSTreeNode(BSTreeNode * & pCurrent, int value)
{
    if (NULL == pCurrent)
    {
        BSTreeNode * pBSTree = new BSTreeNode();
        pBSTree->m_pLeft = NULL;
        pBSTree->m_pRight = NULL;
        pBSTree->m_nValue = value;
        pCurrent = pBSTree;

    }
    else 
    {
        if ((pCurrent->m_nValue) > value)
        {
            addBSTreeNode(pCurrent->m_pLeft, value);
        }
        else if ((pCurrent->m_nValue) < value)
        {
            addBSTreeNode(pCurrent->m_pRight, value);
        }
        else
        {
            //cout<<"�ظ�����ڵ�"<<endl;
        }
    }
}


// ������Ԫ������  ����
void ergodicBSTree(BSTreeNode * pCurrent)
{
    if (NULL == pCurrent)
    {        
        return;
    }
    if (NULL != pCurrent->m_pLeft)
    {
        ergodicBSTree(pCurrent->m_pLeft);    
    }

    // �ڵ�ӵ�����β��
    convertToDoubleList(pCurrent);

    // ������Ϊ��
    if (NULL != pCurrent->m_pRight)
    {
        ergodicBSTree(pCurrent->m_pRight);
    }
}



// ������ת����list
void  convertToDoubleList(BSTreeNode * pCurrent)
{

    pCurrent->m_pLeft = pListIndex;
    if (NULL != pListIndex)
    {
        pListIndex->m_pRight = pCurrent;
    }
    else
    {
        pHead = pCurrent;
    }    
    pListIndex = pCurrent;
    cout<<pCurrent->m_nValue<<endl;
}

void PrintDoubleList(DoubleList *pDList)
{
	//cout<<"==================DOUBLELIST============"<<endl;
	cout<<pDList->m_nValue<<endl;
	if (pDList->m_pRight)
		PrintDoubleList(pDList->m_pRight);
}

int main()
{
    BSTreeNode * pRoot = NULL;
    pListIndex = NULL;
    pHead = NULL;
    addBSTreeNode(pRoot, 10);
    addBSTreeNode(pRoot, 4);
    addBSTreeNode(pRoot, 6);
    addBSTreeNode(pRoot, 8);
    addBSTreeNode(pRoot, 12);
    addBSTreeNode(pRoot, 14);
    addBSTreeNode(pRoot, 16);
    ergodicBSTree(pRoot);

	cout<<"=========================\n";
	PrintDoubleList(pHead);
    return 0;
}
