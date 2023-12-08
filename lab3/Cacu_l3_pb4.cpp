/*Cacu Razvan lab3 prb4
In a software company, some data packets must be broadcasted to n (<=7) subsidiaries, n being entered from
the keyboard. The subsidiaries are located at different distances and the transmission costs depend on those
distances. The data packets must reach their destination, irrespective of the existence of a direct connection
between the main company and a certain subsidiary (use other intermediate subsidiaries if necessary). The
costs associated to each direct link are entered from the keyboard. Any subsidiary can be considered as the
transmitting company packets. Determine and display the route that the data packets have to follow in order to
minimize the total transmission cost. The implementation can be recursive or non-recursive. Use a LUT (Look
Up Table) to match the values of the obtained solution with matching strings of characters with city names.

*/
#include<iostream>
#include<assert.h>
using namespace std;

int cost[7][7], x[7], y[7];
char LUT[7][50];

int max_cost(int[][7], int);
int pos(int);
int main()
{
	int k, n;
	long mcost, ncost;
	char aux[50];
	cout << " \n Enter the value of n : ";
	cin >> n;
	assert(n <= 7);
	getchar();
	for (int i{}; i < n; i++)
	{
		
		cout << "\n New city : ";
		cin.getline(LUT[i], 50);
	}

	cout << "\n The cost matrix : ";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "cost[" << i << "][" << j << "] : ";
			cin >> cost[i][j];
		}
	cout << "The cost matrix is  : \n";
	for (int i = 0; i < n; i++)
	{
		cout << "\t";
		for (int j = 0; j < n; j++)
			cout << cost[i][j] << " ";
		cout << endl;
	}
	mcost = n * (long)max_cost(cost, n) + 1;

	cout << "\nThe initial max cost is : " << mcost;
	k = 0;
	cout << "\nThe initial city :";
	cin >> x[k];
	k = 1; x[k] = -1;
	do {
		while (x[k] < n)
		{
			x[k]++;
			if (pos(k)) if ((k == (n - 1)) && (cost[x[n - 1]][x[0]] != 0)) {
				ncost = 0;
				for (int i = 0; i < n - 1; i++) ncost += cost[x[i]][x[i + 1]];
				ncost += cost[x[n - 1]][x[0]];
				if (ncost < mcost)for (int i = 0; i < n; i++) { y[i] = x[i]; mcost = ncost; }
			}
			else { k++; x[k] = -1; }
		}
		k--;
	} while (!(k < 1));

	printf("\nThe route is: ");
	for (int i = 0; i < n; i++)
		printf("%s \t", LUT[y[i]]);
	printf("\nThe cost is: %ld", mcost);

	return 0;
}
int max_cost(int mat[][7], int n)
{
	int max = mat[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (mat[i][j] > max)max = mat[i][j];
	return max;
}
int pos(int k)
{
	if (k == 0)return 1;
	if (cost[x[k - 1]][x[k]] != 0)
	{
		for (int i = 0; i < k; i++)
			if (x[k] == x[i]) return 0;
		return 1;
	}
	return 0;
}
