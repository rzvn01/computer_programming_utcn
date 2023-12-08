/*Cacu Razvan lab7 prb9
Considering the previous task add in the Fraction class another attribute consisting in a
character array pointer (name) that identifies a fraction. The constructor without parameters
will allocate a max 20 characters memory zone difined with ”Unknown”, the parameterized
constructor will have another last implicit parameter initialized with ”Unknown” that will
represent the fraction’s name and the reserved space will be twice the string dimension.
Implement setter and getter methods for the name attribute. Implement a copy constructor and
a destructor. In the main( ) function create two Fraction objects, one using the constructor
without parameters and the other using the parameterized constructor. Modify the attributes of
the first object using setter methods. Create a third object using the copy constructor. Display
the attributes of this last object using the getter methods..*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;

class Fraction {
	int denominator;
	int nominator; 
	char* name;
	int cmmdc(int denominator  ,int nominator);
public : 
	Fraction() {
		nominator = 0;
		denominator= 1;
		name = new(nothrow)char[20];
		strcpy(name,"Unknown");
	}
	Fraction(int x, int y,char* a) {
		nominator = x;
		denominator = y;
		name = new(nothrow)char[2 * sizeof(a)];
		strcpy(name, a);
	}
	Fraction(Fraction& f1) {
		denominator = f1.denominator;
		nominator = f1.nominator;
		name = new char[sizeof(f1.name)];
		strcpy(name, f1.name);
	}
	
	~Fraction() {
		cout << "\nDestructor called !";
		delete (name);
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
	void setName(char* x) {
		strcpy(name, x);
	}
	char* getName() { return name; }
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
	char name[] = "second", name1[]="first";
	Fraction f1,f2(3,10,name);
	int val;
	cout << "\nEnter the nominator of the first fraction : ";
	cin >> val;
	f1.setNominator(val);
	cout << "\nEnter the denominator  of the first fraction : ";
	cin >> val;	
	assert(val != 0);
	f1.setDenominator(val);
	f1.setName(name1);
	Fraction f3 = f1;

	cout << "\nThe name of the first is : " << f1.getName() << "  the nominator : " << f1.getNominator() << " the denominator : " << f1.getDenominator();
	cout << "\nThe name of the second is : " << f2.getName() << "  the nominator : " << f2.getNominator() << " the denominator : " << f2.getDenominator();
	cout << "\nThe name of the thirs is : " << f3.getName() << "  the nominator : " << f3.getNominator() << " the denominator : " << f3.getDenominator();

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


