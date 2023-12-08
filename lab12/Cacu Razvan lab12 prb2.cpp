/*Cacu Razvan lab12 prb2 
* Write a C++ application that reads from the keyboard a series of values of various types.
Display the values using the standard manipulators.*/

#include<iostream>
#include<iomanip>
using namespace std; 

int main() {
	int a;
	float b;
	char c;

	cout << "\n a int value : ";
	cin >> a;
	cout << "\n a float value : ";
	cin >> b;
	
	cout << "\n a  char : ";
	cin>>c;

	cout << setbase(10) << right << setw(15)<< setfill('_') << showpos<< fixed << setprecision(2);
	
	cout << a << endl << flush;
	cout << scientific << uppercase<< noshowpos << setprecision(9);
	cout << b << endl << flush;
	cout.width(15);
	cout << hex << std::right << showbase << nouppercase << setfill('_') << setprecision(6);
	cout << c;

}