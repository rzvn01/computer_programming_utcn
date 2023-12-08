/*Cacu Razvan lab7 prb7 
* Consider a Pair class that has two pointers to int type, * x and * y. Define a constructor no
parameters that initializes zones with 0, with two parameters that initialize zones with values
specified as parameters, a constructor with one parameter that calls the two-parameter
constructor with parameter value, and 0. The class has a copy constructor, a move constructor,
a destructor (which distinguishes objects that are temporary) and setters and getters that
properly manage attributes. A sum() method is defined that has a Pair object as a parameter
and returns a Pair object sum of the current object with the given one as a parameter. The
class also contains a media() method that returns the double-type arithmetic mean of the
content from the two attributes. Instantiate 3 objects using no-parameter, one-parameter, 
twoparameter constructors. Change the values for the no-parameter object with setters. Display
values from the addresses of the parameters and media value. Display values from the
attribute addresses of other objects. Add the first two objects into a new result object and
display the result. Consider appropriate messages in constructors and destructor. Track the
calls.*/

#include<iostream>
using namespace std;

class Pair {
	int* x, * y;
public: 
	Pair() {
		x = new (std::nothrow) int;
		*x = (int)0;
		y= new (std::nothrow) int;
		*y = (int)0;
		cout << "\nConstructor called without parameters ! "; };

	Pair(int a, int b) { 
		x = new (std::nothrow) int;
		*x = a; 
	    y = new (std::nothrow) int; 
	    *y = b; 
	    
		cout << "\nConstructor called with 2 parameters !"; 
	};

	Pair(int a) : Pair(a, 0) { cout << "\nConstructor called with 1 parameter !"; };
	Pair(const Pair& p1) {
		
		cout << "\nCalling Copy constructor";
		x = p1.x;
	    y = p1.y;}

	Pair( Pair && obj)
	{
		cout << "\nCalling Move constructor";
		x = obj.x;
		y = obj.y;
		obj.x = NULL;
		obj.y = NULL;
	}
	~Pair() {
		cout << "\nCalling destructor ! ";


	}
	void setX(int a) { *x = a; }
	int getX() { return *x; }
	void setY(int a){ *y = a ; }
	int getY() { return *y ; }
	double media() {
		return double(*x + *y) / 2;
	}

	Pair sum(Pair ob) {
		Pair s;
		*s.x = *x + *ob.x;
		*s.y = *y + *ob.y;
		return s;
	}

};

int main() {
	int x, y;
	
	Pair p1, p2(5), p3(3, 6);
	cout << "\nThe values of the first object  : " << p1.getX() << "\t" << p1.getY();
	cout << "\nThe media of the first object is : " << p1.media();

	cout << "\nThe values of the second object  : " << p2.getX() << "\t" << p2.getY();
	cout << "\nThe media of the second  object is : " << p2.media();

	cout << "\nThe values of the third object  : " << p3.getX() << "\t" << p3.getY();
	cout << "\nThe media of the third object is : " << p3.media();

	cout << "\nEnter a value for x : ";
	cin >> x;
	p1.setX(x);

	cout << "\nEnter a value for y : ";
	cin >> y;
	p1.setY(y);
	cout << "\nThe values from the first object  : " << p1.getX() << "\t" << p1.getY();
	cout << "\nThe media of the first object is : " << p1.media();

    Pair sum = p1.sum(p2);
	cout << "\n The values fo the sum object are : " <<sum.getX() <<"\t" << sum.getY();
}