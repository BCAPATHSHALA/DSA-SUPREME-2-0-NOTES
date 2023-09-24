// ✅SORTINGS 03: INSERTION SORT

#include<iostream>
#include<vector>
using namespace std;

// INSERTION SORT Function
void insertionSort(vector<int> &arr){
    int N=arr.size();
    for(int i=1; i<N; i++){
        // Key value =  key value se pahle ki all values ko hum compare karte hai key value se hi 
        //taki key value ko hum uske right position par rakh paye
        int key = arr[i]; 
        int j = i-1;

        // Move element of arr[0,i-1] that are greater than key to one position ahead of there current position 
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        // Insert key at right index/position (Insertion)
        arr[j+1]=key;
    }
}

int main(){
    vector<int> arr{5,4,3,1,2};

    insertionSort(arr);
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

