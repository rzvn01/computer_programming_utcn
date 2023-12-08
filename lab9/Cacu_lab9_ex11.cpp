/*Cacu Razvan lab9 prb11
Consider a class named Fraction that has two integer private attributes a and b for the denominator and
nominator. Define set( ) and get( ) methods for all the class’s attributes. Declare a method named simplify( )
that simplifies a fraction. Consider a private static integer variable icount that will be initialized with 0 and
incremented in the constructors. Declare two explicit constructors, one without parameters that initializes a
with 0 and b with 1 and the other that has two integer parameters which will verify before if the fraction can be
defined (b! =0). Define an explicit destructor that will display a message and the icount counter. Overload the
arithmetic operators (+, -, *, /) using friend functions. The results will be displayed after being simplified.
Instantiate 2 Fraction objects and read the appropriate data from the keyboard. Display the original values of
the nominators and denominators. Using a specific accessor method, display the value of icount. Apply the
implemented friend functions and initialize other 4 objects with the obtained results. Display the characteristics
of the final objects and the value of icount.
*/

#include <iostream>
#include<assert.h>
using namespace std;

int gcd(int, int);

class Fraction {

	int nominator, denominator;
	static int icount;

public:

	Fraction() {
		nominator = 0;
		denominator = 1;
		icount++;
	};
	Fraction(int a, int b) {
		nominator = a;
	denominator = b;
		icount++;
	}
	void setNominator(int a) {
		nominator = a;
	}

	int getNominator() {
		return nominator;
	}
	void setDenominator(int b) {
		this->denominator = b;
	}
	
	int getDenominator() {
		return denominator;
	}
	int getIcount() {
		return icount;
	}
	~Fraction() {
		icount--;
		cout << "\nThe value of icount is " << icount;
	
	}

	friend Fraction& simplify(Fraction&);
	friend Fraction& operator+(Fraction&, Fraction&);
	friend Fraction& operator-(Fraction&, Fraction&);
	friend Fraction& operator/(Fraction&, Fraction&);
	friend Fraction& operator*(Fraction&, Fraction&);

};

int  Fraction::icount=0;


int gcd(int a, int b) {
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

Fraction&simplify(Fraction& x) {
	int aux = gcd(x.nominator, x.denominator);
	x.nominator = x.nominator / aux;
	x.denominator = x.denominator / aux;
	return x;
}


Fraction& operator+(Fraction& x, Fraction& y) {
	Fraction res;
	
		res.nominator = (x.getNominator() * y.getDenominator()) + (y.getNominator() * x.getDenominator());
		res.denominator = (y.denominator * x.denominator);
	
    res=simplify(res);
	return res;
}

Fraction& operator-(Fraction& f1, Fraction& f2) {
	Fraction res;
		res.nominator = (f1.nominator * f2.denominator) - (f2.nominator * f1.denominator);
		res.denominator = (f2.denominator * f1.denominator);
	res=simplify(res);
	return res;
}

Fraction& operator/(Fraction& f1, Fraction& f2) {
	Fraction res;
	res.nominator=f1.nominator * f2.denominator;
	res.denominator=f1.denominator * f2.nominator;
	res=simplify(res);
	return  res;
}

Fraction& operator*(Fraction& f1, Fraction& f2) {
	Fraction res;
	res.denominator = f1.getDenominator() * f2.getDenominator();
	res.nominator = f1.getNominator() * f2.getNominator();
	res=simplify(res);
	return  res;
}

int main() {
	Fraction f1, f2;
	int var;
	cout << "\n The nominator of the first fraction : ";
	cin >> var;
	f1.setNominator(var);
	cout << "\n The denominator of the first fraction : ";
	cin >> var;
	assert(var != 0);
	f1.setDenominator(var);
	cout << "\n The nominator of the second fraction : ";
	cin >> var;
	f2.setNominator(var);
	cout << "\n The denominator of the second fraction : ";
	cin >> var;
	assert(var != 0);
	f2.setDenominator(var);
	cout << "\nThe first fraction is : " <<f1.getNominator() << "/" << f1.getDenominator();
	cout << "\nThe second  fraction is : " << f2.getNominator() << "/" << f2.getDenominator(); 
	Fraction add = f1 + f2;
	Fraction substract = f1 - f2;
	Fraction product = f1 * f2;
	Fraction division = f1 / f2;
	cout << "\n The result of adding the 2 fractions is : " << add.getNominator() << "/" << add.getDenominator();
	cout << "\n The result of substracting the 2 fractions is : " << substract.getNominator() << " / " << substract.getDenominator();
	cout << "\n The result of  the product between  the 2 fractions is : " << product.getNominator() << "/" << product.getDenominator();
	cout << "\n The result of the division between the 2 fractions is : " << division.getNominator() << "/" << division.getDenominator();

}