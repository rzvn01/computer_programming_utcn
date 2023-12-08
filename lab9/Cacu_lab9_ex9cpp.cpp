/*Cacu Razvan lab9 prb9 
Define a class called Student, containing as private member : name(pointer to character array), marks
(integer pointer) and no_marks(integer).The class also contains a constructor with parameters, a copy / move
constructor, a method for assign operator overloading, a method for marks setting, a display method and a
destructor.Create some objects using the constructor with parameters, another one using the copy constructor
as a clone object, displaying each time the attributes of the created object.Copy an object into another one,
both being created.Display the result of the copy operation.Analyze the used methods.Make another
implementation in which the name is given by a fixed character string or pseudo container string, and marks is
a fixed size array specified by a constant, the no_marks attribute being removed
*/

#include<iostream>
using namespace std;
const int mSIZE= 3;

class Student {
	char name[30];
	int* marks;
public: 
	void setName(char* aux) {
		strcpy_s(name, aux);
	}
	char* getName() {
		return name;
	}
	void setMarks(int* aux) {
		for (int i{}; i < mSIZE; i++)
			marks[i] = aux[i];
	}
	int* getMarks() {
		return marks;
	}

	Student( char *aux, int* n) {
		strcpy_s(name, aux);

		marks = new int[mSIZE];
		int i;
		for (i = 0; i < mSIZE; i++) {
			marks[i] = n[i];
		}

	}
	Student() {
		strcpy_s(name, "Nespecificat");
		marks = new int[mSIZE];
	}
	Student(const Student& x) {
		strcpy_s(name, x.name);
	
		marks = new int[mSIZE];
		int i;
		for (i = 0; i < mSIZE; i++)
			marks[i] = x.marks[i];
	}

	Student& operator=(Student& x) {

		if (this != &x) {
			strcpy_s(name, x.name);
		
			for (int i = 0; i < mSIZE; i++)
				marks[i] = x.marks[i];
		}
		return x;
	}

	
	~Student() {
		if(marks!=NULL)
		delete[] marks;
	}
};

int main() {
	char name[30];
	int marks[mSIZE];
	cout << "\n Enter the name of the student : ";
	cin.getline(name, 30);
	cout << "\nEnter the marks of the student ( " << mSIZE << ") :";
	for (int i{}; i < mSIZE; i++)
		cin >> marks[i];
	
	Student s1(name, marks);
	cout << "\n\nData of the first obj \n Name  : " << s1.getName();
	int*arr = s1.getMarks();
	for (int i{}; i < mSIZE; i++)
		cout << "\n" << arr[i] << " ";

	Student s2(s1);
	cout << "\n \nShowing data of the obj2(used copy const)\nName  : " << s2.getName();
	cout << "\n Marks :  \t";
	int * arr2 = s2.getMarks();
	for (int i{}; i < mSIZE; i++)
		cout  << arr2[i] << " ";
	Student s3;
	for (int i = 0; i < 2; i++)
	{
		if (i == 1)
		{
			s3 = s2;
			cout << "\n\n Showing data of the obj3(after the assing operator )  ";
		}
		else cout << "\n\nShowing data of the obj3 before the assign operator !:";
		cout << " \nName  : " << s3.getName();
		cout << "\n Marks :  \t";
		int* arr3 = s3.getMarks();
		for (int i{}; i < mSIZE; i++)
			cout << arr3[i] << " ";
	}
}
