// ✅SORTINGS 01: BUBBLE SORT
#include<iostream>
#include<vector>
using namespace std;

// BUBBLE SORT Function
void bubbleSort(vector<int> &arr){
    int N=arr.size();

    // Outer Loop
    for(int i=0;i<(N-1);i++){
        // Inner Loop
        for(int j=0;j<(N-i-1);j++){
            // When a>b where a=j and b=j+1 to swap kardo
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    vector<int> arr{5,4,3,1,2};

    bubbleSort(arr);
    for(auto value: arr){
        cout<<value<<" ";
    }
    return 0;
}

/*
INPUT: {5,4,3,1,2}
OUTPUT: {1,2,3,4,5}
TIME COMPLEXITY: O(N^2)
SPACE COMPLEXITY: O(1)
*/