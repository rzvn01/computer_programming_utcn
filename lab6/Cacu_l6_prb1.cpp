/*Cacu Razvan lab 6 prb1 
Write a C++ application that implements a class called F1Pilot. The class defines the private
variables name (array of characters), team (array of characters), age (int), best_time (int) and
pole_position_nr(int). As public members, the class contains mutator/setter and
accessor/getter methods for each of the class’s attributes.
In function main( ), create 3 different instances of the F1Pilot class and use the seter methods
for initializing each object’s data with the corresponding information read from the keyboard.
Using the getter methods, display all the data related to the pilot that has the best time.*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;


class F1Pilot {
	char name[50], team[50];
	int age, best_time, pole_position_nr;

public : 
	void setName(char x[50]) {
		strcpy(this->name,x);
	}
		char* getName(){
			return this->name; }
		void setTeam(char x[50]) {
			strcpy(this->team, x);
		}
		char* getTeam() {
			return this->team;
		}

		void setAge(int x){ 
			this->age = x;
		}
		int getAge() {
			return this->age; }
		void setBest_time(int x){
			this->best_time = x;
		}
		int getBest_time() {
			return this->best_time;
		}
		void setPole_position_nr(int x) {
			this->pole_position_nr= x;
		}
		int getPole_position_nr() {
			return this->pole_position_nr;
		}
};


int main()
{
	F1Pilot* x{};
	x = new (nothrow) F1Pilot[3];
	int best, a;
	char b[50];
	for (int i{}; i < 3; i++)
	{
		
		cout << "\n\nData of the player " << i + 1;
		
		cout << "\nName: ";
		cin.getline(b, 50);
		x[i].setName(b);
		cout << "\nTeam: ";
		cin.getline(b, 50);
		x[i].setTeam(b);
		cout << "\nAge : ";
		cin >> a;
		x[i].setAge(a);
		cout << "\n Best time : ";
		cin >> a;
		x[i].setBest_time(a);
		cout << "\nPole position number : ";
		cin >> a;
		x[i].setPole_position_nr(a);

		if (i == 0)
			best = x[i].getBest_time();

		if (best > x[i].getBest_time())
			best = x[i].getBest_time();
		getchar();
	}


	cout << "\nThe best time is : " << best;
}