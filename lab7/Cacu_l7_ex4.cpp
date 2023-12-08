/*Cacu Razavn lab7 prb4 
Model in OOP a class named Student containing name, surname the number of marks and the
marks from the winter session exams specified as an int pointer. Display the name of the
students who have arears exams and the first three students in the group based on the media
that will be also displayed*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Student {
	char name[30], surname[30];
	int *marks;
	int marks_number;
	bool arears=false;
	float average;
public:
	void setName(char* x) { strcpy(name, x); }
	char* getName(void) { return name; }

	void setSurname(char* x) { strcpy(surname, x); }
	char* getSurname(void) { return surname; }

	void setMarks(int* arr);
	int* getMarks(void) { return marks; }

	void setMarks_number(int x) { marks_number = x; }
	int getMarks_number(void) { return marks_number; }
	
	void setArears(bool x) {   arears = x;	}
	bool getArears() {		return arears;	}
	
	void setAverage();
	float getAverage(void) { return average; }
	
	~Student() {
		cout << "\nDestructor called !";
	}
}*arr;
int avg_fnc(const void* a, const void* b);

int main() {

	int number;
	char aux[30];
	int val=1;
	cout << "\nEnter the numbe of students : ";
	cin >> number;
	arr = new Student[number];
	for (int i{}; i < number; i++)
	{
		getchar();
		cout << "\n\tStudent #" << i + 1 << "\n\n";
		cout << "\n Name ";
		cin.getline(aux, 30);
		arr[i].setName(aux);
		cout << "\n Surname ";
		cin.getline(aux, 30);
		arr[i].setSurname(aux);
		cout << " \n Enter the number of marks of the student : ";
		cin >> val;
		arr[i].setMarks_number(val);
		cout << " \n Enter the marks : ";
		int* marks = new(nothrow)int[val];
		for (int i{}; i < val; i++)
			cin >> marks[i];
		arr[i].setMarks(marks);
		arr[i].setAverage();
	}
	qsort(arr, number, sizeof(arr[0]), avg_fnc);
	cout << "\n The top 3 students are: ";
	for (int i{}; i < 3; i++) {
		cout << "\n\t Data of student #" << i + 1 << "\n\n";
		cout << "\nName : " << arr[i].getName();
		cout << "\nSurname: " << arr[i].getSurname();
		cout << "\nThe marks are: ";
		int* a = arr[i].getMarks();
		for (int j{}; j < arr[i].getMarks_number(); j++)
			cout << a[j] << " ";
		cout << "\nThe marks number  is : " << arr[i].getMarks_number();
		cout << "\nThe average is : " << arr[i].getAverage();
	}
	cout << "\n The students with arears are : \n";
	for (int i{}; i < number ; i++) {
		if(arr[i].getArears() == true)
		cout << "\nName : " << arr[i].getName();
	
	}
}
void Student::setAverage() {
	int sum = 0;
	for (int i{}; i < marks_number; i++)
		sum += marks[i];
	average = (float)sum / marks_number;
}
void Student::setMarks(int* arr) {
	marks = new(nothrow)int[marks_number];
	for (int i{}; i < marks_number; i++)
	{
		marks[i] = arr[i];
		if (marks[i] < 5)
			arears = true;
	}
}

int avg_fnc(const void* a, const void* b)
{
	Student* x = (Student*)a, * y = (Student*)b;
	float z = x->getAverage() - y->getAverage();
	if (z > 0)
		return -1;
	else if(z < 0)
		return 1;
	else return 0;
}
