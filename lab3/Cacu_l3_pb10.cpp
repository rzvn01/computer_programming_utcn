/*Cacu Razvan lab3 prb 10
. Write a C/C++ application that finds and displays the images that represent the closest match to a certain
searching key. The searching key is stored in each image's header and it is represented using a structure with
the following fields: a filename (string of characters), a path (string of characters), an intensity resolution
(integer value) and a dimension in bytes (integer value). Use a different searching technique for each key type.
The headers are either stored into a file or the correspondent data is read from the keyboard.*/


#include<iostream>
#include<search.h>
using namespace std;


struct Images {

	char filename[30];
	char path[50];
	int resolution;
	int dimension;

}*arr;

int cmp1(const void*, const void*);
int cmp2(const void*, const void*);

void images_read(int);
void images_print( int);

int main()
{
	Images* result, * result2;
	int size, key2;
	char key1[30];
	cout << "Enter the number of the photos : ";
	cin >> size;

	arr = new Images[size];

	
	images_read(size);

	for (int k{}; k < size; k++)
	images_print(k);
	getchar();
	cout << "\n Enter the key1 (filename ) ";
	cin.getline(key1, 30);
	result = (Images*)_lfind(&key1, arr, (unsigned*)&size, sizeof(arr[0]), (int(*)(const void*, const void*))cmp1); 
	if (result != NULL)
	{
		cout << "\n  Images found : ";
		cout << " \n Filename : " << result->filename << " \n Path : " << result->path;
		cout << " \n Resolution : " << result->resolution << "\n Dimension : " << result->dimension;
	}
	else
		cout << "\nNo images found with the key : " << key1;
	cout << "\n Enter the second key (resolution): ";
	cin >> key2;
	result2 = (Images*)_lfind(&key2, arr, (unsigned*)&size, sizeof(arr[0]), (int(*)(const void*, const void*))cmp2);
	if (result2!= NULL)
	{
		cout << " \n Images found : ";
		cout << " \n Filename : " << result2->filename << " \n Path : " << result2->path;
		cout << " \n Resolution : " << result2->resolution << "\n Dimension : " << result2->dimension;
	}
	else
		cout << "\n No images found with the key : " << key2;
}

void images_read(int size)
{
	for (int i{}; i < size; i++) {
		getchar();
		cout << "\n \nFilename : ";
		cin.getline(arr[i].filename, 30);
		cout << "\n Path : ";
		cin.getline(arr[i].path, 50);
		cout << "\nResolution : ";
		cin >> arr[i].resolution;
		cout << "\nDimension : ";
		cin >> arr[i].dimension;

	}
}
void images_print( int t)
{
	cout << " \n Filename : " << arr[t].filename << " \n Path : " << arr[t].path;
	cout << " \n Resolution : " << arr[t].resolution << "\n Dimension : " << arr[t].dimension;
}
int cmp1(const void* arg1, const void* arg2)
{
	char* k = (char*)arg1;
	Images* s = (Images*)arg2;
	return strcmp(k, s->filename);
}
int cmp2(const void* arg1, const void* arg2)
{
	int* i = (int*)arg1;
	Images* s = (Images*)arg2;
	return (*i - s->resolution);
}