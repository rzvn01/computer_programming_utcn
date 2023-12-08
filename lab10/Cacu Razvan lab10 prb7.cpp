/*Cacu Razvan lab10 prb7
Consider a base class Circle defined by a protected attribute radius, that contains a constructor
with parameters and a method that will determine the area of the circle. Consider other base
class, Square with a protected attribute, length, similar to Circle class. Derive in public mode
the class RoundSquare from both classes that will contain a constructor that will call the
constructors from base classes and a method that will verify if the square of length l may be
included in the circle of radius r. The derived class will also determine the perimeter of both
shapes. Instantiate an object from the derived class (data from the KB) and determine the area
and perimeter of the composed shapes. Display a message if the square may be included in the
circle.

*/

#include <iostream>
using namespace std;
class Circle {
protected: int radius;
public:
    Circle() { ; }
    Circle(int radius) {
        radius = radius;
    }
    int getRadius() {
        return radius;
    }
    void setRadius(int radius) {
        radius = radius;
    }
    double area() {
        return 3.14 * pow(radius, 2);
    }
};
class Square {
protected: int side;
public:
    Square() {}
    Square(int side) {
        side = side;
    }
    void setSide(int side) {
        side = side;
    }
    int getSide() {
        return side;
    }
  
};
class CS : public Circle, public Square {
public:
    CS() { ; }
    CS(int x) :Circle(x), Square(x) { ; }
    void square_circle() {
        double diagonal = side * sqrt(2);
        if (diagonal == 2 * radius)
            cout << "The square is circumscribed by the circle!\n";
        else cout << "The square isn't circumscribed by the circle!\n";
    }
    double Square_perimeter() {
        return pow(side, 2);
    }
    int Square_perimeter() {
        return 4 * side;
    }
    double Circle_area() {
        return 3.14 * pow(radius, 2);
    }
    double Circle_perimtere() {
        return 2 * 3.14 * radius;
    }
};
int main()
{
    Circle c;
    Square s;
    CS ob;
    int x;
    cout << "\nEnter a value for the side of the square: ";
    cin >> x;
    s.setSide(x);
    ob.setSide(x);
\
    cout << "\nEnter a value for the radius: ";
    cin >> x;
    c.setRadius(x);
    ob.setRadius(x);
    ob.square_circle();
    cout << "\nThe area of the square is: " << ob.Square_perimeter() << endl;
    cout << "\nThe perimeter of the square is: " << ob.Square_perimeter() << endl;
    cout << "\nThe area of the circle is: " << ob.Circle_area() << endl;
    cout << "\nThe perimeter of the circle is: " << ob.Circle_perimtere() << endl;
}