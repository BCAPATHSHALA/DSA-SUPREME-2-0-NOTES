// Program 01: Find unique element
#include<iostream>
using namespace std;

// Find unique element
int getUnique(int arr[],int size){
    int ans = 0;
    for(int i=0;i<size;i++){
        ans ^=arr[i];
    }
    return ans;
}

int main(){
    int arr[]={2,10,11,13,10,2,16,13,16};
    int n=9;

    // calling method
    int finalAns = getUnique(arr,n);
    cout<<"Unique element: "<<finalAns;

    return 0;
}

/*
Input: [2,10,11,13,10,2,16,13,16]
Output: Unique element: 11
*/