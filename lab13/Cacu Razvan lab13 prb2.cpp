/*Cacu Razvan lab13 prb2 
Write a program that uses the write( ) method for writing some character arrays into a file.
Display the file’s content using the get( ) method. The filename is read from the keyboard.
*/

#include<iostream>
#include<fstream>
using namespace std;

int main() {

	char filename[20], text[20];
	cout << "\nEnter the name of the file : ";
	cin.getline(filename, 20);

	ofstream myfile; 
	ifstream file;
	cout << "\n text : ";
	cin.getline(text, 20);
	myfile.open(filename);
	file.open(filename);
	myfile.write(text,20);
	myfile.close();
	char c = file.get();
	while (c != '\0')
	{
		cout << c;
		c = file.get();
	}
}
