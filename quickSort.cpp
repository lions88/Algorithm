/*
 *	liliang 2011/3/18
 *	fileName:quickSort.cpp
 *	description:快速排序
 */

#include <iostream>

using namespace std;


void Swap(int &a, int &b)
{
	/*引用（C++）*/
	int temp = a;
	a = b;
	b = temp;
}

/************************************************************************/
/*                                                                      */
/************************************************************************/
int Partition(int *arry, int low, int high)
{
	while(low < high)
	{
		while (low < high && arry[low] < arry[high])
		{
			high--;
		}

		Swap(arry[low], arry[high]);

		while (low < high && arry[low] < arry[high])
		{
			low++;
		}

		Swap(arry[low], arry[high]);
	}
	return low;
}

/************************************************************************/
/* 递归实现                                                             */
/************************************************************************/
void QuickSort(int *arry, int low, int high)
{
	if (low < high)
	{
		int pivotPos = Partition(arry, low, high);

		QuickSort(arry, low, pivotPos-1);
		QuickSort(arry, pivotPos+1, high);
	}
}


int main(void)
{
	int i;
	//int a[10] = {45,23,41,67,1,4,80,65,9,100};
	int a[5] = {3, 6, 1, 9, 7};
	QuickSort(a,0,4/*9*/);

	for (i=0; i<5/*10*/; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;

	return 0;
}