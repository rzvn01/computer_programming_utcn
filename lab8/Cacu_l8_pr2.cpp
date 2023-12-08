/*Cacu Razvan lab8  prb2
* Write a C++ application in which the class Calculator has a private attribute called RAM_memory (int)
and a friend function named service_technician( ) that can modify the attribute’s value. The friend
function will be member in the class Motherboard, that encapsulates the processor_type variable (string of
characters). Write the code that allows the modifying of the processor_type’s value and the RAM_memory
from the friend function.*/

#include<iostream>
using namespace std;

class Motherboard ;

class Calculator {
  int	RAM_memory;
public: 
	void setRAM_memory(int a) {
		RAM_memory = a;
	}
	int getRAM_memory() {
		return RAM_memory;
	}
	friend void service_technician(Calculator& calc, Motherboard& motherb);
};
 class Motherboard {
	char processor_type[30];
public: 
	void setProcessor_type(char *c) {
		strcpy_s(processor_type, c);

	}
	char* getProcessor_type() {
		return processor_type;
	}
	friend void service_technician(Calculator& calc , Motherboard& motherb);
};

int main()
{

	Calculator c1{};
	Motherboard m1{};

	service_technician(c1, m1);
	cout << "\n The cpu name : " << m1.getProcessor_type();
	cout << "\n The RAM ammount : " << c1.getRAM_memory();
	
}

void service_technician(Calculator& c1, Motherboard& m1)
{
	int RAM;
	char cpu_name[30];
	
	cout << "\n Enter the name of the cpu : ";
	cin.getline(cpu_name, 30);
	m1.setProcessor_type(cpu_name);
	cout << "\nEnter the RAM ammount : ";
	cin >> RAM;
	c1.setRAM_memory(RAM);
}
