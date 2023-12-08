#include <iostream>
#include <math.h>
#define f(x) 1/(1+x*x)
using namespace std;
#define SIZE 100

int main()
{
	int i;
	float fx = .0f, size, aux, a, b;

	cout << "\nEnter  value of a : "; cin >> a;
	cout << "\nEnter  value of b : "; cin >> b;


	size = (b - a) / SIZE;
	fx = f(a) + f(b);
	for (i = 1; i < SIZE; i++)
	{
		aux = a + i * size;
		fx = fx + 2 * (f(aux));
	}

	cout << "The result of integration is: " <<  fx * size / 2.0f;;
} 
