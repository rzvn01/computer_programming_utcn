/*Cacu Razvan lab3 prb11 
Read from the keyboard a one-dimensional array of maximum 20 integer values. Using the binary search
mechanism, determine if another value a (also read from the standard input) is part of the array. If so
determine and display all its prime factors.
*/
#include<iostream>
using namespace std;
bool isprime(int);
int compareints(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	int* arr, size, value, * result;
	cout << "Size of the array : ";
	cin >> size;
	arr = new int[size];
	
	cout << "Enter the values  : ";
	for (int i{}; i < size; i++)
		cin >> arr[i];

	cout << "The value you want to find : ";
	cin >> value;
	result= (int*)bsearch(&value, arr, size, sizeof(int), compareints);

	if (result != NULL)
	{
		for (int i{2}; i < value; i++)
		{
			if (value % i == 0 && isprime(i) == true)
				cout << " " << i;
		}
	}

}

bool isprime(int n)
{
	bool flag = true;
	{
		for (int i = 2; i <=n / 2; i++)
			if (n % i == 0)
				flag = false;


				
		return flag;
	}
}