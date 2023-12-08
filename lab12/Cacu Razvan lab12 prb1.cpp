/*Cacu Razvan lab12 prb1 
Write a C++ program that displays some numerical values in decimal, octal and hexadecimal.
Display the values left and right aligned, inside a field that can hold 15 characters. Use the
setfill( ) manipulator for setting the filling character and the width( ) and precision( ) methods
for setting the displaying field size and the values representation precision. 
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <iomanip>
using namespace std;


int main() {

	char field[15];
	cout << std::setfill('_') << std::setprecision(15);
	int a = 77;
	std::cout.width(15); std::cout << std::left << std::hex << a << '\n';
	std::cout.width(15); std::cout << std::right << std::oct << a << '\n';
	std::cout.width(15); std::cout << std::left << std::dec << a << '\n';
}