/*Cacu Razvan lab10 prb5~
Define a class called Triangle with 3 attributes for the triangle sides that has a method that
calculates the perimeter of the triangle with the sides introduced from the KB. Another class,
Triangle_extended, is derived in public mode from Triangle and defines a method for
calculating the triangle’s area. Using objects from both classes call the allowed methods.
Verify before to instantiate the objects the possibility to define a Triangle object
*/ 

#include <iostream>
#include <math.h>
using namespace std;

class T {
protected: int s1, s2, s3;
public:
    void setS1(int l1) {
        s1 = l1;
    }
    int getS1() { return s1; }

    void setS2(int l2) {
        s2 = l2;
    }

    int getS2() { return s2; }

    void setS3(int l3) {
        s3 = l3;
    }

    int getS3() { return s3; }

    int perimeter() {
        if(s1 + s2 > s3 && s1 + s3 > s2 && s3 + s2 > s1)
            return s1 + s2 + s3;
        else {

            cout << "\nThese sides can't create a triangle!";
            return -1;
        }
    }
};
class T_extended : public T {
public:
    double Triangle_area() {
        int perimetet = s1 + s2 + s3;
        double semiperemeter = (float)perimetet / 2;
        return sqrt(semiperemeter * (semiperemeter - s1) * (semiperemeter - s2) * (semiperemeter - s3));
    }
    
    double height1() {
        return (0.5 * sqrt((s1 + s2 + s3) * (s2 + s3 - s1) * (s1 - s2 + s3) * (s1 + s2 - s3))) / s1;
    }
    double height2() {
        return (0.5 * sqrt((s1 + s2 + s3) * (s2 + s3 - s1) * (s1 - s2 + s3) * (s1 + s2 - s3))) / s2;
    }
    double height3() {
        return (0.5 * sqrt((s1 + s2 + s3) * (s2 + s3 - s1) * (s1 - s2 + s3) * (s1 + s2 - s3))) / s3;
    }
};
int main()
{
 
    T_extended t2;
    int var;
    cout << "\nSide 1 : ";
    cin >> var;
 
    t2.setS1(var);
    cout << "\nSide 2 : ";
    cin >> var;
 
    t2.setS2(var);
    cout << "\nSide 3 :  ";
    cin >> var;
  
    t2.setS3(var);
    cout << "The perimeter is: " << t2.perimeter() << endl;
    cout << "The area is: " << t2.Triangle_area() << endl;
    cout << "Choose your base side  : ";
    cin >> var;

    if (var == 1)
        cout << "\n Thw height  is : " << t2.height1();
    else if (var == 2) 
        cout << "\n Thw height  is : " << t2.height2();
    else if (var==3)
        cout << "\n Thw height  is : " << t2.height3();
}
