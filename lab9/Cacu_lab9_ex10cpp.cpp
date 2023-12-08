/*Cacu Razvan lab9 prb10
Define a class named Number that has as private attribute a double variable. The class contains an 
explicit empty constructor, a constructor with a parameter and an accessor method that displays the value of
the stored variable. Write a class called Mathematics that has as attribute an instance created from the first 
class and overloads the arithmetical operators (+, -, /, *). Each method calculates the appropriate result by 
considering the data extracted from the Number object.
*/

#include <iostream>
using namespace std;

class Number {
	double y;
public:
	void setVal(double aux) {
		y = aux;
	}

	double getVal() {
		return y;
	}
	
	Number() { }
	Number(double x) {
		y = x;
	}
};
class Mathematics {
private:
	Number n1;
public:
	
	Mathematics(double a) {
		n1.setVal(a);
	}
	Mathematics() 
	{ n1.setVal(1.f); }

	Mathematics operator+( Mathematics& aux) {
		Mathematics res;
		res.n1.setVal(this->n1.getVal() + aux.n1.getVal());
		return res;
	}
	Mathematics operator-( Mathematics& aux) {
		Mathematics res;
		res.n1.setVal(this->n1.getVal() - aux.n1.getVal());
		return res;
	}
	Mathematics operator/( Mathematics& aux) {
		Mathematics res;
		res.n1.setVal(this->n1.getVal() /aux.n1.getVal());
		return res;
	}
	Mathematics operator*( Mathematics& aux) {
		Mathematics res;
		res.n1.setVal(this->n1.getVal() * aux.n1.getVal());
		return res;
	}
	Number getNr() {
		return n1;
	}

};
int main() {
	double var;
	cout << "\nEnter the first double  value : ";
	cin >> var;
	Mathematics x(var);
	cout << "\nEnter the second double  value : ";
	cin >> var;
	Mathematics y(var);

	Mathematics val = x + y;
	Number n1 = val.getNr();
	cout << "\nThe result of + : " << n1.getVal();
	val = x - y;
	 n1 = val.getNr();
	cout << "\nThe result of - : " << n1.getVal();
	val = x * y;
	n1 = val.getNr();
	cout << "\nThe result of * : " << n1.getVal();
	val = x / y;
	n1 = val.getNr();
	cout << "\nThe result of / : " << n1.getVal();
}