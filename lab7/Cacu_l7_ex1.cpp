/*Modify example 3 in order to allow the addition of two CPunctText points. The name of the
new point will be created from the names of the compounding points. Add a method that
returns the distance from a point to origin. Modify the class so that you remove the afis ()
method by using appropriate getter methods instead. Also remove the lungime_sir attribute by
appropriately modifying the class methods. */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;
const int dim = 20;
class CPunctText
{
    int x;
    int y;
    char* name;

public:

    CPunctText();

    CPunctText(int ix, int iy, const char* sText = "Punct");

    CPunctText(const CPunctText& pct);

    void addPunct(CPunctText p)
    {
        this->x += p.x;
        this->y += p.y;
        strcpy(this->name, p.name);
        strcat(this->name, p.name);
    }

    double distance()
    {
        return sqrt(x * x + y * y);
    }
    void setX(int a) { x = a; }
    int getX()  { return x;   }
    void setY(int a) { y = a; }
    int getY()  {  return y;  }
    
    void setName(char* x) { strcpy(name, x); }
    char* getName()    {   return name;    }

    ~CPunctText() {
        cout << "\n Destructor called";
    
    };


};
CPunctText::CPunctText()
{
    cout << "\n Called constructor without parameters !";
    x = y = 0;
    name = new (nothrow) char[dim];
}
CPunctText::CPunctText(int b, int c, const char* a)
{
    cout << "\n Called constructor with parameters ";
    name = new (nothrow) char[sizeof(a) + 1];
    x = b;
    y = c;
    strcpy(name, a);
}
CPunctText::CPunctText(const CPunctText& p1)
{
    cout << "\n Copy contructor !";
    name = new (nothrow) char[sizeof(p1.name) + 1];
    x = p1.x;
    y = p1.y;
    strcpy(name, p1.name);
}

int main()
{
    CPunctText p1(1, 2, "Punct1 ");
    CPunctText p2(p1); 
    CPunctText p3 = p2; 
    CPunctText p4(-5, 8);
    cout << "\n Data of the second point  x:  " << p2.getX() << " y: " << p2.getY() << " name : " << p2.getName();
   cout << "\n Data of the fourth point  x:  " << p4.getX() << " y: " << p4.getY() << " name : " << p4.getName();

    p2.addPunct(p4);
    cout << "\n Data of the second point  x:  " << p2.getX() << " y: " << p2.getY() << " name : " << p2.getName();
    cout << "\nThe distance from the second point to  the origin is :  " << p2.distance();
}//main