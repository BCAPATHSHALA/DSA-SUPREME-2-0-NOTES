// 4. First negative integer in every window of 'k' ⭐

// APPROACH 1: USING QUEUE (Window Sliding Pattern)
// Time Complexity: O(N), where N is size of array
// Space Complexity: O(K), where K is the size of the window

#include<iostream>
#include<deque>
using namespace std;

void printFirstNegative(int *arr, int size, int k){
    deque<int> dq;
    // Step 1: Process the first k elements in first window
    for(int i = 0; i < k; i++){
        int element = arr[i];
        if(element < 0){
            dq.push_back(i);
        }
    }

    // Step 2: Process the first k elements in next remaining windows
    for(int index = k; index < size; index++){
        // Annge badne se pahle --> Print first negative element of old windows
        if(dq.empty()){
            cout<<" 0"<<" ";
        }
        else{
            cout<< arr[dq.front()] << " ";
        }
        // Remove Old Index From Queue When (index - dq.front() >= k)
        if(index - dq.front() >= k){
            dq.pop_front();
        }
        // Insert New Index From Queue When (arr[index] < 0)
        if(arr[index] < 0){
            dq.push_back(index);
        }
    }

    // Print first negative element of last window
    if(dq.empty()){
        cout<<" 0"<<" ";
    }
    else{
        cout<< arr[dq.front()] << " ";
    }    
}

int main(){
    int arr[] = {2, -5, 4, -1, -2, 0, 5};
    int size = 7;
    int k = 3;
    printFirstNegative(arr, size, k);
    return 0;  
}

/*
Input: arr[2, -5, 4, -1, -2, 0, 5] and k=3
Output: -5 -5 -1 -1 -2
*/