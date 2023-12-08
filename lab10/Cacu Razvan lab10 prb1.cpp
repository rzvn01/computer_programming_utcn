/*
Cacu Razvan lab10 prb1
Implement the program presented in the third example and examine the compilation errors if
are by eliminating the existing comments? Modify the program so the object obiect_derivat
will be able to access the aduna( ) and scade( ) methods, from the main( ) function keeping
the private inheritance.
*/
#include <iostream>
using namespace std;
class Base {
protected: int a, b;
public:
	Base() { a = 1, b = 1; }
	void setA(int a) {
		this->a = a;
	}
	void setB(int b) {
		this->b = b;
	}
	int getA() {
		return a;
	}
	int getB() {
		return b;
	}
	int add() {
		return a + b;
	}
	int substract() {
		return a - b;
	}
};
class Deriv : private Base
{
public:
	int getProduct() {
		return a * b;
	}
	int getsum() {
		return add();
	}
	int getSubs() {
		return substract();
	}
};
int main()
{
	Base b1;
	cout << "\n Valorile initiale " << b1.getA() << " " <<
		b1.getB() << '\n';
	cout << "\nSuma :  " << b1.add(); 
		cout << "\nDiferenta este (cu val. initiale, baza) = " << b1.substract();

	b1.setA(4);
	b1.setB(2);
	cout << "\nAfis din baza (modificat): " << b1.getA() << " " << b1.getB() << '\n';
	cout << "\nSuma/Diferenta dupa setare= " << b1.add() << "/" <<	b1.substract() << '\n';
	Deriv b2
		;
	cout << "\nProdusul este  = " << b2.getProduct() << '\n';
	cout << "\nAdunarea este  = " << b2.getsum();
	cout << "\nScaderea este  = " << b2.getSubs();
	cout << endl;
	
}
