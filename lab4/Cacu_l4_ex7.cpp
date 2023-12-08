/*Cacu Razvan lab4 prb7
Write a program that sorts a stock of computers, represented in the program as objects created from a structure
that stores the computers’ characteristics: name (string of characters), processor type (string of characters),
frequency (long int), RAM memory (int), price (float). The sorting is performed, as specified by the user, by
price, memory amount, frequency, or processor type. Use the qsort( ) library function or any other sorting
technique. Next sort the data using a character string and a numerical field. Display the results.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<assert.h>

using namespace std;

struct Computers{
	char name[50];
	char processor_type[50];
	long int frequency;
	int RAM;
	float price;
};

void print_computer(Computers);
Computers data_read(Computers);

bool cmp_name(Computers a, Computers b);
bool cmp_cpu(Computers a, Computers b);
bool cmp_frequency(Computers a, Computers b);
bool cmp_ram(Computers a, Computers b);
bool cmp_price(Computers a, Computers b);



int main()
{
	std::vector<Computers>computer;
	Computers a{};
	int n;
	std::cout << "\n The number of computers : ";
	std::cin >> n;
	for (int i{}; i < n; i++)
	{
		a = data_read(a);
		computer.push_back(a);
	}
	int choice;
	cout << "Sorted mothods :\n1-name\n2-CPU type \n3-RAM\n4-Frequency\n5-price\n Your choice : ";
	cin >> choice;
	assert(choice ==  1||choice==2||choice==3||choice==4||choice==5 );
	switch (choice) {
	case 1:
	{ sort(computer.begin(), computer.end(), cmp_name);
	break; }
	case 2:
	{ sort(computer.begin(), computer.end(), cmp_cpu);
	break; }
	case 3:
	{ sort(computer.begin(), computer.end(), cmp_ram);
	break; }
	case 4:
	{ sort(computer.begin(), computer.end(), cmp_frequency);
	break; }
	case 5:
	{ sort(computer.begin(), computer.end(), cmp_price);
	break; }
	default: break;

	
	}
	system("cls");
	cout << "The sorted computers are  \n";
	for (int i{}; i < n; i++)
	{
		cout << endl;
		print_computer(computer[i]);
	}
}


Computers data_read(Computers x)
{
	    getchar();
		cout << "Name: ";
		cin.getline(x.name, 50);
		cout << "CPU type: ";
		cin.getline(x.processor_type, 50);
		cout << "Frequency: ";
		cin >> x.frequency;
		cout << "RAM size: ";
		cin >> x.RAM;
		cout << "Price: ";
		cin >> x.price;

		return x;

		
}



	void print_computer(Computers x) {
		cout << "Name: " << x.name <<endl;
		cout << "CPU type: " << x.processor_type << endl;
	cout << "Frequency: " << x.frequency << endl;
	cout << "RAM: " << x.RAM << endl;
	cout << "Price: " << x.price <<endl;
	}


	bool cmp_name(Computers a, Computers b) { return (strcmp(a.name, b.name) < 0); }
	bool cmp_price(Computers a, Computers b) { return (a.price < b.price); }
	bool cmp_frequency(Computers a, Computers b) { return (a.frequency < b.frequency); }
	bool cmp_ram(Computers a, Computers b) { return (a.RAM < b.RAM); }
	bool cmp_cpu(Computers a, Computers b) { return (strcmp(a.processor_type, b.processor_type) < 0); }
