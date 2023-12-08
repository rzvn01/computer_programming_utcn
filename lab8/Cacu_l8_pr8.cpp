/*Cacu Razvan lab8 prb8
Consider the Fraction class that has two private integer attributes a and b for the denominator and
nominator. Use two setter and getter methods for all the class’s attributes. Declare a friend function named
simplify( ) that receives as parameter a Fraction object and returns the corresponding simplified object.
Consider a private static integer variable icount that will be initialized with 0 and incremented in the
class’s constructors. Define an explicit constructor without parameters that initializes a with 0 and b with
1 and another explicit constructor with two integer parameters. For this constructor is verified if b!=0
before to be called. Define an explicit destructor that displays and decrements the value of icount. Define a
friend function f_add_fraction(...) that returns an object reflecting the sum of the objects received as
parameters. Implement similar functions for fractions subtraction, multiplication and division. Instantiate
two Fraction objects and read the appropriate data from the keyboard. Display the initial attributes and the
ones obtained after simplifying. Call the implemented friend functions and store the results into another
different four objects. Display the results and the objects counter using the corresponding accesor
methods*/

#include<iostream>
#include<assert.h>
using namespace std;

class Fraction {
	int nominator, denominator;
	static int icount;
public : 
	void setNominator(int a) {
		nominator = a;
	}
	int getNominator() {
		return nominator;
	}

	void setDenominator(int a) {
		denominator = a;
	}
	int getDenominator() {
		return denominator;
	}
	Fraction() {
		cout << "\nVoid constructor called !";
		nominator = 0;
		denominator = 1;
		icount++;
	}
	Fraction(int a, int b) {
		cout << "\nExplicit constructor called !";
		nominator = a;
		denominator = b;
		icount++;
	}
	~Fraction() {
		cout << "\nDestructor called !";
		icount--;
		cout << "\n The value of icount : " << icount;
	}
	friend Fraction simplify(Fraction &f1);
	friend Fraction f_add_fraction(Fraction &f1,Fraction& f2);
	friend Fraction f_substract_fraction(Fraction &f1,Fraction& f2);
	friend Fraction f_product_fraction(Fraction &f1, Fraction &f2);
	friend Fraction f_division_fraction(Fraction  &f1, Fraction &f2);





};
int gcd(int a, int b);
 int Fraction::icount=0;
int main() {
	Fraction f1(3, 5), f2(5, 14), f3, f4;
	int val;
	cout << "\nEnter the nominator of the third fraction :";
	cin >> val;
	f3.setNominator(val);
	cout << "\nEnter the denominator of the third fraction :";
	cin >> val;
	assert(val != 0);
	f3.setDenominator(val);
	cout << "\nEnter the nominator of the fourth fraction :";
	cin >> val;
	f4.setNominator(val);
	cout << "\nEnter the denominator of the fourth fraction :";
	cin >> val;
	assert(val != 0);
	f4.setDenominator(val);


	Fraction sum = f_add_fraction(f1,f2);
	Fraction subs = f_substract_fraction(f1, f3);
	Fraction prod = f_product_fraction(f2, f4);
	Fraction div = f_division_fraction(f3, f4);

	cout << "\n\n\nThe result of the sum is : " << sum.getNominator() << "/" << sum.getDenominator();
	cout << "\nThe result of the substract is : " << subs.getNominator() << "/" << subs.getDenominator();
	cout << "\nThe result of the product  is : " << prod.getNominator() << "/" << prod.getDenominator();
	cout << "\nThe result of the division is : " << div.getNominator() << "/" << div.getDenominator();
}

Fraction simplify(Fraction &f1)
{

	Fraction f2;
	f2.nominator=(f1.getNominator() /gcd(f1.nominator, f1.denominator));
	f2.denominator=(f1.getDenominator() / gcd(f1.nominator, f1.denominator));
	cout << "\nFraction simplified !";
	return f2;

}

Fraction f_add_fraction(Fraction &f1, Fraction& f2)
{
	Fraction aux;
	aux.nominator = f1.nominator*f2.denominator+f2.nominator*f1.denominator;
	aux.denominator = f1.denominator*f2.denominator;
	aux = simplify(aux);
	return aux;
}
Fraction f_substract_fraction(Fraction& f1, Fraction &f2)
{
	Fraction aux;
	aux.nominator = f1.nominator * f2.denominator - f2.nominator * f1.denominator;
	aux.denominator = f1.denominator * f2.denominator;
	aux = simplify(aux);
	return aux;
}
Fraction f_product_fraction(Fraction &f1, Fraction &f2) {
	Fraction aux;
	aux.nominator = f1.nominator * f2.nominator;
	aux.denominator = f1.denominator * f2.denominator;
	aux = simplify(aux);
	return aux;
}
Fraction f_division_fraction(Fraction& f1, Fraction &f2) {
	Fraction aux;
	aux.nominator = f1.nominator * f2.denominator;
	aux.denominator = f1.denominator * f2.nominator;
	aux = simplify(aux);
	return aux;
}

int gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b % a, a);
}