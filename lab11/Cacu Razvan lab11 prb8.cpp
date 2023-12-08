/*Cacu Razvan lab11 prb8
Consider the Fraction class that has two protected attributes a and b for the nominator and
denominator and two corresponding setter and getter methods. Declare a virtual method
named simplify( ) that simplifies a fraction using the greatest common divider determined
using the % operator. Define an explicit constructor without parameters that initializes a with
0 and b with 1 and another explicit constructor with two integer parameters. For this
constructor is verified if b!=0 before to be called. Overload the addition, subtraction,
multiplication and division operators (+, -, *, /) using friend functions and simplify (if
necessary) the obtained results. Define a class named Fraction_ext that inherits in a public
mode the Fraction class and has a parameterized constructor that calls the constructor from
the base class. The derived class redefines the implementation of simplify( ) by determining
the greatest common divider using the differences based algorithm. Display an appropriate
message in this method. Overload the composed addition, subtraction, multiplication and
division operators (+=, -=, *=, /=) using member methods. Use member methods for
overloading the post-increment and post-decrement operators that will add 1 to the value of a
Fraction_ext instance. Instantiate 2 Fraction objects without parameters. Set the attributes
using values read from the keyboard. Perform the operations implemented with friend
functions from the base class and initialize another 4 objects with the obtained results.
Simplify the results. Instantiate two objects of Fraction_ext type with data from the KB.
Perform the implemented operations with the member functions and methods. Assign the
operation results to other 4 existing Fraction_ext objects. Use for operations copies of the
initial objects. Simplify and display the obtained results. Verify the possibility of using both
simplify( ) methods (base and derived class) using instances of the base and derived classes
and a pointer of Fraction type.*/

#include<iostream>
#include<assert.h>
using namespace std;

class Fraction {
protected:
	int a, b;
public:
	Fraction() {
		a = 0;
		b = 1;
	}
	Fraction(int nominator, int denominator) {
		a = nominator;
		b = denominator;
	}

	void setA(int aux) { a = aux; }
	int getA() { return a; }

	void setB(int aux) { b = aux; }
	int getB() { return b; }

	virtual Fraction simplify() {
		Fraction aux;
		int t = gcd(a, b);
		aux.setA(a / t);
		aux.setB(b / t);
		return aux;
	}
	virtual int gcd(int a, int b) {

		int minn = 1;
		for (int i = 1; i < min(a, b); i++)
			if (a % i == 0 && b % i == 0)
				minn = i;
		return minn;
	}
	friend Fraction operator+(Fraction& first, Fraction& second);
	friend Fraction operator-(Fraction& first, Fraction& second);
	friend Fraction operator*(Fraction& first, Fraction& second);
	friend Fraction operator/(Fraction& first, Fraction& second);

};
class Fraction_ext : public Fraction {
public:
	using Fraction::Fraction;

	int gcd(int a, int b) override
	{
		if (a == 0)
			return b;

		if (b == 0)
			return a;

		if (a == b)
			return a;

		if (a > b)
			return gcd(a - b, b);
		return gcd(a, b - a);
	}
	Fraction operator+(Fraction_ext& second) {
		Fraction aux;
		aux.setA(a * second.getB() + second.getA() * b);
		aux.setB(b * second.getB());
		aux = aux.simplify();
		return aux;
	}
	Fraction operator-(Fraction_ext& second) {
		Fraction aux;
		aux.setA(a * second.getB() - second.getA() * b);
		aux.setB(b * second.getB());
		aux = aux.simplify();
		return aux;
	}
	Fraction operator*(Fraction_ext& second) {
		Fraction aux;
		aux.setA(a * second.getA());
		aux.setB(b * second.getB());
		aux = aux.simplify();
		return aux;
	}
	Fraction operator/(Fraction_ext& second) {
		Fraction aux;
		aux.setA(a * second.getB());
		aux.setB(b * second.getA());
		aux = aux.simplify();
		return aux;
	}
	Fraction operator++(int x) {
		a = a + b;
		return *this;
	}
	Fraction operator--(int x) {
		a = a - b;
		return *this;
	}
};
int main() {
	Fraction_ext f1, f2;
	int value;
	cout << "\nEnter the nominator of the first fraction : ";
	cin >> value;
	f1.setA(value);
	cout << "\nEnter the denominator of the first fraction : ";
	cin >> value;
	assert(value != 0);
	f1.setB(value);
	cout << "\nEnter the nominator of the second fraction : ";
	cin >> value;
	f2.setA(value);
	cout << "\nEnter the denominator of the second fraction : ";
	cin >> value;
	assert(value != 0);
	f2.setB(value);

	Fraction res = f1 + f2;
	cout << "\nThe result of addition is :" << res.getA() << "/" << res.getB();
	res = f1 - f2;
	cout << "\nThe result of difference is :" << res.getA() << "/" << res.getB();
	res = f1 *f2;
	cout << "\nThe result of product is :" << res.getA() << "/" << res.getB();
	res = f1 / f2;
	cout << "\nThe result of division is :" << res.getA() << "/" << res.getB();
	res = f1--;;
	cout << "\nThe result of substracing 1 is :" << f1.getA() << "/" << f1.getB();
	res = f2++;;
	cout << "\nThe result of adding 1 is :" << f2.getA() << "/" << f2.getB();
}

Fraction operator+(Fraction& first, Fraction& second) {
	Fraction aux;
	aux.setA(first.a * second.b + second.a * first.b);
	aux.setB(first.b * second.b);
	aux = aux.simplify();
	return aux;
}
Fraction operator-(Fraction& first, Fraction& second) {
	Fraction aux;
	aux.a = first.a * second.b - second.a * first.b;
	aux.b = first.b * second.b;
	aux = aux.simplify();
	return aux;
}
Fraction operator*(Fraction& first, Fraction& second) {
	Fraction aux;
	aux.a = first.a * second.a;
	aux.b = first.b * second.b;
	aux = aux.simplify();
	return aux;
}
Fraction operator/(Fraction& first, Fraction& second) {
	Fraction aux;
	aux.a = first.a * second.b;
	aux.b = first.b * second.a;
	aux = aux.simplify();
	return aux;
}
