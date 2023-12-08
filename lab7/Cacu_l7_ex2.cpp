/*Cacu Razvan lab7 prb2 
Write a C/C++ application that models in OOP a real numbers one dimensional array.
Instantiate two objects of this class with the same length n and store in a third one the results
of subtracting each of the two real number arrays’ elements. If the source arrays have different
lengths, the result has the length of the shortest array*/

#include<iostream>
using namespace std;

class RealNumber {
	int* arr{};
	int lenght=1;
public: 
	RealNumber(int lenght) { // explicit constructor
		
		arr = new(std::nothrow) int[lenght];
	}
	RealNumber() {};//implicit constructor 

	~RealNumber()
	{
		if (this->arr != NULL)
			delete[] arr;
	}

	void setLenght(int aux) { lenght = aux; }
	int getLenght() { return this->lenght; }
	void setArr(int* x);
	int* getArr() { return this->arr; }
	int* substract(int* arr,int*arr2);


};

int* readArray(int lenght );  // i like to name the variables in headers 
void printArray(int * arr  ,int lenght);

int main() {
	int size1, size2;
	cout << "Enter the size for the first array : ";
	cin >> size1;
	cout << "Enter the size for the second array : ";
	cin >> size2;
	int aux;
	(size1 > size2)
		? aux = size2
		: aux = size1;

	RealNumber first(size1), second(size2), third(aux);
	first.setLenght(size1);
	second.setLenght(size2);
	third.setLenght(aux);

	first.setArr(readArray(first.getLenght()));
	second.setArr(readArray(second.getLenght()));

	cout << "\n The elements of the first Obj are : ";
	printArray(first.getArr(),first.getLenght());
	cout << "\nThe elements of the second Obj are : ";
	printArray(second.getArr(),second.getLenght());
	int* arr1 = first.getArr(), * arr2 = second.getArr();
	third.setArr(third.substract(arr1,arr2));
	cout << "\nThe elements after the substraction are  : ";
	printArray(third.getArr(),third.getLenght());
	cout << " and the  lenght of the  array is : " << third.getLenght();
}
void RealNumber::setArr(int* aux)
{
	for (int i{}; i < this->lenght; i++)
		arr[i] = aux[i];
}

int* RealNumber::substract(int* arr,int* arr2){ 
	
	int *s = new(nothrow)int[this->getLenght()];
	for (int i{}; i < this->getLenght(); i++)
		s[i] = arr[i] - arr2[i];
	return s;
}

int* readArray(int lenght) 
{
	int* arr = new(nothrow)int[lenght];
	cout << "\nEnter the elements of the array : ";
	for (int i{}; i < lenght; i++)
		cin >> arr[i];
	return arr;
	
}

void printArray( int*arr,int lenght)
{
	for (int i{}; i < lenght; i++)
		cout << arr[i] << " ";
}
