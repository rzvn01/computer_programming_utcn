/*Cacu Razvan lab7 prb6 
Define a class called Complex that stores the double variables real, imag and a pointer of
character type that holds the name of the complex number. Define an explicit constructor with
2 parameters that have 1.0 as implicit value. The constructor also initializes the pointer with a
15 characters wide memory zone. Define a copy constructor for this class. Implement the
mutator/setter and accessor/getter methods for each variable stored inside the class. All the
operations related to the complex numbers are also emulated using some specific methods. An
explicit destructor method is also part of the class. Define an array of not more than 10
complex numbers. Determine the sum of all the numbers in this array and use this value for
initializing a new instance of the class named complex_sum. Repeat this action for all the rest
of the operations implemented inside the class.*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;


class Complex {
	double real, imag;
	char* name;
public: 
	Complex(double a = 1.0f, double b = 1.0f)
	{
		real = a;
		imag = b;
		name = new(nothrow)char[15];
	}
	Complex(const Complex& c1) {
		real = c1.real;
		imag = c1.imag;
		strcpy(name, c1.name);
	}
	void setReal(double x) { real = x; }
	double getReal() { return real; }

	void setImag(double x) { imag = x; }
	double getImag() { return imag; }

	void setName(char* x) { strcpy(this->name, x); }
	char* getName() { return name; }

}*arr;
int main()
{
	int number;
	cout << "\n Enter the number of complex numbers (<10):";
	cin >> number;
	assert(number < 10);
	arr = new (nothrow)Complex[number];
	int val;
	char aux[15];
	double a = 0, b = 0, c = 1, d = 1, e = 0, f = 0;
	for (int i{}; i < number; i++)
	{
		
		getchar();
		cout << "Enter the name of the complex  number # " << i + 1 <<"\t";
		cin >> aux;
		arr[i].setName(aux);
		cout << "\nReal part : ";
		cin >> val;
		arr[i].setReal(val);
		cout << "\nImaginary part: "; \
			cin >> val;
		arr[i].setImag(val);
	
			a += arr[i].getReal();
			b += arr[i].getImag();
			c *= arr[i].getReal();
			d *= arr[i].getImag();
			e -= arr[i].getReal();
			f -= arr[i].getImag();
		
	}

	Complex sum, subs, prod;
	char name_sum[] = "Sum_c", name_sub[] = "Substract_c", name_prod[] = " Product_c";
	sum.setName(name_sum);
	subs.setName(name_sub);
	prod.setName(name_prod);
	
	
	sum.setReal(a);
	sum.setImag(b);
	subs.setReal(e);
	subs.setImag(f);
	prod.setReal(c);
	prod.setImag(d);

	cout << "\n Data of the complex sum : ";
	cout << "\n" << sum.getName() << ":\t" << sum.getReal();
	if (sum.getImag() >= 0)
		cout << " + ";
	cout << sum.getImag() << "i \n";

	cout << "\n Data of the complex difference  : ";
	cout << "\n" << subs.getName() << ":\t" << subs.getReal();
	if (subs.getImag() >=0)
		cout << " + ";
	cout << subs.getImag() << "i \n";

	cout << "\n Data of the complex product : ";
	cout << "\n" << prod.getName() << ":\t" << prod.getReal();
	if (prod.getImag() >= 0)
		cout << " + ";
	cout << prod.getImag() << "i \n";
}