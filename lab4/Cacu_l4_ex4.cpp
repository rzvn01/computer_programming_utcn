/* Cacu Razvan lab4 prb4 
Write a C/C++ application that reads from the keyboard 2 arrays of positive numbers. The program determines
a 3-rd array that contains all the elements in the initial arrays, increasingly ordered. The elements that have the
same value must appear a single time in the ordered array.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> first, second;


int main()
{
	int value, n, m;

	cout << "\nSize of the first array : ";
	cin >> n;

	for (int i{}; i < n; i++)
	{
		cin >> value;
		first.push_back(value);
	}

	cout << "\nSize of the second  array : ";
	cin >> m;

	for (int i{}; i < m; i++){
		cin >> value;
		second.push_back(value);
	}
	first.insert(first.begin(), second.begin(), second.end());
	sort(first.begin(), first.end());
	first.erase(unique(first.begin(), first.end()), first.end());

	cout << "\nThe sorted and unique array is : ";
	for (auto it : first) 
		cout << it << " ";
	return 0;
}