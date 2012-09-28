/*
 *	liliang 2011/3/18
 *	fileName:insertSort.cpp
 *	description:÷±Ω”≤Â»Î≈≈–Ú
 */

#include <iostream>
#include <cassert>

using namespace std;

void insertSort(int *arr,int size)
{
	assert(size>0);

	int i,j,temp;
	for (i=1; i<size; i++)
	{
		if (arr[i] < arr[i-1])
		{
			temp = arr[i];				//*******
			arr[i] = arr[i-1];			//*******
		
			for (j=i-2; j>=0; j--)
			{
				if (temp<arr[j])
				{
					arr[j+1] = arr[j];	//******
				}
				else
					break;
			}
			arr[j+1] = temp;			//******
		}
	}
}

int main()
{
	int a[10] =	{1,2,3,4,5,6,7,8,9,0};	//{9,6,8,7,5,4,3,2,0,1};
	insertSort(a,10);

	for (int i=0; i<10; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;

	return 0;
}