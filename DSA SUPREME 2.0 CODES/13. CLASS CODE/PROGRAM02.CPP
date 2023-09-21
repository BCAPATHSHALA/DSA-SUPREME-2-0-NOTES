// Program 02: Binary search on nearly sorted array
#include<iostream>
#include<vector>
using namespace std;

// Find target in nearly sorted array
int searchNearlySorted(vector<int> arr,int target){
    int n=arr.size();
    int s=0;
    int e=n-1;
    int mid = s+(e-s)/2;

    while(s<=e){
        // CATCH 03 -> ARR[-1] PAR CODE FAT JAYEGA
        if(mid-1>=0 && arr[mid-1]==target){
            return mid-1;
        }
        if(arr[mid]==target){
            return mid;
        }
        // CATCH 04 -> ARR[N] PAR CODE FAT JAYEGA
        if(mid+1<n && arr[mid+1]==target){
            return mid+1;
        }
        // CATCH 01 -> GOTO RIGHT SIDE TO GET TARGET'S INDEX
        if(arr[mid]<target){
            s=mid+2; 
        }
        // CATCH 02 -> GOTO LEFT SIDE TO GET TARGET'S INDEX
        else{
            e=mid-2;
        }  
        mid = s+(e-s)/2; 
    }
    return -1;
}

/*
Time Complexity: O(logN), where N is array's length
Space Complexity: O(1)
*/

int main(){
    vector<int> arr{20,10,30,50,40,70,60};
    int target = 100;

    int index = searchNearlySorted(arr,target);

    if(index == -1){
        cout<<"Target not found"<<endl;
    }else{
        cout<<"Target "<<target<<" found at index "<<index<<endl;
    }

    return 0;
}

/*
Example 01:
Input: arr[20,10,30,50,40,70,60] , N=7 , and target = 70
Output: Target 70 found at index 5

Example 02:
Input: arr[20,10,30,50,40,70,60] , N=7 , and target = 20
Output: Target 20 found at index 0

Example 03:
Input: arr[20,10,30,50,40,70,60] , N=7 , and target = 60
Output: Target 60 found at index 6

Example 04:
Input: arr[20,10,30,50,40,70,60] , N=7 , and target = 100
Output: Target not found
*/