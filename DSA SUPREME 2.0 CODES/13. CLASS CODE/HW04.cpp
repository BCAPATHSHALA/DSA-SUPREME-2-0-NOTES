// HW 04: Unbounded Binary Search (Concept)

/*
Unbounded Binary Search involves two steps:  
Step 01: Find range where element is present using exponential search
Step 02: Do Binary Search in above found range

Unbounded Binary Search applications:
Search in ∞ infinite array (Sorted Array)

Time complexity: O(Log n)
Space complexity: O(Log n)
*/

#include<iostream>
#include<vector>
using namespace std;

// Step 02: Do Binary Search in above found range
int binarySearch(vector<int>& arr, int start, int end, int target){
    int mid = start + (end - start)/2;
    while(start<=end){
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

// Step 01: Find range where element is present
int unboundedBinarySearch(vector<int>& arr,int x){
    int i = 0;
    int j = 1;

    if(arr[0]==x){
        return 0;
    }
    int j = 1;
    while( arr[j]<x){
        i = j;        
        j = j*2; // i = i<<1 or i*=2    
    }
    return binarySearch(arr, i, j, x);
}
