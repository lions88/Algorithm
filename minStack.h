/*
 *	liliang 2011/3/18
 *	fileName:minStack.h
 *	description:满足条件：min，push，pop操作的时间复杂度为O(1)。
 */

#ifndef MINSTACK_H_
#define MINSTACK_H_


template<typename T, int size=100>
class MinStack
{
public:
	MinStack():top_arr(0),top_min(0){}
	bool empty()const { return (top_arr==0) ? true:false; }
	bool full()const { return (top_arr==size) ? true:false; }
	const T& top()const;
	const T& min()const;
	void push(const T& val);
	T pop();

private:
	T arr[size];
	int min_index[size];					//辅助的索引数组
	int top_arr,top_min;
};

template<typename T, int size>
const T & MinStack<T,size>::top()const
{
	if (!empty())
		return arr[top_arr];	
}

template<typename T, int size>
const T & MinStack<T,size>::min()const
{
	if (!empty())
		return arr[min_index[top_min-1]];		//min_index[top_min].....min_index[0]依次存储arr最小值的下标，第二小的，第三小的.......
}

template<typename T, int size>
void MinStack<T,size>::push(const T&val)
{
	if (full())
		return;
	
	if (empty() || val<min())					//val大于min_index[top_min]时，不压入索引数组
	{											//栈的第一个元素下标必须存入索引数组
		min_index[top_min++] = top_arr;			//min_index[top_min]存储arr数组中最小元素的下标
	}
	arr[top_arr++] = val;
}

template<typename T, int size>
T MinStack<T,size>::pop()
{
	if (!empty())
	{
		T result = arr[--top_arr];

		if (top_arr == min_index[top_min-1])
		{
			top_min--;
		}
		return result;
	}
	
}



#endif  /*MINSTACK_H_*/
