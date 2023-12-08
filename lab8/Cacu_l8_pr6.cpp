/*Cacu Razvan lab8  prb6
* Write a C++ application that defines a class named Point with the private attributes x and y. Implement a
friend function that calculate and display the area and perimeter of different shapes objects defined by two
Point parameters P0(x0, y0) and P1(x1, y1). Introduce another parameter named shape that controls the
way the two points are used. If we consider a circle, the points delimit the circle’s diameter (shape=1). If
we are dealing with a right triangle (shape=2), the points determine the hypotenuse, and the other sides
are determined considering the 2 initial points. The point’s coordinates and the shape selection will be
realized using parameters introduced from KB*/


#include<iostream>
#include<assert.h>
using namespace std;

class Point {
	int x, y;
public : 
	void setX(int a) {
		x = a;
	}
	int getX() {
		return x;
	}
	void setY(int a) {
		y = a;
	}
	int getY() {
		return y;
	}
	friend void Area_perimeter(Point p1, Point p2,int shape);
};

int main() {
	int val;
	Point p1, p2; 
	cout << "\n Enter the coordinate of the first point \nx: ";
	cin >> val;
	p1.setX(val);
	cout << "\ny:";
	cin >> val;

	p1.setY(val);
	cout << "\n Enter the coordinate of the second point \nx: ";
	cin >> val;
	p2.setX(val);
	cout << "\ny:";
	cin >> val;
	p2.setY(val);
	cout << "\n 1-circle\n2-triangle\n3-square \n  ";
	cin >> val;
	assert(val == 3 || val == 1 || val == 2);
	Area_perimeter(p1, p2, val);
}

void Area_perimeter(Point p1, Point p2, int shape)
{
	int a = p1.x - p2.x;
	int b = p1.y - p2.y;
	float distance = sqrt(a * a + b * b);
	switch (shape)
	{  case 1:
	{
		cout << "\nThe shape is a circle ! \n";
		cout << "The area of the circle is : " << 3.14 * distance * distance;
		cout << "\nThe lenght of the circle is : " << 2 * 3.14 * distance;
		break;
	}
	case 2: {
		
		cout << "\nThe shape is a triangle ! \n";
		cout << "The area of the triangle is : " << sqrt(3) / 4 * distance * distance;
		cout << "\nThe perimeter of the triangle is : " <<  3 * distance;
		break;
	}
	case 3: {
		cout << "\nThe shape is a square ! \n";
		cout << "The area of the triangle is : " <<  distance * distance;
		cout << "\nThe perimeter of the triangle is : " << 4 * distance;
		break;
	}
	default:
		break;
	}
}
