/*Cacu Razvan lab9 prb1
* Implement a class called Complex that overloads the arithmetical operators (+, -, *, /) for performing the
corresponding operations when applied to Complex instances (use both friend functions (*, /) and member
methods (+, -)).
Note: the complex numbers will have a real and an imaginary part, both coefficients being represented as
real numbers.
*/

#include<iostream>
using namespace std;

class Complex {
	double real, imag;
public: 
	void setReal(double x) { real = x; }
	double getReal() { return real; }

	void setImag(double x) { imag = x; }
	double getImag() { return imag; }
	Complex operator+(Complex c1) {
		Complex aux;
		aux.real = this->real + c1.real;
		aux.imag = this->imag + c1.imag;
		return aux;
	}
	Complex operator-(Complex c1) {
		Complex aux;
		aux.real = this->real - c1.real;
		aux.imag = this->imag - c1.imag;
		return aux;
	}
	Complex friend  operator*(Complex c1,Complex c2);
	Complex friend  operator/(Complex c1, Complex c2);
};
Complex operator*(Complex c1,Complex c2) {

	Complex aux;
	aux.real = c1.real * c2.real - c1.imag * c2.imag;
	aux.imag = c1.real * c2.imag + c1.imag * c2.real;
	return aux;

}
Complex operator/(Complex c1, Complex c2) {

	Complex rez;
	rez.real = (c1.real * c2.real + c1.imag * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
	rez.imag = (c1.imag * c2.real - c1.real * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
	return rez;

}

int main() {
	int val;
	Complex c1, c2;
	cout << "\nEnter the real part of the first : ";
	cin >> val;
	c1.setReal(val);
	cout << "\nEnter the imaginary part of the first complex number : ";
	cin >> val;
	c1.setImag(val);
	cout << "\nEnter the real part of the second : ";
	cin >> val;
	c2.setReal(val);
	cout << "\nEnter the imaginary part of the second complex number : ";
	cin >> val;
	c2.setImag(val);
	Complex add = c1 + c2;
	Complex substract = c1 - c2;
	Complex product = c1 * c2;
	Complex division = c1 / c2;
	cout << "\nThe result of add is : " << add.getReal() << " +" << add.getImag()<<"i";
	cout << "\nThe result of substract is : " << substract.getReal() << " +" <<substract.getImag() << "i";
	cout << "\nThe result of product is : " << product.getReal() << " +" << product.getImag() << "i";
	cout << "\nThe result of division is : " << division.getReal() << " +" << division.getImag() << "i";


}