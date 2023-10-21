// Divide and conquer (MERGE SORT)
#include<iostream>
using  namespace std;
// Merge Two Sorted Array Function (Merge two sorted array)
void mergeTwoSortedArray(int arr[], int start, int *left, int *right, int lenLeft, int lenRight){
    // left and right part array are already sorted
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = start; // Yeh Catch hai Yanha galti hone ke chance hai

    while(leftIndex < lenLeft && rightIndex < lenRight){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else{
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    // Case 01: Left array exhaust but right array me abhi bhi element bache huee hai
    while(rightIndex < lenRight){
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }
    // Case 02: Right array exhaust but left array me abhi bhi element bache huee hai
    while(leftIndex < lenLeft){
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }
}

// Merge Function
void merge(int arr[], int start, int end, int mid){
    // Step 01: find the length of left and right part array
    int lenLeft = mid - start + 1;
    int lenRight = end - (mid + 1) + 1;

    // Step 02: create left and right part array
    int *left = new int[lenLeft];
    int *right = new int[lenRight];

    // Step 03: copy value from original array to left and right part array
    int k = start;
    // copy value from original array to left array
    for(int i=0; i<lenLeft; i++){
        left[i] = arr[k];
        k++;
    }
    // copy value from original array to right array
    for(int i=0; i<lenRight; i++){
        right[i] = arr[k];
        k++;
    }

    // Step 04: write actual logic to merge left and right sorted array
    mergeTwoSortedArray(arr, start, left, right, lenLeft, lenRight);

    // 😃De-allocate (Free heap memory from arrays are left and right)
    delete[] left;
    delete[] right;
}

// Merge Sort (Divide and conquer algorith)
void mergeSort(int arr[], int start, int end){
    // Base Case
    if(start > end){
        // Invalid Array
        return;
    }
    if(start == end){
        // Single element array
        return;
    }

    // Step 01: Find mid and break the original array into two equal part
    int mid = start + (end - start)/2;

    // Step 02: Recursion call for sorting left and right part
    // Recursive call for left part
    mergeSort(arr, start, mid);
    // Recursive call for right part
    mergeSort(arr, mid+1, end);

    // Step 03: Merge two sorted arrays
    merge(arr,start,end,mid);
}

int main() {

	int arr[] = {2,1,6,9,4,5};
	int size = 6;
	int s = 0;
	int e = size - 1;

	cout << "Before merge sort: " << endl;
	for(int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	mergeSort(arr,s,e);

	cout << "After merge sort: " << endl;
	for(int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}

/*
Space complexity of merge sort = O(N)
Time complexity of merge sort = O(N logN)
Example: 
Input: arr [7, 2, 1, 8, 6, 3, 5, 4]
Output: 1 2 3 4 5 6 7 8
*/