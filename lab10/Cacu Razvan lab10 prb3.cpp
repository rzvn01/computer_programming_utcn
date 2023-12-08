/*Cacu Razvan lab10 prb3
Implement a class that has 2 protected integer variables, that contains a setter and getter
methods for each attribute. Write a second class that inherits the first defined class and
implements the elementary arithmetic operations (+, -, *, /) applied on the variables mentioned
above the results being returned by methods. Write a third class derived from the second one
that implements the methods for calculating the square root of a number (mul result obtained
by the previous derived class) received as parameter, and for raising a numeric value to a
certain power (the base (plus, result obtained by the previous derived class) and the power
(minus, result obtained by the previous derived class) are sent to the method as parameters).
Verify the methods’s calling using objects at different hierchies levels
*/

#include <iostream>
#include <math.h>
using namespace std;
class A {
protected: int a, b;
public:
	void setA(int a) {
		this->a = a;
	}
	void setB(int b) {
		this->b = b;
	}
	int getA() { return a; }
	int getB() { return b; }

};
class B : public A {
public:
	int sum() {
		return a + b;
	}
	int product() {
		return a * b;
	}
	int substract() {
		return a - b;
	}
	double division() {
		if (b != 0)
			return (float)a / b;
		else if (b == 0) {
			cout << "\nthe denominator can't be 0 !";
		}
	}
};
class C : public B {
public:
	float square() {
		return sum() * sum();
	}
	float power() {
		return pow(sum(), substract());
	}
};
int main()
{
	A a1;
	C c1;
	int aux;
	cout << "\nThe first value :  ";
	cin >> aux;
	a1.setA(aux);
	c1.setA(aux);
	
	cout << "\n The second value  ";
	cin >> aux;
	a1.setB(aux);
	c1.setB(aux);
	cout << endl;
	cout << "\nThe result of sum is : " << c1.sum();
	cout << "\nThe result of substract is : " << c1.substract();
	cout << "\nThe result of product is : " << c1.product();
	cout << "\nThe result of division is : " << c1.division();
	cout << endl<< c1.sum() << " squared is: " << c1.square() << endl;
	cout << endl<<c1.sum() << " to the power of " << c1.substract() << " is: " << c1.power() << endl;
}