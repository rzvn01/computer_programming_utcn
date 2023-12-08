/*Cacu Razvan lab3 prb 9 
Write a C/C++ application that generates max 10 integer random values and stores them in an array. Check if
another randomly generated value belongs to this array, using _lsearch() function*/

#include<iostream>
using namespace std;
int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main()
{
	int arr[11], value, result,size=10;
	srand(time(NULL));
	for (int i{};i<10;i++)
	{
		arr[i] = rand() % 100+ 1;
	}
	value = rand() % 100 + 1;
	for (int i{}; i < size; i++)
		cout << arr[i] << "\n";
	result = (int)_lsearch(&value, arr, (unsigned*)&size, sizeof(int), cmpfunc);
	(size != 11)
		? cout << "The value " << value << " was found in the array "
		: cout<<"The value  " << value <<" was not found in the array !"  ;
}