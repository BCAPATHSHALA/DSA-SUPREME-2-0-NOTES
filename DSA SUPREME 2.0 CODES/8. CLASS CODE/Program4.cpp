// Program 04: Sort 0's and 1's
#include<iostream>
using namespace std;

// Counting 0's and 1's solotion
void sortZeroOne1(int arr[],int size){
    int zeroCount = 0;
    int oneCount = 0;

    // Step 01: Counting 0's and 1's
    for(int i=0;i<size;i++){
        if(arr[i]==0){
            zeroCount++;
        }
        else{
            oneCount++;
        }
    }

    // Step 02: Fill 0's
    // for(int i=0;i<zeroCount;i++){
    //     arr[i]=0;
    // }
    // Step 03: Fill 1's
    // for(int i=zeroCount;i<size;i++){
    //     arr[i]=1;
    // }

    // Easy Way
    int i=0;
    while (zeroCount--)
    {
        arr[i]=0;
        i++;
    }
    while (oneCount--)
    {
        arr[i]=1;
        i++;
    }
    
}

// Print array
void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={0,1,1,0,0,1};
    int n=6;

    // calling method
    sortZeroOne1(arr,n);
    printArray(arr,n);

    return 0;
}

/*
Input: [0,1,1,0,0,1]
Output: 0 0 0 1 1 1 
*/