/*Cacu Razvan lab8  prb4
  Write a C++ application that stores inside a class a public static integer variable called var_static. The
variable is incremented each time the class’s constructor is called. After instantiating several objects,
display their number using the value of the static variable.*/


#include<iostream>
using namespace std;



class Static {
public:
	static int var_static;

	Static() {
		cout << "\nConstructor called !";
		var_static++;
	}

};
int Static::var_static = 0;

int main() {
	Static s1;
	cout << "The obj number  is : " << s1.var_static;
	Static s2;
	cout << "The obj number  is : " << s2.var_static;
	Static s3;
	cout << "The obj number  is : " << s3.var_static;
	Static s4;
	cout << "The obj number  is : " << s4.var_static;
	Static s5;
	cout << "The obj number  is : " << Static::var_static;
}