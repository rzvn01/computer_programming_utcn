/*Cacu Razvan lab5 prb5 
Define a class that implements the following methods:
- int plus(int x, int y), which returns the sum of x and y;
- int minus(int x, int y), which returns the difference between x and y;
- int inmultit(int x, int y), which returns the result of x multiplied by y;
- float impartit(int x, int y), which returns the quotient of x and y;
Write the application that uses this class. Consider also the case that the class contains two int
attributes, x and y, and the class methods will have no parameters
*/

#include<iostream>
#include<assert.h>
using namespace std;


class Numbers {
	int x, y;
public:
	Numbers(int a=1, int b=2) {
		cout << "\nConstructor called ...";
	    x = a; 
		y=b;
	}
	
	~Numbers() { cout << "\nDestructor called ... "; }
	void setX(int a) { x = a; }
	int getX() { return x; }
	void setY(int a) { y = a; }
	int getY() { return y; }

	int plus() { return x + y; }
	int minus() { return x - y; }
	int inmultit() { return x * y; }
	float impartit() { return (float)x / y; }

 };


int main()
{
	int a, b;
	cout << "\nEnter the value of x : ";
	cin >> a;
	cout << "\nEnter the value of y  : ";
	cin >> b;
	assert(b != 0);
	Numbers n1;
	Numbers n2(a, b);
	cout << "\nFor implicit parameters .. ";
	cout << " \nThe sum is : " << n1.plus() << "\nThe difference is : " << n1.minus() << "\nThe product is : " << n1.inmultit() << "\nThe division is :  " << n1.impartit();
	cout << "\nFor explicit parameters .. ";
	cout << " \nThe sum is : " << n2.plus() << "\nThe difference is : " << n2.minus() << "\nThe product is : " << n2.inmultit() << "\nThe division is :  " << n2.impartit();
}