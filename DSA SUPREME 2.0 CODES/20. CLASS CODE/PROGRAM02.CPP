// ✅Program 02: Print array
#include<iostream>
using namespace std;

void printArray(int arr[], int index, int N){
    // Base Case
    if(index >= N){
        return;
    }

    // Processing
    cout<<arr[index]<<" ";

    // Recursive Relation/Call
    printArray(arr,index + 1, N);
}

int main(){
    int arr[500] = {10,20,30,40,50};
    int size = 5;
    int index = 0;

    printArray(arr,index,size);
    return 0;
}