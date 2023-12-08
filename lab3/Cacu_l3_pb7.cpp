
#include <iostream>
#include <fstream>
using namespace std;
#define DIM 2000

int greater(int*, int, int);

int main()
{
	int n, x[DIM];
	ifstream myfile("numbers.txt");
	
	for (int i = 0; i < DIM; i++)
	{
		fin >> x[i];
	}
	cout << "\nThe greatest common divider of the array is:" << greater(x, 0, DIM-1 );

	return 0;
}
int greater(int* a, int first, int last)
{
    int x = 0, y = 0, gcd = 0;
    if (first == last){
        gcd = a[first];
        return gcd;}
    else {
        x = greater(a, first, (first + last) / 2);
        y = greater(a, (first + last) / 2 + 1, last);
        if (x < 0)
         x = -x; 
        if (y < 0)
            y = -y;
        while (x != y){
            if (x > y)
            x = x - y;
            else
            y = y - x;  }
        gcd = x;
        return gcd;
    }
}