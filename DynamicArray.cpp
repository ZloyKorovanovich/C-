#include <iostream>
#include <string>

template<typename T>
class DynamicArray
{
public:
	
	DynamicArray(T* element, unsigned size)
	{
		_sourceArray = element;
		_size = size;
		_capacity = size * 2;
	}
	
	DynamicArray(T* element, unsigned size, unsigned capacity)
	{
		_sourceArray = element;
		_size = size;
		_capacity = capacity;
	}
	
	DynamicArray()
	{
		_capacity = 2;
		_sourceArray = new T[0];
	}
	
	DynamicArray(unsigned capacity)
	{
		_capacity = capacity;
		_sourceArray = new T[0];
	}
	
	DynamicArray(DynamicArray& rght) = delete;
	DynamicArray(DynamicArray&& rght) = delete;
	
	DynamicArray& operator=(DynamicArray& rght) = delete;
	
	~DynamicArray()
	{
		delete[] _sourceArray;
	}
	
	void Add(T element)
	{
		PrivateAdd(element, 2);
	}
	
	void Add(T element, unsigned capacityMultiplier)
	{
		PrivateAdd(element, capacityMultiplier);
	}
	
	T operator[](unsigned index) const
	{
		return _sourceArray[index];
	}
	
	unsigned Size() const
	{
		return _size;
	}
	
	unsigned Capacity() const
	{
		return _capacity;
	}
	
private:
	
	unsigned _size;
	unsigned _capacity;
	T* _sourceArray;
	
	void PrivateAdd(T element, unsigned capacityMultiplier)
	{
		if(_size == _capacity)
		{
			_capacity *= capacityMultiplier;
			T* tmp = new T[_capacity];
			
			for(int i = 0; i < _size; i++)
				tmp[i] = _sourceArray[i];
					
			delete[] _sourceArray;
			_sourceArray = tmp;
		}
		
		_sourceArray[_size] = element;
		_size++;
	}
	
};

int main()
{
	DynamicArray<int> myArray();

	
	int input;
	
	while(std::cin>>input)
	{
		myArray.Add(int(input));
	}

	
	for(int i = 0; i < myArray.Size(); i++)
	{
		std::cout << myArray[i];
		std::cout << std::endl;
	}
	
	return 0;
}
