/*
QUICK SORT ALGORITHM
New way to partitioning of array (Ek Step Chalna Mujhe Aata hai)
Step 01: Find pivot (It is always end element of array)
- To place pivot such that the element to the right of pivot > a[pivot]
- To place pivot such that the element to the left of pivot < a[pivot]
Step 02: Now apply recursion for left and right part of pivot (Baki ka recusion sambhal lega)
*/

//Function to sort an array using quick sort algorithm.
void quickSort(int arr[], int start, int end)
{
    // Base Case
    if(start>=end) {
        return;
    }
        
    int pivot = end;
    int i = start - 1;
    int j = start;
        
    while(j < pivot){
        if(arr[j] < arr[pivot]){
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[pivot]);
        
    // Recursive call karlo Left part ke liye
    quickSort(arr, start, i - 1);
    // Recursive call karlo Right part ke liye
    quickSort(arr, i + 1, end);
}


/*
Space complexity of quick sort = O(N)
Time complexity of quick sort = O(N^2)
Example: 
Input: arr [7, 2, 1, 8, 6, 3, 5, 4]
Output: 1 2 3 4 5 6 7 8
*/