// Program 07: Shift array's element by one (Left to right)
#include<iostream>
using namespace std;

// Shift array's element by one
void shiftArray(int arr[],int size){
    // Step 01 Store first element
    int temp = arr[0];
    
    // Step 02 Shift --> arr[i]=arr[i+1]
    for(int i=0;i<size-1;i++){
        arr[i]=arr[i+1];
    }

    // Step 03 Copy temp at index last
    arr[size-1]=temp;
}

// print array
void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={10,20,30,40,50,60};
    int n=6;

    // calling method
    shiftArray(arr,n);
    printArray(arr,n);

    return 0;
}

/*
Input: [10,20,30,40,50,60]
Output: [20 30 40 50 60 10 ]
*/