/*Cacu Razvan lab11 prb5
* Define an abstract class that contains 3 pure virtual methods declarations for concatenating,
interlacing two arrays of characters and for reverting the character array received as
parameter. A subclass implements the methods declared in the base class. Instantiate the 2-nd
class and display the results produced by applying the methods mentioned above upon some
data read from the keyboard. Examine the error given by the attempt of instantiating the base
class.*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class String {
public:
	virtual char* concatenating(char* first, char* second) = 0;
	virtual char* interlacing(char* first, char* second) = 0;
	virtual char* reverting(char*) = 0;
};
class Subclass :String {
public:
	char* concatenating(char* first, char* second) {
		char* aux;
		int res =1+ sizeof(first) + sizeof(second);
		aux = new(nothrow) char[res];
		strcpy(aux, first);
		strcat(aux, second);
		return aux;

	};
	 char* interlacing(char* a, char* b) {
		char* res = new char[strlen(a)+strlen(b)];

		int i{}, k{};
		for (; k < min(strlen(a), strlen(b)); i += 2) {
			res[i] = a[k];
			res[i + 1] = b[k++];
		}

		int mx = max(strlen(a), strlen(b));
		char* aux;
		if (mx == strlen(a))
			aux = a;
		else
			aux = b;

		for (; k < mx; i++)
			res[i] = aux[k++];

		return res;
	}
	char* reverting(char* str) {
		for (int i = 0; i < strlen(str) / 2; i++)
		{
			char temp = str[i];
			str[i] = str[strlen(str) - i - 1];
			str[strlen(str) - i - 1] = temp;
		}
		return str;
	}
};

int main() {
	Subclass s1;
	char first [30],second[30];
	cout << "Enter the first string : ";
	cin.getline(first, 30);
	cout << "Enter the first second : ";
	cin.getline(second, 30);
	char* res = s1.concatenating(first, second);
	cout << "\nThe result of concatenating is : " << res;
	res = s1.interlacing(first, second);
	cout << "\nThe result of interlacing is : " ;
	for (int i{}; i < strlen(first) + strlen(second); i++)
		cout << res[i];
	res = s1.reverting(first);
	cout << "\nThe result of reverting the first string is : " << res;
	res = s1.reverting(second);
	cout << "\nThe result of reverting the second string is : " << res;
}
