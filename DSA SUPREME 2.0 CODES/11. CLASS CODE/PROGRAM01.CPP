// Program 01: Binary search
#include<iostream>
#include<vector>
using namespace std;

// Binary Search
bool binarySearch(vector<int> arr,int target){
    int n=arr.size();
    int start=0;
    int end=n-1;
    
    // Best practice of finding mid index
    int mid=start+((end-start)/2);
    
    bool ans=false;

    // Rule 04: Terminating condition to outside of loop
    while(start<=end){
        // Rule 01: When target found the return true
        if(arr[mid]==target){
            ans = true;
            return ans;
        }
        // Rule 02: When target is greater than mid of array value then skip the left part
        else if(arr[mid]<target){
            start=mid+1;
        }
        // Rule 03: When target is less than mid of array value the skip the right part
        else if(arr[mid]>target){
            end=mid-1;
        }
        // Update the mid index (HIGH CHANCE:----->Yaha par me galti kar skta hun)
        mid=start+((end-start)/2);
    }
    // When target not found then return false
    return ans;
}

int main(){
    vector<int> arr{10,20,30,40,50,60,70,80};
    int target=70;

    if(binarySearch(arr,target)){
        cout<<"Target found"<<endl;
    }
    else{
        cout<<"Target not found"<<endl;
    }
}

/*
EXAMPLE 01:
INPUT: arr[10,20,30,40,50,60,70,80], target=70
OUTPUT: Target found

EXAMPLE 02:
INPUT: arr[10,20,30,40,50,60,70,80], target=20
OUTPUT: Target found

EXAMPLE 03:
INPUT: arr[10,20,30,40,50,60,70,80], target=10
OUTPUT: Target found

EXAMPLE 04:
INPUT: arr[10,20,30,40,50,60,70,80], target=100
OUTPUT: Target not found
*/