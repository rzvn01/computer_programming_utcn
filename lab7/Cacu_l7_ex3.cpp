/*Cacu Razvan lab7 prb3 
Create a class named Student that has as private attributes the name, surname, some marks
(array 7 int values), the group.Allocate the necessary amount of memory for storing n 
students. Determine the average mark with a method from the class for each student and use
it for sorting the students. Display the ordered array (name, surname, group, average_mark).
The destructor will display a message.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Student {
	char name[30], surname[30];
	int marks[7];
	int group;
	float average;
public:
	 void setName(char* x) { strcpy(name, x); }
	 char* getName(void) { return name; }

	void setSurname(char* x) { strcpy(surname, x); }
	char* getSurname(void) { return surname; }

	void setMarks(int* arr) {
		for (int i{}; i < 7; i++)
			marks[i] = arr[i];
	}
	int* getMarks(void) { return marks; }

	void setGroup(int x) { group = x; }
	int getGroup(void) { return group; }

	void setAverage(void) {
		int sum = 0;
		for (int i{}; i < 7; i++)
			sum += marks[i];
		average = (float)sum / 7;
	}
	float getAverage(void) { return average; }
	~Student() {
		cout << "\nDestructor called !";
	}
}*arr; 

int student_sort(const void* a, const void* b);

int main(void) {
	int number;
	char aux[30];
	int val;
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
		cout << " \n Enter the marks : ";
		int marks[7];
		for (int i{}; i < 7; i++)
			cin >> marks[i];
		arr[i].setMarks(marks);
		cout << " \nGroup : ";
		cin >> val;
		arr[i].setGroup(val);
		arr[i].setAverage();

	}
	qsort(arr, number, sizeof(arr[0]), student_sort);
	for (int i{};i<number;i++)
	{
		cout << "\n\t Data of student #" << i + 1 << "\n\n";
		cout << "\nName : " << arr[i].getName();
		cout << "\nSurname: " << arr[i].getSurname();
		cout << "\nThe marks are: ";
		int* a = arr[i].getMarks();
		for (int i{}; i < 7; i++)
			cout << a[i] <<" ";
		cout << "\nThe group is : " << arr[i].getGroup();
		cout << "\nThe average is : " << arr[i].getAverage();

	}
}

int student_sort(const void* a, const void* b)
{
	Student* x = (Student*)a;
	Student* y = (Student*)b;
	if (strcmp(x->getName(), y->getName()) != 0)
		return strcmp(x->getName(), y->getName());
	else if (strcmp(x->getSurname(), y->getSurname()) != 0)
		return strcmp(x->getSurname(), y->getSurname());
	else if (x->getGroup() != y->getGroup())
	{
		if (x->getGroup() > y->getGroup())
			return x->getGroup() - y->getGroup();
		else return y->getGroup() - x->getGroup();
	}
	else if (x->getAverage() > y->getAverage())
		return -1;
	else if (x->getAverage() < y->getAverage())
		return 1;
	else return 0;

}
