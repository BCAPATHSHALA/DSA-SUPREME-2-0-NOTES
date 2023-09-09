// Program 02: Print all pairs
#include<iostream>
using namespace std;

// Print all pairs
void PrintAllPairs(int arr[],int size){

    // outer loop
    for(int i=0;i<size;i++){
        // inner loop
        for(int j=0;j<size;j++){
            cout<<arr[i]<<", "<<arr[j]<<endl;
        }
    }
}

int main(){
    int arr[]={10,20,30};
    int n=3;

    // calling method
    PrintAllPairs(arr,n);

    return 0;
}

/*
Input: [10,20,30]
Output: 
10, 10
10, 20
10, 30
20, 10
20, 20
20, 30
30, 10
30, 20
30, 30
*/