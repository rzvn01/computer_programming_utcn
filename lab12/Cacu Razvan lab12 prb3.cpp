/*Cacu Razvan lab12 prb3 
Consider a data acquisition process from a hardware device (10 variables real type). Display,
using an appropriate message, the data in a minimal format (the integer part). Determine the
average value of the displayed numbers (the integer part) and if it is greater than a previously
defined (or entered) threshold, display the data in a detailed format (float variables, 3 digits
precision at the fractional part).
*/
#include<iostream>
using namespace std;


int main() {


	float str[10];
	for (int i{}; i < 10; i++) {
		cout << "\n float value : ";
		cin >> str[i];
	}
	int sum = 0;
	for (int i{}; i < 10; i++)
	{
		cout << "\t" << (int)str[i];
		sum += (int)str[i];
	} 

	int value;
	cout << "\n Enter the value to compare with : ";
	cin >> value;
	if(sum/10>=value)
		for (int i{}; i < 10; i++) {
			cout << std::fixed;
			cout.precision(3);
			cout << str[i] << "\t";
		}

}