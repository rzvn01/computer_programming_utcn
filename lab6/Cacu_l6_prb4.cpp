/*Cacu Razvan lab6 prb4 
* Write a C++ class that has as private attribute a date field. The date is defined as a structure
declared outside the class and it contains the fields day – int, month – int, year – int. The class
contains public accessor/getter and mutator/setter methods that can use the private information
as date structure, for all fields from the structure. The class also contains two public methods
that:
- test the validity of the stored date.
- write into a file all the dates from the current year that precede chronologically the class
stored date based only on the year attribute as a modified attribute.
In the main( ) function, after instantiating the class and after reading from the keyboard all the
components of a date, call the member methods and then verify the obtained results.

*/


#include<iostream>
#include<assert.h>
#include<fstream>

using namespace std;

struct AuxDate {
	int year, month, day;
};

class Date {
	AuxDate data;
public: 
	void setDatayear(int x) { data.year = x; }
	int getDataYear() { return data.year; }
	void setDataMonth(int x) { data.month = x; }
	int getDataMonth() { return data.month; }
	void setDataDay(int x) { data.day = x; }
	int getDataDay() { return data.day; }
	bool dateVerify();
	bool stop(int, int,Date);
};

int main() {

   	ofstream myFile("dates.txt");
	Date d1,d2;
	int d, m, y;
	cout << "Enter the date (day/month/year) : ";
	cin >> d >> m>> y;
	d1.setDataDay(d);
	d1.setDataMonth(m);
	d1.setDatayear(y);
	if (d1.dateVerify())
		cout << "\nThe date is ok !";
	else 
		cout << "\nThe date is not ok !";
	
	bool flag=true;
   
	for(int i=1;i<=12&&flag==true;i++)
   {
	   for (int j = 1; j <= 31&&flag==true; j++) {
		   d2.setDataDay(j);
		   d2.setDataMonth(i);
		   d2.setDatayear(y);
		   if (i >= m && j - d >= 0)
			   flag = false;
		   if (d2.dateVerify() && flag==true)
			   myFile << j << "-" << i << "-" << y << "\n";

		   
	   }
	   myFile << "\n";
   }
	myFile.close();

}

bool Date::stop(int day, int month,Date d1) {
	bool flag = true ;
	if (month > d1.getDataMonth())
		flag = false; 
	if (month >= d1.getDataMonth() && day >= d1.getDataDay())
		flag = false;
	return flag;
}
bool Date::dateVerify()
{
	bool year = true, month = true, day = true, y2 = true;
	if (data.year > 2022)
		year= false;
		
	(data.year % 4 == 0)
		? y2 = true
		: y2 = false;
	if (this->data.month > 12)
		month = false;
	if (y2) {
		if (this->data.month == 2)
			if (this->data.day > 29)
				day = false;
	}
	else 
		if (this->data.month == 2)
			if (this->data.day > 28)
				day = false;
	if (this->data.month % 2 == 0)
	{
		if (this->data.day > 30)
			day = false;
	} 
	else if (this->data.day > 31)
		day = false;
	
	if (year && month && day)
		return true;
	else return false;
		

}