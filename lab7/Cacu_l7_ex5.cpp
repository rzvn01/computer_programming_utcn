/*Cacu Razvan lab7 prb5 
Write a C/C++ application that reads a point from the keyboard by giving the x, y and z
coordinates. Write a method that moves the point with a given distance on each of the three
axes. Verify if the line between the first and the second position of the point crosses a third
given point.
*/
#include<iostream>
using namespace std;


class Point {
	int x, y, z;
public: 
	Point() {};
	Point(const Point& p1) { x = p1.x; y = p1.y; z = p1.z; }
	void setX(int a) { x = a; }
	int getX() { return x; }

	void setY(int a) { y = a; }
	int getY() { return y; }

	void setZ(int a) { z = a; }
	int getZ() { return z; }

	void moveX(int a) { this->x += a; }
	void moveY(int a) { this->y += a; }
	void moveZ(int a) { this->z += a; }

	bool is_on_line(Point a, Point b) {
		float t = (float)(this->x - a.x) / (b.x - a.x);
		float f = (float)(this->y - a.y) / (b.y - a.y);
		float v = (float)(this->z - a.z) / (b.z - a.z);

		if (t == f &&f==v)
			return true;
		else return false;
	}

};


int main() {
	Point p1, p2, p3;
	int val;

	cout << "\nEnter the point's coordinates \n ";
	cout << "\n x : ";
	cin >> val;
	p1.setX(val);
	cout << "\n y : ";
	cin >> val;
	p1.setY(val);
	cout << "\n z : ";
	cin >> val;
	p1.setZ(val);
	 p2 = p1;
	cout << "\n Enter the values to move the point  \n";
	cout << "\nx : ";
	cin >> val;
	p1.moveX(val);
	cout << "\ny : ";
	cin >> val;
	p1.moveY(val);
	cout << "\nz : ";
	cin >> val;
	p1.moveZ(val);
	system("cls"); 

	cout << "\nYour points are : \n";
	cout << "\n The initial  point : P(" << p2.getX() << "," << p2.getY() << "," << p2.getZ()<<")";
	cout << "\n The moved  point : O(" << p1.getX() << "," << p1.getY() << "," << p1.getZ() << ")";
	
	cout << "\nEnter the third  point's coordinates \n ";
	cout << "\n x : ";
	cin >> val;
	p3.setX(val);
	cout << "\n y : ";
	cin >> val;
	p3.setY(val);
	cout << "\n z : ";
	cin >> val;
	p3.setZ(val);
	
	if (p3.is_on_line(p1, p2))
		cout << "\nThe third point is on the line formed by the first 2 !";
	else cout << "\nThe third point is not  on the line formed by the first 2 !";


}


