// ✅Program 04: Minimum in array
#include<iostream>
#include<limits.h>
using namespace std;

void findMin(int arr[], int index, int N, int &mini){
    // Base Case
    if(index >= N){
        return;
    }

    // Processing
    mini = min(arr[index], mini);  

    // Recursive Relation/Call
    findMin(arr,index + 1, N, mini);
}

int main(){
    int arr[500] = {20,30,10,5,11};
    int size = 5;
    int index = 0;
    int mini = INT_MAX;
    cout<<"Before Calling findMin then mini: "<< mini<<endl;
    findMin(arr,index,size,mini);
    cout<<"After Calling findMin then mini: "<< mini<<endl;
    return 0;
}