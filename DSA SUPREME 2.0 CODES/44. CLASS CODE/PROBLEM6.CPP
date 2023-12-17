// 7. Heap sort

/*
Heap Sort:
Time Complexity: O(N log N), Where N is number of elements in array
Space Complexity: ?
*/

#include <iostream>
using namespace std;

// Heapify using recursion
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

// Create heap using array
void buildHeap(int *arr, int n){
    for(int index = n/2; index > 0 ; index--){
        heapify(arr, n, index);
    }
}

// Heap Sort
void heapSort(int *arr, int n){
    while (n != 1)
    {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }    
}


int main() {
  int arr[] = {-1,5,10,15,20,25,12};
  int n = 6;
  buildHeap(arr,n);
  
  cout << "Unsorted Array: " << endl;
  for(int i=1; i<=n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  heapSort(arr, n);
  cout << "Sorted Array: " << endl;
  for(int i=1; i<=n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}

/*
Example 1:
Input: 
arr[5 10 15 20 25 12]

Output:
5 10 12 15 20 25
*/