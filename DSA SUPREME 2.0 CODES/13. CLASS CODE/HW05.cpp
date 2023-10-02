// HW 05: Book Allocation Problem(GFG and Code studio)
#include <bits/stdc++.h> 
bool isPossibbleSolution(vector<int> arr, int n, int m, int mid){
    int cases = 1;
    int pageSum = 0;

    int i = 0;
    while(i<n){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            cases++;
            if(cases>m || arr[i]>mid){
                return false;
            }
            // reset pageSum
            pageSum = arr[i];
        }
        i++;
    }
    return true;
}

int BinarySearch(vector<int> arr, int n, int m, int end ){
    int start = 0;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start<=end){
        // Step 03: create predicate function isPossibbleSolution()
        if(isPossibbleSolution(arr, n, m, mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int allocateBooks(vector<int> arr, int n, int m) {
    //Corner Case: 01
    if(m>n){
        return -1;
    }
    // Step 01: find total sum of array to create search space's end point (Maximum number of pages)
    int sum = 0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    // Step 02: apply binary search on search space BinarySearch()
    int ans = BinarySearch(arr, n, m, sum);
    return ans;
}

/*
Problem Statement:
You are given an array ‘pages’ of integer numbers. 
In this array, the ‘pages[i]’ represents the number of pages in the ‘i-th’ book. 
There are ‘m’ number of students, and the task is to allocate all the books to the students. 

Allocate books in a way such that:
- Each student gets at least one book.
- Each book should be allocated to a student.
- Book allocation should be in a contiguous manner.
 
You have to allocate the books to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
---------------------------------------------------------------------------------------------------------------------------
Example 01:
Input: pages[] = { 10,20,30,40}, n = 4 and m = 2
Output: 60

Number of books(n) = 4 
Number of students(m) = 2
Number of pages in a book(ith) = pages[ith]
The minimum of the maximum number of pages assigned = min{90,70,60} = 60
---------------------------------------------------------------------------------------------------------------------------
OPTIMAL APPROACH: Define search space and predicate function 
Step 01: find total sum of array to create search space's end point (Maximum number of pages)
Step 02: apply binary search on search space BinarySearch()
Step 03: create predicate function isPossibbleSolution()

Corner case 01: If number of students(m) are greater then number of books(n) then return -1
Corner case 02: If number number of case greater then number of students(n) then return false
------------------------------------------------------------------------------------------------------------------------------------------------
Time Complexity: O(N*log(Sum)), Here ‘N’ is the number of integers in the array ‘pages,’ and ‘Sum’ is the sum of all the elements of ‘pages.’
Space Complexity: O(1), no extra space used
.................................................................................................................................................
Resource: https://www.codingninjas.com/studio/library/book-allocation-problem
*/