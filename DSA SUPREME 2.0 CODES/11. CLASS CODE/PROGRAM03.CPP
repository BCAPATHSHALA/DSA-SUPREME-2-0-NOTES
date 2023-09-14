// Program 03: Find last occurrence of a number in sorted array
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

int main(){
    vector<int> arr{10,20,30,30,30,30,40,50};
    int target=60;

    int finalAns = findLastOccurence(arr,target);

    if(finalAns!=-1){
        cout<<"Last occurence of target is at index "<<finalAns<<endl;
    }
    else{
        cout<<finalAns<<endl;
    }
  
}

/*
EXAMPLE 01:
INPUT: arr[10,20,30,30,30,30,40,50], target=30
OUTPUT: Last occurence of target is at index 5

EXAMPLE 02:
INPUT: arr[10,20,30,30,30,30,40,50], target=10
OUTPUT: Last occurence of target is at index 0

EXAMPLE 03:
INPUT: arr[10,20,30,30,30,30,40,50], target=50
OUTPUT: Last occurence of target is at index 7

EXAMPLE 04:
INPUT: arr[10,20,30,30,30,30,40,50], target=60
OUTPUT: -1
*/