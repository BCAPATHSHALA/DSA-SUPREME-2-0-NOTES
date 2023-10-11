// ✅Program 08: Print index of all occurrence of target
#include<iostream>
using namespace std;

void searchArray(int arr[], int index, int N, int target){
    // Base Case
    if(index >= N){
        return;
    }
    if(arr[index] == target){
        cout<<index<<" ";
    }    

    // Recursive Relation/Call
    searchArray(arr,index + 1, N, target);
}

int main(){
    int arr[500] = {10,20,10,10,30,40};
    int size = 5;
    int index = 0;
    int target = 10;

    searchArray(arr,index,size,target);
    return 0;
}