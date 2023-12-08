/*Cacu Razvan lab11 prb7
 Write a C++ application that defines the abstract base class AbstractQuadrilateral having as
protected attributes four instances of the Point class (a pair of x and y coordinates, getter and
setter methods) that represent the quadrilateral’s corners. Declare two pure virtual methods for
determining the area and the perimeter of the shape. Implement the derived class
ActualQuadrilateral that implements the inherited abstract methods and has another method
for determining whether the quadrilateral is a square, rectangle, or irregular quadrilateral.
Instantiate the derived class and call the defined methods. The area will be determined
depending on the quadrilateral type. The irregularr convex quadrilateral are wil be determined
considering the following formula that express the area in terms of the sides a, b, c, d, the
semiperimeter s, and the diagonals p, q:
A=sqrt {(s-a)(s-b)(s-c)(s-d)-1/4(ac+bd+pq)(ac+bd-pq)}.
*/


#include<iostream>
using namespace std;


class Point {
	int x, y;
public:
	int getX() { return x; }
	void setX(int a) { x = a; }
	int getY() { return y; }
	void setY(int a) { y = a; }
	Point(int a, int b) {
		x = a;
		y = b;
	}
	Point() {
		x = 1, y = 2;
	}

	~Point() {}
	bool operator==(const Point& p2) {

		if (x == p2.x && y == p2.y)
			return true;
		else
			return false;

	}
};

bool collinear(Point&, Point&, Point&);
bool doIntersect(Point& p1, Point& q1, Point& p2, Point& q2);
int orientation(Point& p, Point& q, Point& r);
int  quadrilateral(Point& p1, Point& p2, Point& p3, Point& p4);

class AbstractQuadrilateral {
	Point p1, p2, p3, p4;

public:
	Point getP1() { return p1; }
	void setP1(Point& a) {
		p1.setX(a.getX());
		p1.setY(a.getY());
	}

	Point getP2() { return p2; }
	void setP2(Point& a) {
		p2.setX(a.getX());
		p2.setY(a.getY());
	}

	Point getP3() { return p3; }
	void setP3(Point& a) {
		p3.setX(a.getX());
		p3.setY(a.getY());
	}

	Point getP4() { return p4; }
	void setP4(Point& a) {
		p4.setX(a.getX());
		p4.setY(a.getY());
	}
	float getA() {

		return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2) * 1.0);
	}
	float getB() {
		return  sqrt(pow(p3.getX() - p2.getX(), 2) + pow(p3.getY() - p1.getY(), 2) * 1.0);
	}
	float getC() {
		return sqrt(pow(p4.getX() - p3.getX(), 2) + pow(p4.getY() - p3.getY(), 2) * 1.0);
	}
	float getD() {
		return sqrt(pow(p1.getX() - p4.getX(), 2) + pow(p1.getY() - p4.getY(), 2) * 1.0);
	}
	float getAC() {
		return sqrt(pow(p3.getX() - p1.getX(), 2) + pow(p3.getY() - p1.getY(), 2) * 1.0);
	}
	float getBD() {
		return sqrt(pow(p4.getX() - p2.getX(), 2) + pow(p4.getY() - p2.getY(), 2) * 1.0);
	}
	virtual float getArea() = 0;

	virtual float getPerimeter() = 0;





};
class ActualQuadrilateral :public AbstractQuadrilateral {

public:

	float getPerimeter() {
		float a = getA();
		float b = getB();
		float c = getC();
		float d = getD();
		float ac = getAC();
		float bd = getBD();
		float pq = ac * bd;

		if (a == b == c == d)
			cout << "\nThe shape  is a square ! ";
		else if (a == c && d == b)
			cout << "\nThe shape  is a rectangular ";
		else
			cout << "\nThe shape  is a irregular quadrilateral !";
		return a + b + c + d;
	}

	float getArea() {
		float a = getA();
		float b = getB();
		float c = getC();
		float d = getD();
		float ac = getAC();
		float bd = getBD();
		float pq = ac * bd;
		float semip = (a + b + c + d) / 2;

		return  sqrt((semip - a) * (semip - b) * (semip - c) * (semip - d) - 1 / 4 * (ac + bd + pq) * (ac + bd - pq) * 1.0);
	}
	ActualQuadrilateral(Point& p, Point& q, Point& t, Point& r) {
		setP1(p);
		setP2(q);
		setP3(t);
		setP4(r);
	}
	ActualQuadrilateral() {
		cout << "Constructor called !";
	}


};


int main() {

	Point p1(0, 0), p2(3, 0), p3(1, 1), p4(0, 1);
	ActualQuadrilateral aq(p1, p2, p3, p4);

	int a = quadrilateral(p1, p2, p3, p4);
	if (a == 0)
	{
		cout << "\nThe points dont form a quadrilateral !";
		exit(1);
	}
	else if (a == 1)
	{
		cout << "\nThe points form a convex quadrilateral !";
		cout << "\nThe perimeter is : " << aq.getPerimeter();
		cout << "\nThe area is : " << aq.getArea();
	}
	else
	{
		cout << "\nThe points form a concave quadrilateral !";
		cout << "\nThe perimeter is : " << aq.getPerimeter();
	}


};
int  quadrilateral(Point& p1, Point& p2, Point& p3, Point& p4) {

	if ((p1 == p2) == true || (p1 == p3) == true || (p1 == p4) == true || (p2 == p3) == true || (p2 == p4) == true || (p4 == p3) == true)
		return 0;
	if (collinear(p1, p2, p3) == true || collinear(p1, p2, p4) == true || collinear(p1, p3, p4) == true || collinear(p2, p3, p4) == true)
		return 0;
	int check = 0;

	if (doIntersect(p1, p2, p3, p4))
		check = 1;
	if (doIntersect(p1, p3, p2, p4))
		check = 1;
	if (doIntersect(p1, p2, p4, p3))
		check = 1;

	if (check == 0)
		return 3;
	else
		return 1;
}
int orientation(Point& p, Point& q, Point& r)
{
	int val = (q.getY() - p.getY()) * (r.getX() - q.getX()) - (q.getX() - p.getX()) * (r.getY() - q.getY());

	if (val == 0)
		return 0;
	else
		return (val > 0) ? 1 : 2;
}


bool doIntersect(Point& p1, Point& q1, Point& p2, Point& q2)
{
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	if (o1 != o2 && o3 != o4)
		return true;

	return false;
}
bool collinear(Point& first, Point& second, Point& third)
{

	if ((third.getY() - second.getY()) * (second.getX() - first.getX()) == (second.getY() - first.getY()) * (third.getX() - second.getX()))
		return true;
	else
		return false;
} 