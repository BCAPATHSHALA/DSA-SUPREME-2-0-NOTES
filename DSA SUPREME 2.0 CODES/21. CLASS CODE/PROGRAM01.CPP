// ✅Program 01: Check array sorted or not
#include<iostream>
using namespace std;

bool checkSorted(int *arr, int size, int index){
    // Base Case
    if(index >= size){
        return true; 
    }

    // Processing
    if(arr[index] > arr[index - 1]){
        // Aage check karna padega to ab recursion dekh lega
        bool aageKaAns = checkSorted(arr, size, index + 1);
        return aageKaAns;
    }
    else{
        // Iska mtlb array sorted nhi hai
        return false;
    }
}

int main(){
    int arr[300] = {10,20,30,40,50,60};
    int size = 6;
    int index = 1;

    bool ans = checkSorted(arr, size, index);

    if(ans){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }

    return 0;
}