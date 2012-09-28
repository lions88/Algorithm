/*
 *	liliang 2011/3/17
 *	fileName: 1.cpp
 *	description: —°‘Ò≈≈–Ú
 */

#include <iostream>
#include <vector>

using namespace std;

void swap(int &a,int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}

void selection_sort(vector<int>& v)
{
	int size = v.size();				//size of v
	int i,j;
	for (i=0; i<size-1; i++)
	{
		int best = i;
		for(j=i+1; j<size; j++)
		{
			if (v[j] < v[best])
				best = j;
		}
		if (best != i)
		{
			swap(v[i],v[best]);
		}
	}
}

int main()
{
	vector<int> v;
	v.push_back(12);
	v.push_back(52);
	v.push_back(7);
	v.push_back(33);
	v.push_back(75);
	v.push_back(11);
	v.push_back(53);
	v.push_back(3);
	
	selection_sort(v);
	for (int k=0; k<v.size(); k++)
	{
		cout<<v[k]<<"\t";
	}
	cout<<"\n";
	return 0;
}