#include<iostream>
#include<queue>

template <typename T>
class Stack
{
public:
	void Push(T value)
	{
		_source.push(value);
		_size++;
	}
	
	T Top()
	{
		T value;
		std::queue<T> temp;
		for(int i = 0; i < _size - 1; i++)
		{
			temp.push(_source.front());
			_source.pop();
		}
		value = _source.front();
		
		temp.push(value);
		_source = temp;
		
		return value;
	}
	
	void Pop()
	{
		std::queue<T> temp;
		for(int i = 0; i < _size - 1; i++)
		{
			temp.push(_source.front());
			_source.pop();
		}
		_source = temp;
		_size--;
	}
private:
	std::queue<T> _source;
	unsigned _size;
};

int main()
{
	Stack<int> myStack;
	myStack.Push(1);
	myStack.Push(2);
	myStack.Pop();
	std::cout << myStack.Top();
	
	return 0;
}
