/*Cacu Razvan lab5 prb3
* Write a program that reads from the keyboard an array of maximum 10 characters
and performs all the operations implemented in the class defined at problem 3. */

#include<iostream>
#include<string.h>
#include"strClass.h"
using namespace std;

/*
* // The header file is : 
class String {

	char string1[100];

public:
	void setArray(char ba[100]) {
		strcpy_s(string1, ba);
	}
	char* getArray() { return string1; }

	int lenght() {
		return strlen(string1);
	}
	int occurance(char x)
	{
		int occ = -1;
		for (int i{}; i < strlen(string1); i++)
			if (x == string1[i])
				occ = i;
		return occ;
	}
	char* ret()
	{
		for (int i{}; i < strlen(string1); i++)
			string1[i] = toupper(string1[i]);
		return string1;

	}
	int number_occurance(char x)
	{
		int occ = 0;
		for (int i{}; i < strlen(string1); i++)
			if (x == string1[i])
				occ++;
		return occ;
	}

};
*/
int main()
{

	String s1;
	char a[10], b;

	cout << "\n Enter the string (maximum 10 char!) : ";
	cin.getline(a, 10);

	s1.setArray(a);

	cout << "\nThe lenght is the string is  : " << s1.lenght() << endl;

	cout << "\nEnter the char's index you want to find : ";
	cin >> b;

	cout << "The last index of occurance is  : " << s1.occurance(b) << endl;

	cout << "\n Enter the char you want to find the number of occurances : ";
	cin >> b;

	cout << "\nThe number of occurances is : " << s1.number_occurance(b);
	char* c = s1.ret();

	cout << "\n The capitals string is : ";
	cout << c;

}