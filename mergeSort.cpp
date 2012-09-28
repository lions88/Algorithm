/*
 *	liliang 2011/4/6
 *	fileName:mergeSort.cpp
 *	description:�鲢�����ǲ��÷��η���һ���ǳ����͵�Ӧ�á�
 *		ʱ�临�Ӷ�O(nlogn)
 *		�ռ临�Ӷ�O(n)
 *		�ٶȽ����ڿ������򣬵����ȶ���
 */

#include <iostream>

using namespace std;

/*
 *��array��Ԫ�����У����д�����first��ʼ��midλ�ã������������У�
 *	ͬʱ����(mid+1)��lastҲ�Ѿ������������У�
 *	merge()���������������Ѿ�����õ������кϲ���һ���������С�
 *	����ŵ�array�С� 
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

/* �鲢����(�ݹ�ʵ��) */
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