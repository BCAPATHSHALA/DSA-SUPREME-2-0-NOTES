// 5. Heapify using recursion

/*
Heapification Operation:
Time Complexity: O(log N), Where N is number of elements in array
Space Complexity: O(log N) , Where log N is max height of binary tree
*/

#include <iostream>
using namespace std;

void heapify(int *arr, int size, int index){
    int leftIndex = 2*index;
    int rightIndex = 2*index+1;
    int largestIndex = index;

    // Now find -> larget index from three indeces
    if(leftIndex <= size && arr[largestIndex] < arr[leftIndex]){
        largestIndex = leftIndex;
    }
    if (rightIndex <= size && arr[largestIndex] < arr[rightIndex]){
        largestIndex = rightIndex;
    }
    if(index != largestIndex){
        // 1 case hum solve kar lenge
        swap(arr[largestIndex], arr[index]);

        // Ab recursion solve kar lega
        index = largestIndex;
        heapify(arr, size, index);
    }          
}

int main() {
  int arr[] = {-1,12,50,60,13};
  int n = 4;
  heapify(arr,4,1);
  
  cout << "printing heap: " << endl;
  for(int i=1; i<=n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}

/*
Example 1:
Input: 
arr[12 50 60 13]

Output:
Printing Heap
60 50 12 13

Example 2:
Input: 
arr[5 10 15 20 25 12]

Output:
Printing Heap
15 10 12 20 25 5 


*/