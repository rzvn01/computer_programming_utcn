/*Cacu Razvan lab3 prb2 
Consider a computing system that monitors the data transfer on a main communication channel that has a
maximum flow capacity of 40 MBps. The data stream can be shared among max 10 users. The channel's data
flow is divided automatically by the monitoring program using max 10 (0...9) sub-unitary weights, each of
them being associated with a user. The weights are entered from the keyboard when the program starts, and
their sum must be 1. If the weights are entered correctly, generate all the possible solutions for each one of the
max 10 individual channels, considering that the main channel has the debit between 2MBps and 40 MBps.
Calculate the solutions with a precision of MBps. The 0 MBps will be assigned for those channels that cannot
have the minimum of 2MBps. Display the solutions. The implementation can be both recursive and nonrecursive. 
*/

#include<iostream>
#include<assert.h>
using namespace std;

int pos(int, int, int*, float*);
void display(int, int*);


int main()
{
	float w[10];
	int sol[10];
	int users, capacity;
	float ws = 0;
	cout << "\n The capacity : ";
	cin >> capacity;
	assert(capacity >= 2 && capacity <= 40);
	cout << "The number of users : ";
	cin >> users;
	assert(users <= 10 && users >= 1);

	cout << "Wheights for the users : ";
	for (int i{}; i < users; i++)
	{
		cin >> w[i];
		ws += w[i];
	}
	assert(ws == 1);
	int k = 0;
	sol[k] = .0f;
	do
	{
		while (sol[k] < capacity)
		{
			sol[k] += 1;
			if (k == (users - 1))
			{
				if (pos(users ,capacity,sol,w)) display(users ,sol);
			}
			else { k++; sol[k] = 0; }
		}
		k--;
	} while (!(k < 0));

	return 0;
}
int pos(int users,int capacity,int* sol,float*w)
{
	int count = 0, i = 0;
	while (i != users)
	{
		for (int j = 0; j < users; j++)
		{
			if (round((capacity * w[j])) == sol[i]) count++;
		}
		i++;
	}
	if (count == users) return 1;
	else return 0;
}

void display(int users, int* sol)
{
	for (int i{}; i < users; i++)
		if (sol[i] < 2.0)
			cout << " sol =0\t";
		else cout << " sol = \t " << sol[i];
	cout << endl;
}