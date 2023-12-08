#include<iostream>
#include<ctime>

#include<string>

using namespace std;

void rules(string);

int main()
{
	int coin, user_choice, balance, bet;
	string name;
	char choice = 'n';
	cout << "Please enter your name : ";
	cin >> name;

	cout << "\nPlease enter your balance $: ";
	cin >> balance;
	do {
		system("CLS");
		rules(name);
		srand(time(0));
		coin = rand() % 2 + 1;
		cout << "\nYour balance : " << balance;

		cout << "\n Enter your bet :";
		cin >> bet;
		while (bet > balance) {
			cout << "\nThe bet is over your balance !\n Your balance is " << balance << "$\n Try again :";
			cin >> bet;
		}

		cout << " Time to chose (1 for head 2 for tails ) :";
		cin >> user_choice;
		while (user_choice != 1 && user_choice != 2)
		{
			cout << "Invalid input \nTry afain";
			cin >> user_choice;
		}

		if (coin == user_choice)
		{
			cout << "WIN !";
			balance += bet * 5;
		}
		else {
			cout << " Lose  :(";
			balance -= bet;
		}
		if (coin == 1)
			cout << " The result is HEAD.";
		else
			cout << " The result is TAILS .";

		if (balance == 0)
		{
			cout << " We re sorry but you balance is 0 \n\n\n Thanks for playing ";
			exit(1);
		}
		cout << "Your balance is : " << balance << "$";
		cout << "Still wanna play ? (Y/N)";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');

}

void rules(string name)
{
	cout << " Welcome " << name << " to our flip coin game !\n\n\ ";
	cout << "Choose 1 for head 2 for tails !\n";
	cout << "Win 5 times  your bet or try again !\n";
	cout << "Have fun !";
}