// PROGRAM 01: Find pivot element index from sorted and rotated array
#include<iostream>
#include<vector>
using namespace std;

// Pivot index function
int findPivotIndex(vector<int> nums){
    int n=nums.size();
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        // Corner Case for single element
        if(s==e){
            return s;
        }
        // Handle separately condition
        if(mid+1<n && nums[mid]>nums[mid+1]){
            return mid;
        }
        else if(mid-1>=0 && nums[mid]<nums[mid-1]){
            return mid-1;
        }
        // Apply binary search in line B
        else if(nums[s]>nums[mid]){
            e=mid-1;
        }
        // Apply binary search in line A
        else{
            s=mid+1;
        }
        // Updated mid index
        mid=s+(e-s)/2;
    }
}

int main(){
    vector<int> nums{12,14,16,2,4,6,8,10};

    int pivotIndex = findPivotIndex(nums);
    cout<<"Maximum element at index: "<<pivotIndex<<endl;
}

/*
Example 01:
INPUT: [12,14,16,2,4,6,8,10]
OUTPUT: Maximum element at index: 2

Example 02:
INPUT: [1,3]
OUTPUT: Maximum element at index: 1

Example 03:
INPUT: [3]
OUTPUT: Maximum element at index: 0
*/