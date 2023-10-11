// ✅Homework 02: Maximum in an array
#include<iostream>
#include<limits.h>
using namespace std;

void findMax(int arr[], int index, int N, int &maxi){
    // Base Case
    if(index >= N){
        return;
    }

    // Processing
    maxi = max(arr[index], mini);  

    // Recursive Relation/Call
    findMax(arr,index + 1, N, mini);
}

int main(){
    int arr[500] = {20,30,10,5,11};
    int size = 5;
    int index = 0;
    int maxi = INT_MIN;
    cout<<"Before Calling findMin then maxi: "<< maxi<<endl;
    findMax(arr,index,size,maxi);
    cout<<"After Calling findMin then maxi: "<< maxi<<endl;
    return 0;
}