/*Cacu Razvan lab13 prb1 
Write a program that uses the seekg( ) method for mid-file positioning and then displays the
file’s content, starting with this position. The filename is read from the command line.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>

using namespace std;


int main(int argc, char* argv[])
{
	FILE* p_file = NULL;
	p_file = fopen(argv[1], "rb");
	fseek(p_file, 0, SEEK_END);
	int size = ftell(p_file);
	fclose(p_file);

	ifstream myfile(argv[1]);
	myfile.seekg(size/2, ios::beg);
	 char c = myfile.get();
	cout << c;
	
	
}