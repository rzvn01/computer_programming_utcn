/*Cacu Razvan lab11 prb2
* Extend the base class from the fourth example by adding some other virtual methods, which
will be implemented in the derived classes (like the setter and getter for the value of greutate).
*/

#include<iostream>
using namespace std;

class Vehicul {
protected:
	int roti;
	float greutate;
public:
	virtual void mesaj() {
		cout << "Mesaj din clasa Vehicul\n";
	}
	virtual void setGreutate(int aux) {
		greutate = aux;
	};
	virtual float getGreutate() {
		return greutate; 
	};
};
class Automobil : public Vehicul {
	int incarcatura_pasageri;
public:
	void mesaj() override {
		cout << "Mesaj din clasa Automobil\n";
	}
	virtual void setGreutate(int aux) override{
		greutate = aux;
	};
	virtual float getGreutate() override{
		return greutate;
	};

};
class Camion : public Vehicul {
	int incarcatura_pasageri;
	float incarcatura_utila;
public:
	int pasageri() {
		return incarcatura_pasageri;
	}
	virtual void setGreutate(int aux) override {
		greutate = aux;
	};
	virtual float getGreutate() override {
		return greutate;
	};
};
class Barca : public Vehicul {
	int incarcatura_pasageri;
public:
	int pasageri() {
		return incarcatura_pasageri;
	}
	void mesaj() override {
		cout << "Mesaj din clasa Barca\n";
	}
	virtual void setGreutate(int aux) override{
		greutate = aux;
	};
	virtual float getGreutate() override{
		return greutate;
	};
};



int main() {
 
	Vehicul monocicleta;
	Automobil ford;
	Camion semi;
	Barca barca_de_pescuit;
	monocicleta.mesaj();
	ford.mesaj();
	semi.mesaj(); 
	barca_de_pescuit.mesaj();
	
	Vehicul* pmonocicleta;
	Automobil* pford;
	Camion* psemi;
	Barca* pbarca_de_pescuit;
	cout << "\n";
	pmonocicleta = &monocicleta;
	pmonocicleta->mesaj();
	pford = &ford;
	pford->mesaj();
	psemi = &semi;
	psemi->mesaj();//din CB
	pbarca_de_pescuit = &barca_de_pescuit;
	pbarca_de_pescuit->mesaj();
	// apel prin intermediul unui pointer catre un obiect al clasei de baza
	cout << "\n";
	pmonocicleta = &monocicleta;
	pmonocicleta->mesaj();//Vehicul
	pmonocicleta = &ford;//upcasting
	pmonocicleta->mesaj();//Automobil
	pmonocicleta = &semi;//upcasting
	pmonocicleta->mesaj();//Camion- Vehicul
	pmonocicleta = &barca_de_pescuit;//upcasting
	pmonocicleta->mesaj();//Barca
	return 0;
}
