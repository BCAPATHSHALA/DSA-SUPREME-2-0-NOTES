// Program 04: Find total occurrence of a number in sorted array
#include<iostream>
#include<vector>
using namespace std;

// Last occurrence
int findLastOccurence(vector<int> arr,int target){
    int n=arr.size();
    int start=0;
    int end=n-1;
    int ans=-1;

    while(start<=end){

        int mid=start+((end-start)/2);

        // Rule 01: When target is equal to mid of array then store possible index in ans and skip the left part
        if(arr[mid]==target){
            ans=mid;
            start=mid+1;
        }
        // Rule 02: When target is greater than mid of array value then skip the left part
        else if(arr[mid]<target){
            start=mid+1;
        }
        // Rule 03: When target is less than mid of array value the skip the right part
        else if(arr[mid]>target){
            end=mid-1;
        }
    }
    // When first occurence of a number is found then return ans=index otherwise ans=-1
    return ans;
}

// First occurrence
int findFirstOccurence(vector<int> arr,int target){
    int n=arr.size();
    int start=0;
    int end=n-1;
    int ans=-1;

    while(start<=end){

        int mid=start+((end-start)/2);

        // Rule 01: When target is equal to mid of array then store possible index in ans and skip the right part
        if(arr[mid]==target){
            ans=mid;
            end=mid-1;
        }
        // Rule 02: When target is greater than mid of array value then skip the left part
        else if(arr[mid]<target){
            start=mid+1;
        }
        // Rule 03: When target is less than mid of array value the skip the right part
        else if(arr[mid]>target){
            end=mid-1;
        }
    }
    // When first occurence of a number is found then return ans=index otherwise ans=-1
    return ans;
}

// First occurrence
int findTotalOccurence(vector<int> arr,int target){
    int lastIndex=findLastOccurence(arr,target);
    int firstIndex=findFirstOccurence(arr,target);
    int totalOccurrence=lastIndex-firstIndex+1;
    return totalOccurrence;
}

int main(){
    vector<int> arr{10,20,30,30,30,30,40,50};
    int target=30;

    int finalAns = findTotalOccurence(arr,target);
    cout<<"Total occurence of target is "<<finalAns;
  
}

/*
EXAMPLE 01:
INPUT: arr[10,20,30,30,30,30,40,50], target=30
OUTPUT: Total occurence of target is 4
*/