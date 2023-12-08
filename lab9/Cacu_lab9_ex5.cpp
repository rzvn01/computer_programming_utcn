/*Cacu Razvan lab9 prb5
/*Overload the [ ] operator for the Department class that contains an array of Employee objects (that has as
variables the name (character array) and the salary (float)). When the operator is applied to a Department
object, it returns (or displays) all the data related to the Employee object with that index.
*/

#include  <iostream>
using  namespace  std;


class Department;

class Employee {
	char name[20];
	float salary;
	friend Department;
public:
	char* getName() { return name; }
	float getSalary() { return salary; }
	void setName(char* aux) {
		strcpy_s(name, aux);
	}
		void setSalary(float aux) {
			salary = aux;
		}
};

class Department {
	Employee* x;
	int n;
public:
	Department() {
		n = 3;
		x = new Employee[3];
	}
	Department(int numar) {
		n = numar;
		x = new Employee[n];
	}
void setEmployee(Employee* aux){ 
	for (int i{}; i < n; i++)
	{
		strcpy_s(x[i].name, aux[i].name);
		x[i].salary = aux[i].salary;
	}
	}
void operator[](int aux) {
	if (aux >= 0 && aux < n)
	{
		cout << "\nThe name of the employee " << x[aux].getName();
		cout << "\n Salary : " << x[aux].getSalary();

	}
}
};

	int  main() {
		int  var;
		cout << "Enter the number of employees : ";
		cin >> var;
		Department d1(var);
		char name[20];
		float sal;
		Employee* res = new Employee[var];
		for (int i{}; i < var; i++) {
			getchar();
			cout << "\nEnter the name of the employee : ";
			cin.getline(name, 20);
			res[i].setName(name);
			cout << "\n Enter the salary : ";
			cin >> sal;
			res[i].setSalary(sal);
		}
		d1.setEmployee(res);
		int x;
		cout << "\nEnter the index of the employee you want to check : ";
		cin >> x;
			d1[x-1];
	}