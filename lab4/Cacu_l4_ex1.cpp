/*Cacu Razvan lab4 prb1
Implement the Bubble-Sort method using a flag indicator and optimize the inner loop. Write the function that
orders an array of integer values read from the keyboard. Display the original and the sorted arrays.
*/
#include<iostream>
using namespace std;
void data_print(int);
void data_read(int);
void BubbleSort(int);
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
	BubbleSort(n);
	cout << "\nThe sorted array is : ";
	data_print(n);
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



void BubbleSort(int n)
{
	int aux;
	bool sorted = true;
	while (sorted) {
		sorted = false;
		for (int i{}; i < n-1; i++)
			
				if (arr[i] >arr[i+1])
				{
					aux = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = aux;
					sorted = true;
				}
		
	} 
}
