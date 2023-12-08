/*Cacu Razvan lab13 prb3
Write a C++ application that reads a file’s content using the read( ) method. The obtained data
is displayed on the screen. Check the system’s state after each reading operation. The filename
is read from the command line
*/

#include<iostream>
#include<fstream>

using namespace std;


int main(int argc, char* argv[])
{
	ifstream myfile;
	char arr[1];
	myfile.open(argv[1]);
	myfile.read(arr, 1);
	while (myfile.good()) {
		cout << endl<< arr[0];
		cout << "\nThe file is ok !";
		myfile.read(arr, 1);
	}
}