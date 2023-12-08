/*Cacu Razvan lab10 prb6 
Define a class Shape that considers a shape with a name attribute as a pointer to character
string. The class will contain a constructor without parameters, one with parameters, copy
constructor and the assign operator will be overloaded. The class will also have getter/setter
methods and a destructor. Derive in public mode a Circle class that adds an int type attribute
to the radius and appropriate constructors considering also the attributes (name, radius) and a
getter method for the radius and other methods that calculate the area and perimeter of the
circle of radius r, value entered in main () from the keyboard.
In the same mode define other classes (Square, Rectangle, etc.) Instantiate objects from the
derived classes and display the area and the perimeter. The data will be introduced from the
KB. Define a Circle object with parameters introduced from the KB, to copy to a new object
and display its attributes. Define a Square object with parameters and another without
parameters. Assign the instantiated object with the parameters to the one without parameters
and display the attributes.
*/
#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
using namespace std;

class Shapes {
protected: char* name;
public:
	void setName(char* x) {
		strcpy(x, name);
	}
	char* getName() { return name; }

	Shapes() {
		name = new char[30];
	}
	Shapes(const Shapes& s1) {
		strcpy(name, s1.name);
	}
	~Shapes() {
		delete[] name;
	}
};
class Circle : public Shapes {
protected: int radius;
public:
	void setRadius(int radius) {
		this->radius = radius;
	}
	int getRadius() {
		return radius;
	}

	double Circle_area() {
		return 3.14 * pow(radius, 2);
	}
	double Circle_perimeter() {
		return 2 * 3.14 * radius;
	}
};
class Square : public Shapes {
protected: int side;
public:
	void setSide(int side) { this->side = side; }
	int getSide() { return side; }

	int Square_area() {
		return pow(side, 2);
	}
	int Square_perimeter() {
		return 4 * side;
	}
};
class Rectangle : public Shapes {
protected: int long_side, short_side;
public:
	void setLong_side(int l_side) {long_side = l_side; }
	int getLong_side() { return long_side; }

	void setShort_side(int s_side) {short_side = s_side; }
	int getShort_side() { return short_side; }


	int Rectangle_area() {
		return long_side * short_side;
	}
	int Rectangle_perimeter() {
		return 2 * (long_side + short_side);
	}
};
int main()
{
	Circle circle;
	Square square;
	Rectangle rectangle;
	int var, var1;
	int res;

	cout << "Enter the name of the shape(1 - rectangle,2-  circle or3- square): ";
	cin >> res;

	if (res==2) {
		
		cout << "Enter the radius: ";
		cin >> var;
		circle.setRadius(var);
		cout << "The area is: " << circle.Circle_area() << endl;
		cout << "The perimeter is: " << circle.Circle_perimeter() << endl;
	}
	else if (res==3) {

		cout << "Enter the side: ";
		cin >> var;
		square.setSide(var);
		cout << "The area is: " << square.Square_area() << endl;
		cout << "The perimeter is: " << square.Square_perimeter() << endl;
	}
	else if (res==1) {
	
		cout << "Enter the long side: ";
		cin >> var;
		rectangle.setLong_side(var);
		cout << "Enter the short side: ";
		cin >> var;
		rectangle.setShort_side(var);
		cout << "The area is: " << rectangle.Rectangle_area() << endl;
		cout << "The perimeter is: " << rectangle.Rectangle_perimeter() << endl;
	}
}
