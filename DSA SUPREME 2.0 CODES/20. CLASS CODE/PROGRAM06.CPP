// ✅Program 06: Double each element
#include<iostream>
using namespace std;

void doubleArray(int arr[], int index, int N){
    // Base Case
    if(index >= N){
        return;
    }

    // Processing
    arr[index] = arr[index] * 2; 

    // Recursive Relation/Call
    doubleArray(arr,index + 1, N);
}

int main(){
    int arr[500] = {10,20,30,40,50};
    int size = 5;
    int index = 0;

    doubleArray(arr,index,size);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}