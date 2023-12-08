/*Cacu Razvan lab7 prb8
* Consider a class named Fraction that has two private integer attributes a and b for the
denominator and nominator, two set( ) and get( ) methods and a method simplify( ) that will
simplify the current calling Fraction object and will return as result a Fraction object.
simplify( ) method will call a private cmmdc( ) method to simplify the fraction. Define an
explicit constructor without parameters that initializes a with 0 and b with 1. Define another
explicit constructor that receives 2 integer parameters. For this constructor is verified if b!=0
before to be called. Define a method named add_fraction( ) that returns the object obtained by
adding the current object with the one received as parameter, as a Fraction object. Define in
the same manner the methods that subtract, multiply and divide two fractions. Instantiate two
Fraction objects having the corresponding data read from the keyboard. Display the initial
attributes and the ones obtained after simplifying the fractions. Call the methods that apply the
implemented arithmetical operations and display the results.*/

#include<iostream>
#include<assert.h>
using namespace std;

class Fraction {
	int denominator;
	int nominator; 
	int cmmdc(int denominator  ,int nominator);
public : 
	Fraction() {
		nominator = 0;
		denominator= 1;
	}
	Fraction(int x, int y) {
		nominator = x;
		denominator = y;
	}
	void setDenominator(int a) {
		denominator = a;
	}
	int getDenominator() {
		return denominator; 
	}
	void setNominator(int a) {
		nominator = a;
	}
	int getNominator() {
		return nominator;
	}
	Fraction simplify() {
		Fraction aux;
		aux.denominator = this->denominator / this->cmmdc(this->denominator,this->nominator);
		aux.nominator = this->nominator / this->cmmdc(this->denominator, this->nominator);
		return aux;
	}
	void add(Fraction f2);
	void substract(Fraction f2);
	void multiply(Fraction f2)
	{
		int num = ( this->nominator*f2.nominator);
		int denom = (this->denominator * f2.nominator);
		cout << endl << this->nominator << "/" << this->denominator << " * " << f2.nominator << "/" << f2.denominator << " = " << num << "/" << denom;
	}

};
int main() {
	Fraction f1, f2;
	int val;
	cout << "\nEnter the nominator of the first fraction : ";
	cin >> val;
	f1.setNominator(val);
	cout << "\nEnter the denominator  of the first fraction : ";
	cin >> val;	
	assert(val != 0);
	f1.setDenominator(val);
	cout << "\nEnter the nominator of the second fraction : ";
	cin >> val;
	f2.setNominator(val);
	cout << "\nEnter the denominator of the second fraction : ";
	cin >> val;
	assert(val != 0);
	f2.setDenominator(val);
	f1.add(f2);
	f1.substract(f2);
	f1.multiply(f2);
	Fraction f1Simplified = f1.simplify();
	cout << "\nThe first fraction is : " << f1.getNominator() << " /" << f1.getDenominator();
	cout << "\nThe first faction simplified is : " << f1Simplified.getNominator() << " / " << f1Simplified.getDenominator();
	Fraction f2Simplified = f2.simplify();
	cout << "\nThe second fraction is : " << f2.getNominator() << " /" << f2.getDenominator();
	cout << "\nThe second faction simplified is : " << f2Simplified.getNominator() << " / " << f2Simplified.getDenominator();
}

int Fraction::cmmdc(int denominator, int nominator)
{
	int hcf=1;
	if (denominator > nominator) {
		int temp = denominator;
		denominator = nominator;
		nominator = temp;
	}

	for (int i = 1; i <= denominator; ++i) {
		if (nominator % i == 0 && denominator % i == 0) {
			hcf = i;
		}
	}
	return hcf;
}

void Fraction::add(Fraction f2)
{
	
		int lcm = (this->denominator * f2.denominator) / cmmdc(denominator, f2.denominator);


		int sum = (this->nominator * lcm / this->denominator + (f2.nominator * lcm / f2.denominator));


		int num3 = sum / cmmdc(sum, lcm);

		lcm = lcm / cmmdc(sum, lcm);

		cout << endl<< this->nominator << "/" << this->denominator << " + " << f2.nominator << "/" << f2.denominator << " = " << num3 << "/" << lcm;
	}
void Fraction::substract(Fraction f2)
{

	int lcm = (this->denominator * f2.denominator) / cmmdc(denominator, f2.denominator);


	int sum = (this->nominator * lcm / this->denominator - (f2.nominator * lcm / f2.denominator));


	int num3 = sum / cmmdc(sum, lcm);

	lcm = lcm / cmmdc(sum, lcm);

	cout<<endl << this->nominator << "/" << this->denominator << " -" << f2.nominator << "/" << f2.denominator << " = " << num3 << "/" << lcm;
}


