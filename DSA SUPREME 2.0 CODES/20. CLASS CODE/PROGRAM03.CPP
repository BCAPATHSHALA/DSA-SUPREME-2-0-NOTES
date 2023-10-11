// ✅Program 03: Search in array
#include<iostream>
using namespace std;

bool searchArray(int arr[], int index, int N, int target){
    // Base Case
    if(index >= N){
        return false;
    }
    if(arr[index] == target){
        return true;
    }    

    // Recursive Relation/Call
    bool aageKaAns = searchArray(arr,index + 1, N, target);
    return aageKaAns;
}

int main(){
    int arr[500] = {10,20,30,40,50};
    int size = 5;
    int index = 0;
    int target = 50;

    cout<<searchArray(arr,index,size,target)<<endl;
    return 0;
}