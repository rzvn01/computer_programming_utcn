/*Cacu Razvan lab4 prb2
Modify the program that implements the explicit Quick-Sort algorithm so that it will sort decreasingly the
initial array of values.*/

#include<iostream>
using namespace std;
void data_print(int);
void data_read(int);
void quicksort(int*, int, int);
int* arr;

int main()
{
	int n;
	cout << "\nEnter the size of the array : ";
	cin >> n;
	arr = new int[n];
	data_read(n);
	cout << "\nThe nonsorted array is : ";
	data_print(n);
	quicksort(arr,0,--n);
	cout << "\nThe sorted array is : ";
	data_print(++n);
}


void data_read(int n)
{
	cout << "\nEnter the values of the array  : \n";
	for (int i{}; i < n; i++)
		cin >> arr[i];

}

void data_print(int n)
{
	for (int i{}; i < n; i++)
		cout << arr[i] << " ";
}
void quicksort(int* p, int prim, int ultim) {
	int i, j, pivot, temp;
	i = prim;
	j = ultim;
	pivot = p[ultim];
	do {
		while (p[i] > pivot)
			i++;
		while (p[j] < pivot)
			j--;
		if (i < j) {
			temp = p[i];
			p[i] = p[j];
			p[j] = temp;
		}
		if (i <= j) {
			j--;
			i++;
		}
	} while (i < j);
	if (prim < j)
		quicksort(p, prim, j);
}



