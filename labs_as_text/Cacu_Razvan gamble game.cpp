#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include <cstdlib> 
#include <ctime>

using namespace std;

void rules();

struct user_credits {
	string username, password;
};

user_credits Register(user_credits);
string Login();

int main()
{
	srand(time(0));
	int balance, bet, guess, choice, dice;
	user_credits user1;
	string name;
	char choice2 = 'n';
	bool login = false;
	cout << "\n\t1-Register \n\t 2-Login \n";
	cout << " Your choice :";
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "Invalid input !\n Try again:";
		cin >> choice;
	}
	if (choice == 1)
	{
		user1 = Register(user1);
		main();
	}
	else
		name = Login();

	cout << "\nHello " << name << "!\nWelcome to our roullete game !";
	cout << "enter your balance $ :";
	cin >> balance;
	while (choice2 == 'Y' || choice2 == 'y'){
		system("cls");
		rules();
		cout << "\n\nYour current balance is $ " << balance << "\n";
		do
		{
			cout << "Hey, " << name << ", enter amount to bet : $";
			cin >> bet;
			if (bet > balance)
				cout << "Betting balance can't be more than current balance!\n"
				<< "\nRe-enter balance\n ";
		} while (bet > balance);

		do
		{
			cout << "Guess any betting number between 1 & 10 :";
			cin >> guess;
			if (guess <= 0 || guess > 10)
				cout << "\nNumber should be between 1 to 10\n"
				<< "Re-enter number:\n ";
		} while (guess <= 0 || guess > 10);
		dice = rand() % 10 + 1;
		if (dice == guess)
		{
			cout << "\n\nYou are in luck!! You have won Rs." << bet * 100;
			balance = balance + bet * 10;
		}
		else
		{
			cout << "Oops, better luck next time !! You lost $ " << bet << "\n";
			balance = balance - bet;
		}
		cout << "\nThe winning number was : " << dice << "\n";
		cout << "\n" << name << ", You have balance of $ " << balance << "\n";
		if (balance == 0)
		{
			cout << "You are broke :( ";
			break;
		}
		cout << "\n\n-->Do you want to play again (y/n)? ";
		cin >> choice2;


	} 
	cout << "\n\n\n";
	cout << "\n\nThanks for playing the game. " << "\n\n";
	return 0;
}
user_credits Register(user_credits x)
{
	string name;
	cout << "\n\tEnter your name : ";
	cin >> name;
	cout << "\n\tPlease enter your username ";
	cin >> x.username;
	cout << "\n\tEnter your password :";
	cin >> x.password;
	ofstream file;
	file.open("data." + x.username + ".txt");
	file << name << endl << x.username << endl << x.password << endl;
	file.close();
	return x;

}
string  Login() {

	string username, password, un, pw, name;
	cout << "\n\tEnter the username :"; cin >> username;
LOOP: cout << "\n\tEnter the password :"; cin >> password;

	ifstream read("data." + username + ".txt");
	getline(read, name);
	getline(read, un);
	getline(read, pw);

	if (un == username && password == pw)
		cout << "\n\tLogged in!";
	else if (un == username && password != pw)
		goto LOOP;
	else {
		cout << " \n\tCouldnt verify ur info !";
		exit(1);
	}
	return name;
}
void rules()
{
	system("cls");
	cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
	cout << "\t1. Choose a number between 1 to 10\n";
	cout << "\t2. Winner gets 100 times of the money bet\n";
	cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}