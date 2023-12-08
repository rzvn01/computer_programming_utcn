/*Cacu Razvan lab8  prb5
  Implement the 4-th problem by changing the static variable’s access modifier to private. Define a method
that returns the counter’s value. Analyze the case if the getter method is static or non-static and the way it
is called.*/


#include<iostream>
using namespace std;



class Static {
	static int var_static;
public:
	Static() {
		cout << "\nConstructor called !";
		var_static++;
	}
  static	int getVar_static() { 
		return var_static;
	}
};
int Static::var_static = 0;

int main() {
	Static s1;
	cout << "The obj number  is : " << s1.getVar_static();
	Static s2;
	cout << "The obj number  is : " << s2.getVar_static();
	Static s3;
	cout << "The obj number  is : " << s3.getVar_static();
	Static s4;
	cout << "The obj number  is : " << s4.getVar_static();
	Static s5;
	cout << "The obj number  is : " << Static::getVar_static();
}