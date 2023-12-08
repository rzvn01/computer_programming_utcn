/*Cacu Razvan Colocviu 2022 */


#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;

class Vehicle {
protected:
	string name, producer;
	int wheels;
public:
	Vehicle() {
		name = "No name !";
		producer = "No producer !";
		wheels = 0;
	}
	Vehicle(string n, string pr, int w) {
		name = n;
		producer = pr;
		wheels = w;
	}
	~Vehicle() {
		cout << "\nDestructor called !";
	}

	void setName(string a) {
		name = a;
	}
	string getName() {
		return name;
	}

	void setProducer(string a) {
		producer = a;
	}
	string getProducer() {
		return producer;
	}
	void setWheels(int a) {
		wheels = a;
	}
	int getWheels() {
		return wheels;
	}
	virtual void display() {
		cout.setf(ios::fixed);
		std::cout.width(30); std::cout << std::left;
		cout << "\nThe name is : " << name;
		std::cout.width(30); std::cout << std::left;
		cout << "\nThe producer is : " << producer;
		std::cout.width(30); std::cout << std::left;
		cout << "\nThe number of wheels : " << wheels;


	};
	friend istream& operator>> (istream& stream, Vehicle& ob);
	friend ostream& operator<<(ostream&, Vehicle& ob);
	Vehicle(const Vehicle& p1) { name = p1.name; producer = p1.producer; wheels = p1.wheels; }



};
class Car :public Vehicle {
	int power, capacity;
public:
	void setPower(int a) {
		power = a;
	}
	int getPower() {
		return power;
	}void setCapacity(int a) {
		capacity = a;
	}
	int getCapacity() {
		return capacity;
	}
	Car(int p = 0, int c = 0) {
		power = p;
		capacity = p;
	}
	~Car() {
		cout << "\nCar destructor called !";
	}
	virtual void display() override {


		cout.setf(ios::fixed);
		std::cout.width(30); std::cout << std::left;
		cout << "\nThe name is : " << name;
		std::cout.width(30); std::cout << std::left;
		cout << "\nThe producer is : " << producer;
		std::cout.width(30); std::cout << std::left;
		cout << "\nThe number of wheels : " << wheels;
		std::cout.width(30); std::cout << std::left;
		cout << "\nThe power is : " << power;
		std::cout.width(30); std::cout << std::left;
		cout << "\nThe capacity is " << capacity;


	}
	friend istream& operator>> (istream& stream, Vehicle& ob);
	friend ostream& operator<<(ostream&, Vehicle& ob);
	Car(const Car& p1) { name = p1.name; producer = p1.producer; wheels = p1.wheels; power = p1.power; capacity = p1.capacity; }
};

int main() {
	Vehicle v("M5", "BMW", 4), v1;
	v1.setName("M3");
	v1.setProducer("bmw");
	v1.setWheels(4);
	Car c1, c2(120, 2000);
	c1.setName("Yaris");
	c1.setCapacity(1200);
	c1.setProducer("Toyota");
	c1.setWheels(4);
	c1.setPower(100);
	c2.setName("supra");
	c2.setProducer("Toyota");
	c2.setWheels(4);
	ofstream myfile;
	myfile.open("Text.txt");
	myfile << v;
	myfile << v1;
	myfile << c1;
	myfile << c2;
	v1.display();
	v.display();
	c1.display();
	c2.display();
	Vehicle* pointervehicle = &v;
	pointervehicle->setName("A4");
	pointervehicle->setProducer("AUDI");
	pointervehicle->setWheels(4);
	cout << "\n\nThe modified pointer is : ";
	pointervehicle->display();
	myfile << *pointervehicle;
	Car* poitercar = &c1;
	poitercar->setName("Logan mcv");
	poitercar->setProducer("dacia");
	poitercar->setWheels(4);
	poitercar->setPower(220);
	poitercar->setCapacity(3000);
	cout << "\n\nThe modified pointer is : ";
	poitercar->display();
	myfile << *poitercar;
	Car c3(c2);
	//copy const used
	myfile << c3;
	Vehicle v3(v);
	myfile << v3;
	myfile.close();
}

ostream& operator<< (ostream& stream, Vehicle& ob)
{
	stream << ob.name << " " << ob.producer << " " << ob.wheels << "\n";
	return stream;

}

ostream& operator>> (ostream& stream, Car& ob)
{
	stream << ob.getName() << ob.getProducer() << ob.getWheels() << ob.getPower() << ob.getCapacity();
	return stream;
}