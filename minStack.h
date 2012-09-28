/*
 *	liliang 2011/3/18
 *	fileName:minStack.h
 *	description:����������min��push��pop������ʱ�临�Ӷ�ΪO(1)��
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
	int min_index[size];					//��������������
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
		return arr[min_index[top_min-1]];		//min_index[top_min].....min_index[0]���δ洢arr��Сֵ���±꣬�ڶ�С�ģ�����С��.......
}

template<typename T, int size>
void MinStack<T,size>::push(const T&val)
{
	if (full())
		return;
	
	if (empty() || val<min())					//val����min_index[top_min]ʱ����ѹ����������
	{											//ջ�ĵ�һ��Ԫ���±���������������
		min_index[top_min++] = top_arr;			//min_index[top_min]�洢arr��������СԪ�ص��±�
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
