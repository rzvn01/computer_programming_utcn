/*Cacu Razvan lab8  prb7
* A kiosk sells newspapers, magazines and books. Each publication has a name, an editorial house, a
number of pages, the number of copies and a price (no VAT). Write the class that models the publications.
Introduce a static member named VAT_value (percentage) and a static method that modifies the value of
this variable. Determine the total income and the average price per page for each publication type. Modify
the VAT and redo the calculations. Order the printing houses by the total income and display the result.
*/


#include<iostream>
#include<assert.h>
using namespace std;


class Publications {
	int type;
	char name[50], editorial_house[50];
	int nr_pages, nr_copies;
	double price;
	static double VAT_value;

public : 
	

	void setType(int aux) {
		type = aux;
	}
	int getType() {
		return type;
	}
   
	void setName(char* aux) {
		strcpy_s(name, aux);
	}
	char* getName() {
		return name;
	}

	void setEditorial_House(char* aux) {
		strcpy_s(editorial_house,aux);
	}
	char* getEditorial_house() {
		return editorial_house;
	}
	
	void setNR_pages(int aux) {
		nr_pages = aux;
	}
	int getNR_page() {
		return nr_pages;
	}

	void setNR_copies(int aux) {
		nr_copies = aux;
	}
	int getNR_copies() {
		return nr_copies;
	}

	void setPrice(double aux) {
		price = aux;
	}
	double getPrice() {
		return price;
	}
	
	static void setVAT_value(double aux) {
		VAT_value = aux;
	}
	static double getVAT_value() {
		return VAT_value;
	}



}*arr;
double Publications::VAT_value;

void price_average(Publications* arr,int number);
int main() {
	int aux;
	cout << "\nHow many items are in ur kiosk ? \nA:";
	cin >> aux;
	arr = new(nothrow)Publications[aux];
	char name[30], ed_name[50];
	double price;
	int val;
	Publications::setVAT_value(0);
	for (int i{}; i < aux; i++) {

		cout << "\n Type(1-newspapers 2 - magazines,  3 - books) \nA : ";
		cin >> val;
		assert(val == 1 || val == 2 || val == 3);
		arr[i].setType(val);
		getchar();
		cout << "\n Name : ";
		cin.getline(name, 30);
		arr[i].setName(name);

		cout << "\n Editorial House  : ";
		cin.getline(ed_name, 30);
		arr[i].setEditorial_House(ed_name);

		cout << "\nNumber of pages : ";
		cin >> val;
		arr[i].setNR_pages(val);

		cout << "\nNumber of copies : ";
		cin >> val;
		arr[i].setNR_copies(val);
		
		cout << "\nPrice : ";
		cin >> price;
		arr[i].setPrice(price + Publications::getVAT_value() * price);
	}
	price_average(arr,aux);
	Publications::setVAT_value(17/100);
	for (int i{}; i < aux; i++) {
		double res = arr[i].getPrice() + Publications::getVAT_value() * price;
		arr[i].setPrice(res);

	}
	price_average(arr, aux);
}

	void price_average(Publications * arr,int aux){

		double type1_income = {}, type2_income{}, type3_income{}, type1_pages{}, type2_pages{}, type3_pages{};

		for (int i{}; i < aux; i++)
			switch (arr[i].getType())
			{
			case 1:
			{
				type1_income += arr[i].getPrice();
				type1_pages += arr[i].getNR_page();
			}
			case 2:
			{
				type2_income += arr[i].getPrice();
				type2_pages += arr[i].getNR_page();
			}
			case 3: {
				type3_income += arr[i].getPrice();
				type3_pages += arr[i].getNR_page();
			}


			default:
				break;
			}

		cout << "\n The income of the newspapers : " << type1_income;
		cout << "\n The average price per page for newspapers : " << type1_income / type1_pages;
		cout << "\n The income of the magazines : " << type2_income;
		cout << "\n The average price per page for magazines : " << type2_income / type2_pages;
		cout << "\n The income of the books  : " << type3_income;
		cout << "\n The average price per page for books : " << type3_income / type3_pages;
	}