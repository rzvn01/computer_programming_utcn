/*Cacu Razvan lab4 prb9 
Generate in a random mode maximum 200 smaller than 100 integer numbers and store them into an array.
Determine and display the minimum, the median and the maximum value and sort the array in order to
accomplish that. Determine the average value and display the difference between it and the calculated median.
Check if the average value is part of the initial array.
*/
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define Lenght 200

int main()
{
	srand(time(NULL));

	vector<int>xf;
	int aux, sum = 0, value;
	for (int i{}; i < Lenght; i++){
		value = rand() % 100 +1;
		sum += value;
		xf.push_back(value);	}

	sort(xf.begin(), xf.end());
	cout << "\nThe min : " << xf[0] << "\nThe median : " << xf[Lenght / 2] << " \nThe max : " << xf[Lenght-1];
	int avg = sum / Lenght;
	cout << "\n The diference between the median value and maximum value is : " << mod(xf(Lenght / 2) - xf(Lenght - 1));
	bool is = false;
	for (int i{};i<Lenght;i++)
		if (avg ==xf[i]){
			is = true;	break;}
	cout << "\nThe avg  is : " << avg;
	(is)
		? cout << " and is a part of the array !"
		: cout << " and is not a part of the array ! ";
}