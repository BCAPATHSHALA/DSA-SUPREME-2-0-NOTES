// ✅Inversion count in Array using Merge Sort

Problem Statement:
If the array is already sorted, then the inversion count is 0, 
but if the array is sorted in reverse order, the inversion count is the maximum. 

Given an array arr[]. The task is to find the inversion count of arr[]. 
Where two elements arr[i] and arr[j] form an inversion if a[i] > a[j] and i < j.


Example 1:
Input: arr[] = {8, 4, 2, 1}
Output: 6
Explanation: Given array has six inversions: (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).

Example 2:
Input: arr[] = {1, 20, 6, 4, 5}
Output: 5
Explanation: Given array has five inversions: (20, 6), (20, 4), (20, 5), (6, 4), (6, 5). 

Example 3:
Input: arr[] = {1, 2, 3, 4}
Output: 0
Explanation: Given array has 0 inversions because array sorted in ascending order.