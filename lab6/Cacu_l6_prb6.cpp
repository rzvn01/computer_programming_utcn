/*Cacu Razvan lab6 prb6
Write a C++ application that defines a class called Triangle. The class contains as private int
variables the triangle's sides a, b and c, a constructor with parameters and adequate setter and
getter methods. The class will contain methods that will calculate the shape's area and
perimeter. Write a distinct method that will print a specific message if the triangle is right.
Develop a private method with parameters that will determine whether the values of a, b and c
form a triangle. The method will be called in setter methods.*/

#include<iostream>
using namespace std;

class Triangle {

	int a, b, c;
	bool isTriangle(int, int, int);

public: 
	void setA(int x) { a = x;	}
	int  getA() { return a; }
	void setB(int x) {b = x;}
	int getB() { return b; }
	void setC(int x) { c = x; }
	int getC() { return c; }
	bool getValidity() { return this->isTriangle(a, b, c); }
	Triangle(int, int, int);
	float getArea();
	int getPerimeter() { return a+b+c; }

};

int main() {

	int side1, side2, side3;
	cout << "\n Enter the value of the triangle's sides : ";
	cin >> side1 >> side2 >> side3;
	Triangle t(side1, side2, side3);
	t1.setA(side1);
	t1.setB(side2);
	t1.setC(side3);
	
	bool flag = t1.getValidity();
	if (!flag)
		cout << "\nThe triangle  doesnt exist !";
	else {
		cout << "\nThe triangle exist !";
		cout << "\n The perimeter of the triangle is : " << t1.getPerimeter();
		cout << "\nThe area of the triangle is : " << t1.getArea();
	}
}

bool Triangle::isTriangle(int side1 , int side2 , int side3 )
{
	bool flag = 0;
	if ((side1 + side2) > side3)
	{
		if ((side2 + side3) > side1)
		{
			if ((side1 + side3) > side2)
			{
				
				flag = 1;
			}
		}
	}
	return flag;
}

Triangle::Triangle(int x=3 , int y=4, int z=5)
{
	a = x;
	b = y;
	c = z;
}

float Triangle::getArea()
{
	float s, area;
	s = (a + b + c) / 2;
	area = (float)sqrt(s * (s - a) * (s - b) * (s - c));
	return area;
}
