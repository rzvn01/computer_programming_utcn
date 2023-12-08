/*Cacu Razvan lab4 prb6
Read from the keyboard a one-dimensional array of m integers and an integer value n<m. Split the array in 2
subarrays as it follows:
a) the first array will contain the first n elements of the initial array
b) the second subarray will contain the rest elements of the initial array
Realize the following operations:
- sort increasingly the subarrays
- sort the initial array, by interlacing the sorted subarrays (merge-sort)
*/

#include<iostream>
#include<vector>
#include<algorithm>
std::vector<int> merge(std::vector<int>, std::vector<int>);
std::vector<int> first, second;

int main()
{
	int n, m, value;

	std::cout << "\nThe size of first array : ";
	std::cin >> n;

	for (int i{}; i < n; i++)
	{
		std::cin >> value;
		first.push_back(value);
	}
	std::cout << "\n The size of second array : ";
	std::cin >> m;
	for (int i{}; i < m; i++)
	{
		std::cin >> value;
		second.push_back(value);
	}
	std::sort(first.begin(), first.end());
	std::sort(second.begin(), second.end());
	first = merge(first, second);

	for (auto& i : first)
	std::cout << i << " ";
}
std::vector<int> merge(std::vector<int> left, std::vector<int> right) {
	int leftCount = 0;
	int rightCount = 0;

	std::vector<int> results;

	bool useLeft;
	for (int i = 0; i < left.size() + right.size(); i++) {
		if (leftCount < left.size()) {
			if (rightCount < right.size()) {
				useLeft = (left[leftCount] < right[rightCount]);
			}
			else {
				useLeft = true;
			}
		}
		else {
			useLeft = false;
		}

		if (useLeft) {
			results.push_back(left[leftCount]);
			if (leftCount < left.size()) {
				leftCount++;
			}
		}
		else {
			results.push_back(right[rightCount]);
			if (rightCount < right.size()) {
				rightCount++;
			}
		}
	}
	return results;
}