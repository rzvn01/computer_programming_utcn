/*Cacu Razvan lab5 prb4
Write a program that implements a class called Number with an attribute of int type, val. In function
main(), declare two Number objects and a pointer to one object of this type, used to call a method int
sum_nr(Number) from the class that will calculate and return the sum of 2 int numbers read from the
keyboard, associated to the instantiated objects (current, parameter). Implement the method inside and
outside the class (with different names).
*/

#include<iostream>
#include<Windows.h>
using namespace std;
#define Time1 1000
class Number {
	int first, second;
public:
	void setFirst(int a) {
		first = a;
	}
	int getFirst() {
		return first;
	}
	
	void setSecond(int a) {
		second = a;
	}

	int getSecond() {
		return first;
	}
	int sum();
	int sum2() { return first + second; }
};



int Number::sum() {return first + second; } 


int main()
{
	Number n1, n2;
	Number* n3 = new (nothrow)Number[1];
      int value;
	cout << "Enter the fist number :";
	cin >> value;
	n1.setFirst(value);
	cout << "Enter the second  number :";
	cin >> value;
	n1.setSecond(value);
	cout << "The sum is :  " << n1.sum();
	cout << "\nPlease wait ...";
	Sleep(3 * Time1);
	system("cls");

	cout << "Enter the fist number :";
	cin >> value;
	n2.setFirst(value);
	cout << "Enter the second  number :";
	cin >> value;
	n2.setSecond(value);
	cout << "The sum is :  " << n2.sum();
	cout << "\nPlease wait ...";
	Sleep(3 * Time1);
	system("cls");

	cout << "Enter the fist number :";
	cin >> value;
	n3->setFirst(value);
	cout << "Enter the second  number :";
	cin >> value;
	n3->setSecond(value);
	cout << "The sum is :  " << n3->sum();

}