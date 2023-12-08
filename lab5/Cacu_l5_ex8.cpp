/*Cacu Razvan lab5 prb8  
 Starting with the Complex class ex.4, implement the addition, subtraction, multiplication and
division of complex numbers. The methods can be implemented inside or outside the class. Test the
defined methods by using them upon some created objects. The methods will return Complex objects
and in main() with getter methods will be displayed the results.
*/

#include<iostream>
#include<string>
using namespace std;

class Complex {
	int real, imaginary;
public:
	void setReal(int a) {
		this->real = a;
	}
	int getReal() {
		return this->real;
	}
	void setImaginary(int a) {
		this->imaginary = a;
	}
	int getImaginary() {
		return this->imaginary;
	}

	Complex  sum(Complex x) {
		Complex y;
		y.real = this->real + x.real;
		y.imaginary = this->imaginary + x.imaginary;
		return y;
	}

     Complex  substract(Complex x) {
		Complex y;
		y.real = this->real -x.real;
		y.imaginary = this->imaginary - x.imaginary;
		return y;
	}
	 Complex  product(Complex x) {
		 Complex y;
		 y.real = this->real * x.real -this->imaginary * x.imaginary;
		 y.imaginary = this->imaginary * x.real + this->real * x.imaginary;
		 return y;
	 }
	 Complex division(Complex y){ 
		 Complex x;
		 x.real = (((this->real) * (y.real)) + ((this->imaginary) * (y.imaginary))) / (pow(y.real, 2) + pow(y.imaginary, 2));
		 x.imaginary = (((y.real) * (this->imaginary)) - ((this->real) * (y.imaginary))) / (pow(y.real, 2) + pow(y.imaginary, 2));
		 return x;
	 }
};

int main()
{
	Complex x,y,z;
	int a, b;
	cout << "\nenter the real part of the first complex number : ";
	cin >> a;
	cout << "\nenter the imaginary part of the first complex number :";
	cin >> b;
	x.setReal(a);
	x.setImaginary(b);
	cout << "\nenter the real part of the second complex number : ";
	cin >> a;
	cout << "\nenter the imaginary part of the second complex number :";
	cin >> b;
	y.setReal(a);
	y.setImaginary(b);
	z = x.sum(y);
	cout << "\nThe sum of the 2 complex numbers is : " << z.getReal() << " + " << z.getImaginary() << "i ";
	z = x.substract(y);
	cout << "\nThe difference  of the 2 complex numbers is : " << z.getReal() << " + " << z.getImaginary() << "i ";
	z = x.product(y);
	cout << "\nThe product  of the 2 complex numbers is : " << z.getReal() << " + " << z.getImaginary() << "i ";
	z = x.division(y);
	cout << "\nThe division  of the 2 complex numbers is : " << z.getReal() << " + " << z.getImaginary() << "i ";

}