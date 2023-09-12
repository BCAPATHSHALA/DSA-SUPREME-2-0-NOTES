// Vector for 1D Array
#include<iostream>
#include<vector>
using namespace std;

// Function to print the 1D vector array
void printVector(vector<int> arr3){
    int size = arr3.size();
    for(int i=0;i<size;i++){
        cout<<arr3[i]<<" ";
    }
}

int main(){
    // Way 00: Static memory allocation with static array
    int arr1[5]={1,2,3,4,5};

    // Way 01: Bad Practice with Dynamic memory allocation with user input
    int n;
    cin>>n;
    int *arr2 = new int[n]; // Each element would be 0 or garbage value

    // Way 02: Always Good Practice with Dynamic array (vector STL C++)
    // In vector, dont tell size of vector array.
    // just keep inserting, we will manage the allocation

    // Lesson 01: Declare 1D array
    vector<int> arr3;

    // Lesson 02: Insert element in 1D vector array and how internally work
    arr3.push_back(1); // capacity=1  and  size=1
    arr3.push_back(2); // capacity=2  and  size=2
    arr3.push_back(3); // capacity=4  and  size=3
    arr3.push_back(4); // capacity=4  and  size=4
    arr3.push_back(5); // capacity=8  and  size=5

    cout<<"capacity = "<< arr3.capacity() << " size = "<< arr3.size()<<endl;

    // Lesson 03: Access 1D vector array's element
    for(int i=0;i<arr3.size();i++){
        cout<<arr3[i]<<" "; // 1 2 3 4 5
    }

    // Lesson 04: Delete element of 1D vector array
    arr3.pop_back(); // 1 2 3 4

    // Lesson 05: Taking input from user in 1D vector array
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr3.push_back(data);
        cout<<"capacity = "<< arr3.capacity() << " size = "<< arr3.size()<<endl;
    }

    // Lesson 06: We want to clear the 1D vector array
    arr3.clear();

    // Lesson 07: We want to initialize 1D array vector with size and specific data
    int size = 5;
    int data = 1;
    vector<int> arr4(size,data); // 1 1 1 1 1

    // Lesson 08: We want to initialize 1D array vector with data only
    vector<int>arr5={1,2,3,4,5};

    // Lesson 09: We want to copy 1D array vector in other 1D array vector
    vector<int>arr6(arr5); // {1,2,3,4,5}

    // Lesson 10: We want to pass 1D vector array in a function to print it
    printVector(arr6);


    return 0 ;
}