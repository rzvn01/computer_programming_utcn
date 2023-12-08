/*Cacu Razvan lab4 ex5 
Add some new sorting methods to the code presented in the examples area (example 2 - selection sort, shell
sort, etc.). Read from the keyboard the 
number of elements from the array and pass it as parameter to each
sorting function. Compare the working times scored by each implemented sorting algorithm using huge arrays.
Use comments for displaying method. Enter a timer (1-5 seconds) among the sorting methods in main().
*/
#include<iostream>
int* first, n;
void quickSort(int, int);
void bubblesort();
void randomize();
void selectionsort();
void swap(int,int);
void insertionSort();
int main()
{
	std::cout << "\nEnter the size of the array : ";
	std::cin >> n;
	first = new int[n];
	bubblesort();
	selectionsort();
	insertionSort();
	randomize();
	clock_t start = clock();
	quickSort(0, n - 1);
	clock_t end = clock();
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	std::cout << "\nQuick sort time : " << cpu_time_used << "seconds .";
}
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionsort()
{
	randomize();
	clock_t start = clock();
	int i, j, min_idx;


	for (i = 0; i < n - 1; i++)
	{
	
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (first[j] < first[min_idx])
				min_idx = j;

		
		swap(&first[min_idx], &first[i]);
	}
	clock_t end = clock();
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	std::cout << "\nSelection sort time : " << cpu_time_used << "seconds .";
}

void bubblesort()
{
	randomize();
	clock_t start = clock();

	for (int i = 0; i <n; i++) {
		for (int j = i + 1; j < n; j++)
		{
			if (first[j] < first [i]) {
				int temp = first[i];
				first[i] = first[j];
				first[j] = temp;
			}
		}
	}
	clock_t end = clock();
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	std::cout << "\nBubble sort time : " << cpu_time_used << "seconds .";
}
void randomize()
{
	
	for (int i{}; i < n; i++)
		first[i] = rand() % 1000 + 1;
}
void insertionSort()
{
	randomize();
	clock_t start = clock();

	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = first[i];
		j = i - 1;

		while (j >= 0 && first[j] > key)
		{
			first[j + 1] = first[j];
			j = j - 1;
		}
		first[j + 1] = key;
	}
	clock_t end = clock();
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	std::cout << "\n Insertion  sort time : " << cpu_time_used << "seconds .";
}
void quickSort(int prim, int ultim) {
	

	int i, j, pivot, temp;
	i = prim;
	j = ultim;
	pivot = first[ultim];

	do {
		while (first[i] < pivot)
			i++;
		while (first[j] > pivot)
			j--;
		if (i < j) {
			temp = first[i];
			first[i] = first[j];
			first[j] = temp;
		}
		if (i <= j) {
			j--;
			i++;
		}
	} while (i < j);

	if (prim < j)
		quickSort(prim, j);
	if (i < ultim)
		quickSort(i, ultim);

}