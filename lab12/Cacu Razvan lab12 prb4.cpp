/*Cacu Razvan lab12 prb4 
Define a class called AcceleratedMovement that contains the private attributes dc (the current
distance), vc (the current speed) and a (the acceleration). The values of dc, vc and a are
initialized in the constructor and their values are equal to d0, v0 and a0 (as parameters).The
class overloads the extraction and insertion operators for initializing and displaying the
characteristics of a certain instance.
Implement the method determineMovement that re-calculates the values of dc and vc,
considering a number of seconds (received as paramenter) and the law of uniformly
accelerated linear motion with a0 acceleration. Instantiate the class and use the defined
members.
*/


#include<iostream>
using namespace std;


class AcceleratedMovement {
	int dc, vc, a;
public:
	void setDC(int aux) { dc = aux; }
	int getDC() { return dc; }

	void setVC(int aux) { vc = aux; }
	int getVC() { return vc; }


	void setA(int aux) { a = aux; }
	int getA() { return a; }

	AcceleratedMovement(int d0 = 0, int v0 = 0, int a0 = 0) {
		dc = d0;
		vc = v0;
		a = a0;
	}

	friend ostream& operator<<(ostream& stream, AcceleratedMovement obj);
	friend istream& operator>> (istream& stream, AcceleratedMovement& obj);

	void determineMovement(int time)
	{
		vc = vc + a * time;
		dc = vc * time;
	}
};
 ostream& operator<<(ostream& stream, AcceleratedMovement obj) {
	 stream << "\nThe dc is : " << obj.dc << "\nThe vc is : " << obj.vc << "\nThe a : " << obj.a;
	 return stream;
}
 istream& operator>> (istream& stream, AcceleratedMovement& obj) {
	 cout << "\nEnter dc : ";
	 stream >> obj.dc;
	 cout << "\nEnter vc : ";
	 stream >> obj.vc;
	 cout << "\nEnter a : ";
	 stream >> obj.a;
	 return stream;
 } 

 int main() {

	 AcceleratedMovement obj;
	 cin >> obj;
	 cout << obj;
	 int seconds;
	 cout << "\nenter the seconds : ";
	 cin >> seconds;
	 obj.determineMovement(seconds);

	 cout << obj;
 }