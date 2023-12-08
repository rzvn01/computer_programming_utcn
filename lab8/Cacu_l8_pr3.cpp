/*Cacu Razvan lab8  prb3
* Define a class called Repository that has 2 integer private variables. The class contains an empty
constructor and another one with 2 parameters. An accesor method that displays the variables values is
also included in the class. Write another class called Mathematics which is friend to the first one. This
class contains the implementation of the elementary arithmetical operations (+, -, *, /) applied to the
values stored in the first class. Each arithmetical method receives as parameter an object instantiated from
the first class.*/

#include<iostream>
using namespace std;

class Repository {
	int first, second;
public: 
	void setFirst(int a) {
		first = a;
	}
	int getFirst() {
		return first;
	}
	void setSecond(int a) {
		second = a;
	}
	int getSecond() {
		return second;
	}
	friend class Mathematics;

	Repository() {
		first = 0;
		second = 1;
		cout << "\n Void constructor !";
	}
	Repository(int a, int b) {
		first = a;
		second = b;
		cout << "\n Explicit constructor with parameters ";
	}
};
class Mathematics {

public: 
	int operator+(Repository obj) {
		int a = obj.first + obj.second;
		return a;
	}
	int operator-(Repository obj) {
		int a = obj.first - obj.second;
		return a;
	}
	int operator*(Repository obj) {
		int a = obj.first * obj.second;
		return a;
	}
	double operator/(Repository obj) {
		double a = (double)(obj.first / obj.second);
		return a;
	}
};
int main() {
	int value;
	double val;
	Repository r1();
	Mathematics m1;
	cout << "\n Enter the first number : ";
	cin >> value;
	r1.setFirst(value);
	cout << "\n Enter the second number : ";
	cin >> value;
	r1.setSecond(value);
	value = m1+r1;
	cout << "\nThe result of add is :" << value;
	value = m1 - r1;
	cout << "\nThe result of substract is :" << value;
	value = m1 *r1;
	cout << "\nThe result of product is :" << value;
	val = m1/ r1;
	cout << "\nThe result of division  is :" << val;

}