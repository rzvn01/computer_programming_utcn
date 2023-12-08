/*Cacu Razvan lab13 prb4
Write a C++ application that opens a binary file for reading. The filename is read from the
keyboard. Display a message if the file doesn’t exist and ask the user to re-enter the filename.
Assuming that the file contains some agenda records (name, city, phone number) overload the
insertion and extraction operators for reading the file’s content and for displaying it on the
screen
*/

#include<iostream>
#include<fstream>
using namespace std;

int main() {
	cout << "\nenter the  name :";
	char name[20];
	cin.getline(name, 20);
	ifstream myfile;
	myfile.open(name, ios::binary);
	if (myfile.good())
		cout << "\nThe file was opened !";
	else while (!myfile.good()) {
		cout << "\nThe file was not opened !\n enter the name again ";
		cin.getline(name, 20);
		myfile.open(name, ios::binary);
		if (myfile.good())
			cout << "\nThe file was opened !";
	}
	myfile.close();
	myfile.open(name);
	char arr[20];
	cout << "\nThe name is : ";
	myfile.getline(arr, 20);
	cout << arr;
	cout << "\nThe city is : ";
	myfile.getline(arr, 20);
	cout << arr;
	cout << "\nThe phone number is : ";
	myfile.getline(arr, 20);
	cout << arr;
}
