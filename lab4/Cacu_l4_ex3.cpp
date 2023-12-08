/*Cacu Razvan lab4 prb3
Use the library function "qsort( )" for sorting an array of records that contain a name, a surname, a personal
identification code and an employment date. The sorting is based on the data stored in some specific fields
(like name, employment date, etc.).
*/


#include<iostream>
#include<string>
#include<assert.h>
using namespace std;


void data_read(int);
void data_print(int);

struct Records {
	char name[50];
	char surname[50];
	long int code;
	int year;
	int day;
	char month[30];
	
}*record;

int cmp_name(const void* a, const void* b) {
	return strcmp(((Records*)a)->name, ((Records*)b)->name);
}

int cmp_sname(const void* a, const void* b) {
	return strcmp(((Records*)a)->surname, ((Records*)b)->surname);}
int cmp_code(const void* a, const void* b) {
	return ((Records*)a)->code - ((Records*)b)->code;}


int main() {

	int n;
	cout << "nEnter the numbers of records : ";
	cin >> n;

	record = new Records[n];

	data_read(n);

	int choice;
	cout << "\n How you want to sort the arrays : \n1-name\n2-surname\n3-code \n Your choice : ";
	cin >> choice;
	assert(choice == 1 || choice == 2 || choice == 3);
	if(choice==1)
	qsort(record,n,sizeof(record[0]),cmp_name);
	else if(choice==2)
		qsort(record, n, sizeof(record[0]), cmp_sname);
	else 		
		qsort(record, n, sizeof(record[0]), cmp_code);

	cout << "\nThe records were sorted !\n  ";
	data_print(n);

	return 0;

} 
void data_read(int n)
{
	for (int i{}; i < n; i++)
	{
		getchar();
		cout << "\nName : ";
		cin.getline(record[i].name, 50);
		cout << "\nSurame : ";
		cin.getline(record[i].surname, 50);
		cout << "\n Code : ";
		cin >> record[i].code;
		cout << "\n Emp day:";
		cin >> record[i].day;
		getchar();
		cout << "\nEmp month ";
		cin.getline(record[i].month, 30);
		cout << "\n Emp year :  ";
		cin >> record[i].year;
	}
}
void data_print(int n)
{
	for (int i{}; i < n; i++)
	{
		cout << "\n Name : " << record[i].name << "\n Surname : " << record[i].surname;
		cout << " \n Code : " << record[i].code  ;
		cout << "\nEmp Date : " << record[i].day << " " << record[i].month << " " << record[i].year;

	}
}