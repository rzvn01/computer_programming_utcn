/*Cacu Razvan lab6 prb7 
Write a class named Safe that has as private attributes the cipher (pin, 4 int digits) and the
amount of money of double type. Implement the private methods getMoney( ) and setMoney(
). The public methods putInSafe( ) and getFromSafe( ) will call the previous private methods
only if the cipher sent as parameter matches the value stored inside the class. Display a
message if the cipher is not correct.
*/

#include<iostream>
#include<assert.h>
using namespace std;


class Safe {
	int cipher;
	double money_ammount;
public:
	void setMoney_ammount(double x) { money_ammount = x; }
	double getMoney_ammount() { return money_ammount; }
	void setCipher(int x) { this->cipher = x; }
	int getChiper() { return this->cipher; }
	void moneyWithdraw(int x) { money_ammount -= x; }
	void moneyDeposit(int x) { money_ammount += x; }
	
  };

int main() {
	Safe s1;
	int a,x,count =0;
	bool flag=1;
		char choice2;
	cout << "\nPlease enter a cipher(4 digits ) : ";
		cin >> a;
		int y = a;
		while (a != 0)
		{  
			a /= 10;
			count++;
		}
		if (count != 4)
		{
			cout << "The pin must be of 4 digits !";
				exit(1);
		}
	cout << "\nCipher registred !";

	s1.setCipher(y);
	s1.setMoney_ammount(1000);
	system("cls");
	cout << "\nPlease enter your pin : ";
	cin >> x;
	system("cls");
	if (x==s1.getChiper())
		cout << "\nPin correct !";
	else {
		cout << "\nPin incorect !";
		exit(1);
	}
	do
	{
		
			int t, test[4];
			cout << "\n 1- Withdraw money .\n2-Deposit money . \n3-Check your balance . \n";
			cin >> t;
			switch (t) {
			case 1:
			{  int x;
			system("cls");
			cout << "\n You have : " << s1.getMoney_ammount() << " $ ";
			cout << "\nEnter the ammount you want to withdraw : ";
			cin >> x;
			assert(x <= s1.getMoney_ammount());
			s1.moneyWithdraw(x);
			cout << "\nTransaction succesfull !";
			break; }

			case 2: {
				int x;
				system("cls");
				cout << "\n You have : " << s1.getMoney_ammount() << " $ ";
				cout << "\nEnter the ammount you want to deposit: ";
				cin >> x;
				s1.moneyDeposit(x);
				cout << "\nTransaction succesfull !";
				break; }
			case 3:
			{   system("cls");
				cout << "\nYour balance : " << s1.getMoney_ammount() << " $ ";
				break;

			}
			default: break;

			}
	
		
		cout << "\nDo you want to do other action ? ";
			cin >> choice2;
			choice2 = toupper(choice2);
	} while (choice2 == 'Y');
	cout << "\n Thank you !";
}
