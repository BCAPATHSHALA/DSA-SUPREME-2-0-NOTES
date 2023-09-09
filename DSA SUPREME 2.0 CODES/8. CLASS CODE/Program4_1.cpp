// Program 04: Sort 0's and 1's
#include<iostream>
using namespace std;

// Counting 0's and 1's solotion
void sortZeroOne1(int arr[],int size){
    int s = 0;
    int e = size-1;

    while (s<e)
    {
        // When arr[s]==0 then increase only s++
       while(s<e && arr[s]==0){
        s++;
       }
        // When arr[e]==1 then decrease only e--
       while(s<e && arr[e]==1){
        e--;
       }
        // When arr[s]==1 and arr[e]==0 then increase and decrease respectively s++, e-- and swap
        if(s<e && arr[s]==1 && arr[e]==0){
            swap(arr[s],arr[e]);
            s++;
            e--;
        }
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