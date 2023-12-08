/*Cacu Razvan lab3 prb 12
Using a file that contains real ordered numbers, look for a value read from the keyboard. The searching method
will rely on an iterative binary search, the recursive algorithm and the bsearch() library function. Display the
values read from the file, the value to be searched and the position it was found (if any).
 */


#include<iostream>
#include<fstream>
using namespace std;

int binary_iterative(int*, int, int);
int binary_recursive(int *, int , int , int );
int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main()
{
	ifstream myfile("numbers.txt");
	int value, arr[10],*result,index;
	
	cout << "Please enter the value you want to find : ";
    	cin >> value;

	if(myfile.is_open())
		for (int i{}; i < 10; i++)
	     	myfile >> arr[i];
	
	 myfile.close();

     index = binary_iterative(arr, 10, value);
     (index != -1)
         ? cout << "\nThe value " << value << " was found using the iterative function at position : " << index
         : cout << "\nThe value " << value << " was not found using the iterative function !";
     index = binary_recursive(arr, 0,9, value);
     (index != -1)
         ? cout << "\nThe value " << value << " was found using the recursive function at position : " << index
         : cout << "\nThe value " << value << " was not found using the recursive function !";
     result = (int*)bsearch(&value, arr,10, sizeof(int), cmpfunc);
     (result != NULL)
         ? cout << "\nThe value " << value << " was found using the library function "
         : cout << "\nThe value " << value << " was not found using the library function !";

}
int binary_iterative(int nums[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
       

        int mid = (low + high) / 2;    
        

        
        if (target == nums[mid]) {
            return mid;
        }

        
        else if (target < nums[mid]) {
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }
    return -1;
}
int binary_recursive(int nums[], int low, int high, int target)
{
    
    if (low > high) {
        return -1;
    }


    int mid = (low + high) / 2;    
   
    if (target == nums[mid]) {
        return mid;
    }

    else if (target < nums[mid]) {
        return binary_recursive(nums, low, mid - 1, target);
    }
    else {
        return binary_recursive(nums, mid + 1, high, target);
    }
}