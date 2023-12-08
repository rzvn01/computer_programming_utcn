/*Cacu Razvan lab5 prb7 
* Write a program that implements a class named Arithmetics that has two numeric (int, float or
double) attributes a and b. The class will contai setter and getter methods for attributes. Inside the class,
implement a method named sum( ). The method difference() that also belongs to the class is
implemented outside the class, methods that will be called using Arithmetics objects. Create 3 objects
instantiated from the Arithmetics class and make use of the defined methods. The methods return the
numerical values corresponding to the operation using the two attributes of the class results that will be
displayed in main(). For each addition / subtraction operation group, display the values of the object
attributes using the getter methods*/


#include<iostream>
using namespace std;

class Arithmetics {
	int a, b;
public:
	void setA(int x) { a = x; }
	int getA() { return a; }
	void setB(int x) { b = x; }
	int getB() { return b; }
	void sum(Arithmetics x) {
		a += x.a;
		b += x.b;
	}
	void difference(Arithmetics);
};
void Arithmetics::difference(Arithmetics x) {
	a -= x.a;
	b -= x.b;
}
int main() {
	Arithmetics a1{}, a2{}, a3{};
	int a, b;
	cout << "Enter x & y for the first object : ";
	cin >> a >> b;
	a1.setA(a);
	a1.setB(b);
	cout << "Enter x & y for the second object : ";
	cin >> a >> b;
	a2.setA(a);
	a2.setB(b);
	cout << "Enter x & y for the third object : ";
	cin >> a >> b;
	a3.setA(a);
	a3.setB(b);

	a1.sum(a2);
	a = a1.getA();
	b = a1.getB();
	cout << "\n After the operations for object 1  x =" << a << " y=" << b;
	a1.difference(a3);
	a = a1.getA();
	b = a1.getB();
	cout << " \n After the operations for object 1 x = " << a << " y=" << b;
	a2.sum(a3);
	
	a = a2.getA();
	b = a2.getB();
	cout << " \nAfter the operations for object 2 x = " << a << " y=" << b;
}