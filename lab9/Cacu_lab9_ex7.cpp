/*Cacu Razvna lab9 prb7
 Write the program that considers a MyClass class with three int-type attributes. The class considers on the
basis of the overload mechanism public methods int myFunction (…), which depending on the number of
parameters received, returns either the value received (1 parameter) or the product of the input variables (0- all,
2, 3 parameters). Instantiate an object of the class in main(), set the attributes using dedicated setter methods
from the class, and display the values at method calls.*/


#include<iostream>
using namespace std;


class MyClass {
	int x, y, z;
public: 
	void setX(int a) {
		x = a;
	}
	int getX() {
		return x;
	}
	void setY(int a) {
		y = a;
	}
	int getY() {
		return y;
	}
	void setZ(int a) {
		z = a;
	}
	int getZ() {
		return z;
	}
	int myFunction(int a) {
		return a;
	}
	int myFunction() {
		return x * y * z;
	}
	int myFunction(int a, int b) {
		return a * b;
	}
	int myFunction(int a, int b, int c) {
		return a * b * c;
	}
};

int main() {
	MyClass m1;
	m1.setX(10);
	m1.setY(5);
	m1.setZ(2);
	cout << "\nThe value of x is : " << m1.getX();
	cout << "\nThe value of y is : " << m1.getY();	
	cout << "\nThe value of z is : " << m1.getZ();
	cout << " \nThe result of calling the void function : " << m1.myFunction();
	cout << " \nThe result of calling the  function  with 1 parameter : " << m1.myFunction(13);
	cout << " \nThe result of calling the  function  with 2 parameter : " << m1.myFunction(m1.getY(), 3);
	cout << " \nThe result of calling the  function  with 3 parameter : " << m1.myFunction(m1.getX(), 3,m1.getZ());

}