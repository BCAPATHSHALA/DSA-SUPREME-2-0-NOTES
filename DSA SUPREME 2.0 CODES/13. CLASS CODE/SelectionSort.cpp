// ✅SORTINGS 02: SELECTION SORT
#include<iostream>
#include<vector>
using namespace std;

// SELECTION SORT Function
void selectionSort(vector<int> &arr){
    int N=arr.size();


    for(int i=0;i<N-1;i++){

        // Lets assume ki 1st index par jo value hai wo hi smallest hai
        int minIndex=i;  

        // ▶Step 01: find smallest element's index from [0,N-1]
        for(int j=i+1;j<N;j++){

            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        // ▶Step 02: swap the ith and minIndex position's value
        swap(arr[i],arr[minIndex]);
    }

}

int main(){
    vector<int> arr{5,4,3,1,2};

    selectionSort(arr);
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

