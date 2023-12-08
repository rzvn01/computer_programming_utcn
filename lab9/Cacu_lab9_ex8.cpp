/*Cacu Razvna lab9 prb8
Write the program that uses a class called Calculator that has as overloaded public methods:
- int calcul(int x) that returns the square value of x;
- int calcul(int x, int y) that returns the product of x and y;
- double calcul(int x, int y, int z) that returns the result of f(x,y,z) = (x-y)(x+z)/2.;
The program receives the parameters from the command line.
Consider the case when all the methods are static. Is it possible to have in the same time static and non-static
public methods? Analyze the case that the class has 3 private attributes of type int, x, y, z, that are modified
with setter adequate methods. What must be modified to perform the required operations?
*/


#include<iostream>
using namespace std;

class Calculator {
	int x, y, z;
public: 

	void setX(int a) { x = a; }
	int getX() { return x; }

	void setY(int a) { y = a; }
	int getY() { return y; }
	
	void setZ(int a) { z = a; }
	int getZ() { return z; }


	int calcul(int a) { return a * a; };
	int calcul(int a, int t) { return a * t; } 
	double calcul(int x, int y, int z) { return (x - y)*(x + z) / 2; } 
};

int main(int argc, char* argv[])
{
	Calculator c1;
	
	c1.setX(atoi(argv[1]));
	c1.setY(atoi(argv[2]));
	c1.setZ(atoi(argv[3]));
	cout << "\nThe value of x is : " << c1.getX();
	cout << "\nThe value of y is : " << c1.getY();
	cout << "\nThe value of z is : " << c1.getZ();
	cout << "\n The calcul function called with 1 parameter(x): " << c1.calcul(c1.getX());
	cout << "\n The calcul function called with 2 parameter(15,y): " << c1.calcul(15,c1.getY());
	cout << "\n The calcul function called with 3 parameter(x,y,z): " << c1.calcul(c1.getX(),c1.getY(),c1.getZ());
}
/*to make the last part  : - added setters/getters , made 3 private int variables , used the getters in main  */