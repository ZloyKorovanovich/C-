#include <iostream>

class DynamicArray
{
private: 
	int* array;
	int maxLength;
	int length;
	
public:
	
	DynamicArray(int[], int lemgth);
	
	void Add(int element, int scaleIncrese);
};



void DynamicArray::Add(int element, int scaleIncrease)
{
	if(length == maxLength)
	{
		maxLength += scaleIncrease;
		int* array2 = new int[maxLength];
		for(int i = 0; i < length; i++)
		{
			array2[i] = array[i];
		}
		delete array;
		array = array2;
	}
	array[length] = element;
	length++;
}
operator [](int index) // Fix
{
	if(index >= length)
		index = length-1;
	return array[index];
}



int main()
{
	return 0;
}
