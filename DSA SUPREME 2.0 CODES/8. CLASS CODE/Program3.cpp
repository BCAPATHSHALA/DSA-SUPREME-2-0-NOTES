// Program 03: Print all triplets
#include<iostream>
using namespace std;

// Print all triplets
void printAllTriplets(int arr[],int size){

    // outer loop
    for(int i=0;i<size;i++){
        // inner loop of i
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                cout<<arr[i]<<", "<<arr[j]<<", "<<arr[k]<<endl;
            }
        }
    }
}

int main(){
    int arr[]={10,20,30};
    int n=3;

    // calling method
    printAllTriplets(arr,n);

    return 0;
}

/*
Input: [10,20,30]
Output: 
10, 10, 10
10, 10, 20
10, 10, 30
10, 20, 10
10, 20, 20
10, 20, 30
10, 30, 10
10, 30, 20
10, 30, 30
20, 10, 10
20, 10, 20
20, 10, 30
20, 20, 10
20, 20, 20
20, 20, 30
20, 30, 10
20, 30, 20
20, 30, 30
30, 10, 10
30, 10, 20
30, 10, 30
30, 20, 10
30, 20, 20
30, 20, 30
30, 30, 10
30, 30, 20
30, 30, 30
*/