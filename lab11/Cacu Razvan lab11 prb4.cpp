/*Cacu Razvan lab11 prb4
* Declare a class called Animal that contains a pure virtual method (breath( )) and 2 virtual
methods (eat( ) and sleep( )). The classes Dog and Fish inherit the first class in a public mode
and implements the pure virtual method. The class Dog overrides the eat() method. The class
Fish overrides the sleep( ) method. Instantiate the derived classes and call the specific
methods. After that, define an array of Animal objects that will contain instances of the
derived classes, if that’s possible. If not, find an appropriate solution. */

#include<iostream>
using namespace std;

class Animal {
public:
	virtual void breath() = 0;
	virtual void eat() { };
	virtual void sleep() { };
};
class Dog :Animal {
public:
	void breath() {
		cout << "\nThe dog in breathing !";
	}
	void eat() override {
		cout << "\nThe dog is eating ! ";
	}
};
class Fish :Animal {
public:
	void breath() {
		cout << "\nThe fish in breathing !";
	}
	void sleep()override {
		cout << "\nThe fish is sleeping !";
	}
};

int main() {
	/* Animal* arr; - we cant create intances of the Animal class because is a abstract class ! */
	Dog d;
	Fish f;
	d.eat();
	d.breath();
	f.breath();
	f.sleep();
}