/*Cacu Razvan lab6 prb2 
Modify example 2 so that the code can be launched in execution considering the private class
attribute and appropriate public get/set methods. In main(), instantiate an object from the class
that will be modified and then accessed, displaying also the result.
*/

#include <iostream>
using namespace std;
class Test2 {
	int x;
public: 

	Test2() {
		x = 0;
		cout << "\nConstructor called ...";
	}~Test2()
	{
		cout << "\nDestructor called ...";
	} 
	void setX(int a) {
		this->x = a;
	}
	int getX() {
		return this->x;
	}

};
int main() {
	Test2 ob1; 
	int a;
	cout << "\nEnter a value for x : ";
	cin >> a;

	ob1.setX(a);
	a = ob1.getX();
	cout << "\nThe getter method returned : " << a;

}