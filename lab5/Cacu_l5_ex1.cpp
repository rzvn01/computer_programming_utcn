/*Cacu Razvan lab5 prb 1
Write a C/C++ application that uses a data structure named Scircle. The structure has an integer
variable that represents the circle’s radius. In the main( ) function that uses the Scircle structure,
declare 2 Scircle variables (c1 and c2) and calculate the area and the perimeter (using 2 methods) for 2
circles with the value of the radius read from the keyboard.
Perform the same operations using a class called Circle (the radius is a private member of the class).
The class contains, besides those 2 methods defined in the first application for area and perimeter, an
explicit constructor with 1 parameter, a destructor. Introduce an accessor method in the class,
getRadius( ), method that allows access to the private radius attribute, to display in the main( ) the
radius of objects. Define several Circle objects, pointers to the declared objects and references to those
objects and call the specific methods.
*/

#include<iostream>
using namespace std;

struct Scircle {
	int radius;
};

float area(int radius) { return (float)3.14 * radius * radius; }
float perimeter(int radius) {	return (float)2*3.14 * radius;}

class Circle {
	
	int radius;
public: 
	
	int  getRadius() {
		cout << "\n getRadius called ! ";
		return radius;}

	Circle(int x) {
		cout << "\nConstructor called !";
		radius = x;}

	~Circle()
	{	cout << "\n Destructor  called ! ";}

	float area() { return (float)3.14 * radius * radius; }
	float perimeter() { return (float)2 * 3.14 * radius; }
};

int main()
{
	Scircle c1{}, c2{};
	cout << "\n The radius of the first circle ? ";
	cin >> c1.radius;
	cout << "\nThe radius of the second circle ? ";
	cin >> c2.radius;
	cout << "\nArea for the first circle : " << area(c1.radius) << " and the perimeter  : " << perimeter(c1.radius);
	cout << "\nArea for the second circle : " << area(c2.radius) << " and the perimeter  : " << perimeter(c2.radius)<<endl;
	system("pause");
	system("cls");
	Circle c3(5), c4(7), c5(3);
	
	cout << "\n The radius of the first circle is :" << c3.getRadius();
	cout << "\nArea for the first circle : " << c3.area() << " and the perimeter  : " << c3.perimeter();
	cout << "\n The radius of the second circle is " << c4.getRadius();
	cout << "\nArea for the second circle : " << c4.area() << " and the perimeter  : " << c4.perimeter();
	cout << "\n The radius of the third circle is : " << c5.getRadius();
	cout << "\nArea for the third circle : " << c5.area() << " and the perimeter  : " << c5.perimeter();
}
