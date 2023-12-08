/*Cacu Razvan lab5 prb6 
Define a class that manages complex numbers. Write the program that uses this class considering 2
objects and displays the object’s characteristics and the results of the defined operations. (Use exemple
3 with result in the current object)*/

#include<iostream>
using namespace std;

class Complex {
	double real, imaginary;
public:
	Complex(double x = 0.0, double y = 0.0) {
		real = x;
		imaginary = y;
	}
	double modul() {
		return sqrt(real * real + imaginary * imaginary);
	}
	
	void setReal(double x) {
		real = x;
	}
	double getReal() {
		return real;
	}
	void setImaginary(double imaginar) {
		imaginary = imaginar;
	}
	double getImaginary() {
		return imaginary;
	}
	void ad_complex(Complex b) {
		real += b.real;
		imaginary += b.imaginary;
	}
	
};


int main() {
	Complex c1, c2;
	float value;
	cout << "Enter the real part of the first complex number : ";
	cin >> value;
	c1.setReal(value);
	cout << "Enter the imaginary part of the fist complex number : ";
	cin >> value;
	c1.setImaginary(value);

	cout << "Enter the real part of the second complex number : ";
	cin >> value;
	c2.setReal(value);
	cout << "Enter the imaginary part of the second complex number : ";
	cin >> value;
	c2.setImaginary(value);

	c1.ad_complex(c2);
		float a, b;
	a = c1.getReal();
	b = c1.getImaginary();
	cout << "\nThe sum is : "<<a<<"+"<<b<<"i ";

}