// HW 04: Missing Element From An Array With Duplicates (GFG)

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

// Solution 01: Negative marking method
void findMissing(vector<int> arr){
    int n= arr.size();
    
    // Step 01: Apply Visited Method
    for(int i=0;i<n;i++){
        int index=abs(arr[i]);
        if(arr[index-1]>0){
            arr[index-1]*=-1;
        }
    }

    // Step 02: All positive index are missing
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            cout<<i+1<<" ";
        }
    }
}
// Time Complexity: O(N)
// Space Complexity: O(1)

// Solution 02: Sorting method
void findMissing(vector<int> arr){
    int n= arr.size();
    
    // Step 01: Sorting array
    sort(arr.begin(),arr.end());

    // Step 02: Printing missing element
    for(int i=0;i<n;i++){
        if(arr[i]!=i+1){
            cout<<i+1<<" ";
        }
    }
}

// Time Complexity: O(N log N)
// Space Complexity: O(1)

int main(){
    vector<int> arr{1,3,5,3,3};
    findMissing(arr);
    return 0;
}


/*
Problem: Given an array arr[] of size N having integers in the range [1, N] with some of the elements missing. The task is to find the missing elements.

Note: There can be duplicates in the array.

EXAMPLE 01:
Input: arr[] = {1, 3, 5, 3, 4}, N = 5
Output: 2

EXAMPLE 02:
Input: arr[] = {1, 3, 3, 3, 5}, N = 5
Output: 2 4

EXAMPLE 03:
Input: arr[] = {1, 2, 3, 4, 4, 7, 7}, N = 7
Output: 5 6
*/