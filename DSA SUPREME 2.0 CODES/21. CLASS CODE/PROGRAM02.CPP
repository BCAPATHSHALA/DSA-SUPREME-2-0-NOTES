// ✅Program 02: Binary search recursive solution
#include<iostream>
using namespace std;

int binaryS(int arr[], int target, int start, int end){
    // Base Case
    if(start > end){
        return -1;
    }

    // Processing -> Ek case me khud solve kar loonga
    int mid = start + (end - start)/2;
    if(arr[mid] == target){
        return mid;
    }

    // Baki ka recursion dekh lega
    else if(arr[mid] < target){
        // Right jaoo
        return binaryS(arr, target, mid + 1, end);
    }
    else{
        // Left jaoo
        return binaryS(arr, target, start, mid - 1);
    }
}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int size = 6;
    int start = 0;
    int end = size - 1;
    int target = 40;

    int ans = binaryS(arr, target, start, end);

    if(ans > 0){
        cout<<"Target found at index "<< ans <<endl;
    }
    else{
        cout<<"Target not found"<<endl;
    }
    return 0;
}