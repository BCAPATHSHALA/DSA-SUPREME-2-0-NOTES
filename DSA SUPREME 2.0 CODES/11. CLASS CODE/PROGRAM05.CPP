// Program 05: Find missing element in sorted array (GFG)
#include<iostream>
#include<vector>
using namespace std;

// Find missing element
int findMissingElement(int arr[],int size){
    int start=0;
    int end=size-1;
    int mid=start+((end-start)/2);
    int ans=-1;

    while(start<=end){
        // Rule 01: Find the pattern
        int difference=arr[mid]-mid;

        // Rule 02: When difference is equal to 1 then skip the left part
        if(difference==1){
            start=mid+1;
        }
        // Rule 03: When difference is equal to 2 then store mid index in ans and skip the right part
        else if(difference==2){
            ans=mid;
            end=mid-1;
        }
        // Updated mid index
        mid=start+((end-start)/2);
    }
    return ans+1;
}

int main(){
   int arr[]={1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size=9;

    int finalAns = findMissingElement(arr,size);
    cout<<"Missing number is "<<finalAns;
  
}

/*
Example 01:
Input : arr[] = [1, 2, 3, 4, 6, 7, 8]
Output : 5

Example 02:
Input : arr[] = [1, 2, 3, 4, 5, 6, 8, 9]
Output : 7

Example 03:
Input : arr[] = [1, 2, 3, 4, 5, 6, 7, 8, 9]
Output : 0
*/