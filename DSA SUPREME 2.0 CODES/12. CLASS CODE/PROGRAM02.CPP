// PROGRAM 02: Search in a rotated and sorted array (Leetcode-33)
#include<iostream>
#include<vector>
using namespace std;

// Step 01: Pivot index function
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

// Step 03: Binary Search
int binarySearch(vector<int> nums,int s,int e,int target){
    int n=nums.size();
    int mid=s+(e-s)/2;

    while(s<=e){
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}


int search(vector<int> nums,int target){
    // Step 01
    int pivotIndex = findPivotIndex(nums);
    int n=nums.size();
    int ans=-1;

    // Step 02: Line A
    if(nums[0]<=target && target<=nums[pivotIndex]){
        // Step 03: Apply binary search
        ans=binarySearch(nums,0,pivotIndex,target);
    }
    // Step 02: Line B
    else{
        ans=binarySearch(nums,pivotIndex+1,n-1,target);
    }

    // return target index
    return ans;
}


int main(){
    vector<int> nums{12,14,16,2,4,6,8,10};
    int target=8;

    int finalAns = search(nums,target);
    cout<<"Target element at index: "<<finalAns<<endl;

    return 0;
}

/*
Example 01:
INPUT: [12,14,16,2,4,6,8,10] target=14
OUTPUT: Target element at index: 1

Example 02:
INPUT: [12,14,16,2,4,6,8,10] target=8
OUTPUT: Target element at index: 6
*/