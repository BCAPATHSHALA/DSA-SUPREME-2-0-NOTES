// Program 05: Shift array's element by one (Right to left)
#include<iostream>
using namespace std;

// Shift array's element by one
void shiftArray(int arr[],int size){
    // Step 01 Store last element
    int temp = arr[size-1];
    
    // Step 02 Shift --> arr[i]=arr[i-1]
    for(int i=size-1;i>=1;i--){
        arr[i]=arr[i-1];
    }

    // Step 03 Copy temp at index zero
    arr[0]=temp;
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
Output: [60,10,20,30,40,50]
*/