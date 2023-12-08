/*Cacu Razvan lab4 prb8
Read from two files, two one dimensional arrays composed of real values. Generate a third array that contains
all the values from the initial arrays and all the values obtained by calculating the average of the corresponding
numbers. If the initial arrays have different numbers of values, the average is calculated between the existent
values and 0.0. Order the last array and count the number of non-unique elements.*/

#include<iostream>
#include<vector>
#include<fstream>
#include<assert.h>
#include<algorithm>

using namespace std;

int main()
{
	vector<float> first, second, third;
	ifstream file1, file2;

	float value, fs1, fs2, fs3;
	file1.open("numere1.txt", ios::in);
	file2.open("numere2.txt", ios::in);
	while(!file1.eof())
	{
		file1 >> value;
		first.push_back(value);
		third.push_back(value);
		

	}
	while (!file2.eof())
	{
		file2 >> value;
		second.push_back(value);
		third.push_back(value);
		
	}
	fs1 = first.size(); fs2 = second.size();
	if (fs1 > fs2)
	{
		fs3 = fs1;
		for (int i{}; i < fs1 - fs2; i++)
			second.push_back(0);
	}
	else if (fs1 < fs2)
	{
		fs3 = fs2;
		for (int i{}; i < fs2 - fs1; i++)
			first.push_back(0);
	}
	else
		fs3 = fs1;

	for (int i{}; i < fs3; i++)
	{
		value = (first[i] + second[i])/2;
		third.push_back(value);
	}
	sort(third.begin(), third.end());

	float aux = third.size();
	third.erase(unique(third.begin(), third.end()), third.end());

	cout << "The final array is : \n";
	for (auto& i : third)
		cout << endl << i;
	cout << "\nThere are " << aux - third.size() << " non unique values !";

	file1.close();
	file2.close();


}