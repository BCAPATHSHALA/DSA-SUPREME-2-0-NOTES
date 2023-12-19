// 3. Kth Smallest Element in an Array using Max Heap (GFG)

/*
Time Complexity: O(N), Where N is number of elements in array
Space Complexity: O(K), Where K is number of nodes in heap
*/

#include<iostream>
#include<queue>
using namespace std;

int getKthSmallestElement(int arr[], int n, int k){
    // Step 1: First K size ka Max Heap Create krlo
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        int element = arr[i];
        pq.push(element);
    }

    // Step 2: Root element ko remaining element se replace krte raho
    // jav tak Root > Remaining Element se
    for (int i = k; i < n; i++)
    {
        int element = arr[i];
        if(pq.top() > element)
        {
            pq.pop();
            pq.push(element);
        }        
    }

    return pq.top();    
}

int main(){
    int arr[] = {3,7,4,5,8,6,9};
    int n = 7;
    int k = 4;
    int ans = getKthSmallestElement(arr, n, k);
    cout<< k << "th Smallest Element: "<< ans << endl;
    return 0;
}

/*
Example 1:
INPUT:
arr[] = {3,7,4,5,8,6,9} and k=4

OUTPUT:
4th Smallest Element: 6

Example 2:
INPUT:
arr[] = {3,7,4,5,8,6,9} and k=3

OUTPUT:
3th Smallest Element: 5
*/