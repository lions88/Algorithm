#include <iostream>
#include <cassert>

using namespace std;

template <class T>
struct linkNode
{
	linkNode():data(T()),next(0){}
	linkNode(const T& d, linkNode *nxt=0):data(d),next(nxt){}

	T data;
	linkNode *next;
};

template <class T>
linkNode<T> *createLinkList(T* arrary,int size)
{
	assert(arrary);

	if (!arrary)
		return NULL;

	linkNode<T> *prev=NULL, *cur=NULL, *head = NULL;
	
	if( (head=new linkNode<T>(arrary[0],0)) == NULL )
		return NULL;
	prev = head;

	if (size > 1)
	{
		for (int i=1; i<size; i++)
		{
			cur = new linkNode<T>(arrary[i],0);
			prev->next = cur;
			prev = cur;
		}
		cur->next = NULL;
	}
	
	return head;
}

template <class T>
void destroyLinkList(linkNode<T> *head)
{
	if (!head)
		return;

	linkNode <T> *temp = head, *del = NULL;
	while (temp)
	{		
		del = temp;
		temp = temp->next;
		free(del);
	}
	
}

template<class T>
void printListData(linkNode<T> *head)
{
	if(!head)
		return;

	linkNode<T> *temp = head;
	while (temp)
	{
		cout<<temp->data<<"\t" ;
		temp = temp->next;
	}
	cout <<endl;
}

template <class T>
linkNode<T>* reverseList(linkNode<T> *head)
{
	if (!head)
		return NULL;

	linkNode<T> *prev=NULL, *cur=head, *after=head;

	while (cur)
	{
		after = cur->next;
		cur->next = prev;
		prev = cur;
		cur = after;
	}
	//now cur and after is NULL prev is new head pointer
	return prev;		
}

int main()
{
	//int arrary[5] = {1,2,3,4,5};	
	char arrary[5] = {'a', 'b', 'c', 'd', 'e'};
	linkNode<char> *nodeHead = createLinkList(arrary,5);
	printListData(nodeHead);
	
	linkNode<char> *newHead = reverseList(nodeHead);
	printListData(newHead);

	return 0;
}

/*
template<class T>
typedef struct _BinaryTreeNode
{
	T value;
	_BinaryTreeNode *leftChild;
	_BinaryTreeNode *rightNode;
}BinaryTreeNode;
*/

/*一个十进制数转为2进制数有多少个1*/
/*int main()
{
	int n = 256;
	assert (n > 0);

	int num1 = 0;

	while ((n/2) != 0)
	{
		((n%2)==1) ? (num1+=1): (num1+=0);
		n /= 2;
	}
	if (n%2 == 1)
	{
		num1+=1;
	}
	cout<<num1<<"个1"<<endl;
	
	return 0;
}*/

//f(n)=f(n-1)+f(n-1)
/*int recursionFun(int n)
{
	if (n==2)
		return 2;
	else if (n==1)
		return 1;

	return recursionFun(n-1) + recursionFun(n-2);
}

int main()
{
	int n = 4;
	int result = recursionFun(n);
	cout<<"result = "<<result<<endl;
	
	result = recursionFun(6);
	cout<<"result = "<<result<<endl;
	return 0;
}
*/

/*
#include <stdio.h>

void Exchg1(int x, int y)
{
	int tmp=x;
	x=y;
	y=tmp;
	printf("x=%d,y=%d\n",x,y);
}

void Exchg2(int &x, int &y)
{
	int tmp=x;
	x=y;
	y=tmp;
	printf("x=%d,y=%d\n",x,y);
}
int main()
{
	int a=4;
	int b=6;
	Exchg2(a,b);
	//Exchg1(a,b);
	printf("a=%d,b=%d\n", a, b);
}

*/