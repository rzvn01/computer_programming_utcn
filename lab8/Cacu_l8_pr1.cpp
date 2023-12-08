/*Cacu Razvan lab8 prb1
Implement a C++ application that defines the class called CurrentHour with hour, minute, second as
private attributes. The class has public setter/getter methods for each attribute. Add a friend function that
copies the content of a CurrentHour object used as parameter into another instance of the class that will be
returned by the function, hour being modified to Greenwich Mean Time. Use the computer local current
time.*/
#define _CRT_SECURE_NO_WARNINGS
#include <chrono>
#include <ctime>
#include <iostream>
using namespace std;

class CurrentHour {
	int hour;
	int minute;
	int second;
public: 
	void setHour(int a) {
		hour = a;
	}
	int getHour() { 
		return hour;
	}
	void setMinute(int a) {
		minute = a;
	}
	int getMinute() {
		return minute;
	}

	void setSecond(int a) {
		second = a;
	}
	int getSecond() {
		return second;
	}
	
 	CurrentHour friend copy(CurrentHour obj);
};


int main()
{
	CurrentHour c1, c2;
	time_t t = time(NULL);
	int h = (t / 3600) % 24+3;  
	int m = (t / 60) % 60;
	int s = t % 60;
	cout <<"\nThe current hour is : " <<h << ":" << m << ":" << s;
	c1.setHour(h);
	c1.setMinute(m);
	c1.setSecond(s);

	c2 = copy(c1);
	cout << "\nThe Greenwich hour is  " << c2.getHour() << ":" << c2.getMinute() << ":" << c2.getSecond();

}


CurrentHour copy(CurrentHour obj) {
	CurrentHour aux;
	aux.minute = obj.minute;
	aux.hour = obj.hour-3;
	aux.second = obj.second;
	return aux;
}