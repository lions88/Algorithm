/*
 *	liliang 2011/4/6
 *	fileName:mergeSort.cpp
 *	description:归并排序，是采用分治法的一个非常典型的应用。
 *		时间复杂度O(nlogn)
 *		空间复杂度O(n)
 *		速度仅次于快速排序，但较稳定。
 */

#include <iostream>

using namespace std;

/*
 *　array是元素序列，其中从索引first开始到mid位置，按照升序排列，
 *	同时，从(mid+1)到last也已经按照升序排列，
 *	merge()函数将把这两个已经排序好的子序列合并成一个排序序列。
 *	结果放到array中。 
 */
 void Merge(int *array, int first, int mid, int last)
{
	int i,k;
	int begin1,end1, begin2,end2;
	int size;

	int *temp = (int *)malloc((last-first+1)*sizeof(int));

	begin1 = first;
	end1 = mid;
	begin2 = mid+1;
	end2 = last;

	k = 0;

	while(begin1<=end1 && begin2<=end2)
	{
		if (array[begin1] < array[begin2])
		{
			temp[k] = array[begin1];
			begin1++;
		}
		else
		{
			temp[k] = array[begin2];
			begin2++;
		}

		k++;
	}

	while(begin1 <= end1)
		temp[k++] = array[begin1++];

	while(begin2 <= end2)
		temp[k++] = array[begin2++];

	size = last-first+1;
	for (i=0; i<size; i++)
	{
		array[first+i] = temp[i];
	}

	free(temp);
}

/* 归并排序(递归实现) */
void MergeSort(int *array, int first, int last)
{
	int mid = 0;

	if ( first < last )
	{
		mid = (first + last) / 2 ;
		MergeSort(array, first, mid);
		MergeSort(array, mid+1, last);

		Merge(array, first, mid, last);
	}
}

int main(void)
{
	int i;
	int a[10] = {45,23,41,67,1,4,80,65,9,100};
	MergeSort(a, 0, 9);

	for(i=0; i<10; i++)
		cout<<a[i] <<"\t" ;

	cout<<endl;

	return 0;
}
/*
	{45,23,41,67,1,4,80,65,9,100};

	{45,23,41,67,1} {4,80,65,9,100}

	{45.23.41} {67,1} {4,80,65} {9,100}

	{45,23} {41} {67,1} {4,80} {65} {9,100}

	{23,45} {41} {1,67} {4,80} {65} {9,100}

	{23,41,45} {1,67} {4,65,80} {9,100}

	{1,23,41,45,67} {4,9,65,80,100}

	{1,4,9,23,41,45,67,80,100}
*/