/* Binary Search : Efficiently locates a target value within a sorted array.
 The binary search is an searching algorithm used to find an element in sorted array
Time Complexity:

Best Case: O(1) - When the target element is found at the middle of the array in the first comparison.
Average Case: O(log n) - Each comparison reduces the search space by half, leading to logarithmic time complexity.
Worst Case: O(log n) - Even in the worst-case scenario, binary search operates in logarithmic time due to its divide-and-conquer approach.
Space Complexity:

Binary search typically has a space complexity of O(1) since it operates in-place and does not require additional memory proportional to the size of the input array.

Applications:

Binary search is commonly used in programming tasks that involve searching, such as searching for an element in a sorted array, finding the index of a specific value, or determining if a value exists in a dataset.
It is also utilized in various algorithms and data structures, including binary search trees and binary heaps.
Advantages:

Binary search is highly efficient, especially for large datasets, due to its logarithmic time complexity.
It's relatively simple to implement and understand.
It can be applied to any sorted array, making it versatile in various programming scenarios.
Limitations:

Binary search requires the input array to be sorted beforehand. If the array is not sorted, binary search cannot be applied.
It may not be the best choice for small datasets or dynamic datasets that frequently change, as the overhead of sorting the array initially may outweigh the benefits of the search algorithm.*/
// lets code it



#include <iostream>
using namespace std;
void input_array(int size ,int* arr)
{   
    
    cout<<"the Elememts should be in ascending or decending  order "<< endl;
    for (int i = 0; i < size; i++)
    {
        cin>> arr[i];

    }
}

void print_array(int size ,int* arr)
{
    cout<<"the Elememts are "<< endl;

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<< "\t";

    }
}


//implementing a binary serch program
void binary_search(int size , int* arr)
{    int target;
    cout<< "Enter the targeted element \t";
    cin>>target;
     // as we are using divide and conquror method we will always divide our array into two parts 
     // lets get start , end  and Mid

     int start =  0;// before any divide process it will be at zero
     int end = size -1; // before array index starts from zero
     int mid= start + (end - start )/2;
     
     while (start < end) 
     {
       if(target == arr[mid])
       {
        cout << "Found  at position \t "<< mid+1 << " \t and at index  \t" << mid << endl;

        break;
       }
       else if (target > arr[mid])
       {
        end = mid-1;
       }
       else
       {
        start = mid+1; // divide the array that put start at the mid
       }

        mid= start + (end - start )/2; // calculate mid ever time

     }
     




}

int main()
{
    // Decleaing an array
    int* arr = new int[100];
    int size;

    // lets take input from USER
    cout<<"Number of Elements \t";
    cin>> size;
    input_array(size,arr);

    // to print this array
     print_array(size ,arr);

     //binary search
     binary_search(size,arr);


}