// Program 03:Reverse an array (Two pointer approach)
#include<iostream>
#include<limits.h>
using namespace std;

// Reverse an array (Two pointer approach)
void reverseArray(int arr[],int size){
    int start=0;
    int end=size-1;

    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

// Printing array
void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[100];
    int size;

    // Entering size of array
    cout<<"Enter size: ";
    cin>>size;

    // Taking input in array
    cout<<"Enter element: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    // Calling method
    reverseArray(arr,size);
    printArray(arr,size);
    return 0;
}

/*
OUTPUT:
Enter size: 5
Enter element: 20 4 15 2 6
6 2 15 4 20 
*/