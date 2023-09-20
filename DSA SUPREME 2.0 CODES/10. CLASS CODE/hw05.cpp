// HW 05: Find First Repeating Element (GFG)
#include <iostream>
#include <unordered_map>
using namespace std;

// BRUTE FORCE APPROACH
int bruteForceSol(int *arr, int n) {
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                return i+1;
            }
        }
    }
    return -1;
}
// TIME COMPLEXITY: O(N^2)
// SPACE COMPLEXITY: O(1)


// OPTIMAL SOLUTION WITH HASHING APPROACH
int optimalSol(int arr[],int n){
    // Declared unordered_map
    unordered_map<int,int> hash;
    // Step 01: Traverse array and store it's element as hashing
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    // Step 02: Traverse array to check each element if it has occurrence in future
    for(int i=0;i<n;i++){
        if(hash[arr[i]] > 1){
            return i+1;
        }
    }
    return -1;
}
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(N)

int main() {
    int arr[]={1,5,3,4,3,5,6};
    int n=7;
    
    int index=optimalSol(arr,n);
    cout<<"Value: "<<arr[index-1]<<" at index: "<<index<<endl;
    
    return 0;
}

/*
EXAMPLE 01:
INPUT: arr{1,5,3,4,3,5,6} and N=7
OUTPUT: Value: 5 at index: 2

*/