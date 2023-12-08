/*Cacu Razvan lab6 prb 1
Write a C++ application that implements a class called F1Pilot. The class defines the private
variables name (array of characters), team (array of characters), age (int), best_time (int) and
pole_position_nr(int). As public members, the class contains mutator/setter and
accessor/getter methods for each of the class’s attributes.
In function main( ), create 3 different instances of the F1Pilot class and use the seter methods
for initializing each object’s data with the corresponding information read from the keyboard.
Using the getter methods, display all the data related to the pilot that has the best time.
*/


#include<iostream>
using namespace std;


class F1Pilot {
	char name[50], team[50];
	int age, best_time, pole_position_nr;
public:

	void setName(char x[50]) {
		strcpy(name, x);
	}
	char* getName{
		return name; }
		void setTeam(char x[50]) {
		strcpy(team, x);
	}
	char[50]getTeam{
		return team; }
	void setAge(int a) {
		age = a;
	}
	int getAge() { 
		return age; }

	void setBest_time(int a) {
		best_time = a;
	}
	int getBest_time() {
		return best_time;
	}

	void setPole_position_nr(int a) {
		best_time = a;
	}
	int getPole_position_nr() {
		return pole_position_nr;
	}
};

int main()
{
	char[50]a;
	int b;
	F1Pilot* x;
	x = new (nothrow) F1Pilot[3];

	for (int i{}; i < 3; i++)
	{
		cout << "\nData for pilor nr :" << i + 1;
		flush(cin);
		cout << "\nname : ";
		cin.getline(a, 50);
		x[i].setName

	}
}
