#include <iostream>

template <typename T>
class Node
{
public:
	
	Node(T value, Node* previous)
	{
		_value = value;
		_previous = previous;
	}
	
	
	T GetValue()
	{
		return _value;
	}
	
	void SetValue(T value)
	{
		_value = value;
	}
	
	
	Node* GetPrevious()
	{
		return _previous;
	}
	
	void SetPrevious(Node* node)
	{
		_previous = node;
	}
	
private:
	
	T _value;
	Node* _previous;
	
};

template <typename T>
class Stack
{
public:
	
	Stack()
	{
		_last = nullptr;
		_size = 0;
	}
	
	Stack(Stack& right) = delete;
	Stack(Stack&& right) = delete;
	
	Stack& operator=(Stack& right) = delete;
	
	~Stack()
	{
		Clear();
	}
	
	unsigned Size()
	{
		return _size;
	}


	void Add(T value)
	{
		Node<T>* newNode = new Node<T>(value, _last);
		_last = newNode;
		_size++;
	}
	
	void RemoveLast()
	{
		Node<T>* preLastNode = _last->GetPrevious();
		delete _last;
		_last = preLastNode;
		_size--;
	}
	
	void Clear()
	{
		int size = _size;
		for(int i = 0; i < size; i++)
		{
			RemoveLast();
		}
	}
	
	T GetLast()
	{
		return _last->GetValue();
	}
	
	T operator[](unsigned index) const
	{
		if(index > _size - 1)
			index = _size - 1;
		index = _size - index - 1;
		Node<T>* currentNode = _last;
		for(int i = 0; i < index; i++)
			currentNode = currentNode->GetPrevious();
		return currentNode->GetValue();
	}

private:

	Node<T>* _last;
	unsigned _size;
	
};


int main()
{
	
	return 0;
}
