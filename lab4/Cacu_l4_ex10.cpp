/*Cacu Razvan lab4 prb10
Generate 200 random float values. Store the integer parts (not bigger than 100) into an array. The fractional
parts (limited at 20 as an integer value representing a 0.20 fractional part) are stored into another array with the
same size as the first one. The initial values re-calculated by combining the elements stored into the previously
described arrays are stored into another vector. Display all the arrays. Use the  library function for
storing the float values and display the final result
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define Lenght 200

int main()
{
	srand(time(NULL));
	vector<float> first, second, third;
	float value, value1;
	for (int i{}; i < Lenght; i++)
	{
		value = rand() % 100 + 1;
		first.push_back(value);
		value1 = (float)(rand() % 20 + 1) / 100;
		second.push_back(value);
		value += value1;
		third.push_back(value);
	}
	sort(third.begin(), third.end());
	for (int i{}; i != Lenght; i++)
		cout << endl << third[i];
}