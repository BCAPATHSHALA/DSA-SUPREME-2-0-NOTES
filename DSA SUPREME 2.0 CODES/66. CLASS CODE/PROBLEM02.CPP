// 2. Fixed size window 
// Problem 02: Max Sum Subarray of size K (GFG)

/*
Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

NOTE: A subarray is a contiguous part of any given array.

Example 1:
Input: N = 4, K = 2, Arr = [100, 200, 300, 400]
Output: 700
Explanation: Arr3  + Arr4 =700, which is maximum.


Example 2:
Input: N = 4, K = 4, Arr = [100, 200, 300, 400]
Output: 1000
Explanation: Arr1 + Arr2 + Arr3 + Arr4 =1000, which is maximum.


Your Task:
You don't need to read input or print anything. Your task is to complete the function maximumSumSubarray() which takes the integer K, vector Arr with size N, containing the elements of the array and returns the maximum sum of a subarray of size K.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 10^5
1 <= Arr index <= 10^5
1 <= K <= N
*/

class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long long maxSum = INT_MIN;
        long long windowSum = 0;
        
        // Step 1: process the first window for "K time"
        for(long long index = 0; index < K; index++){
            windowSum += Arr[index];
        }
        
        // Initialize maxSum with the sum of the first window
        maxSum = windowSum;
        
        // Step 2: process remaning windows
        for(long long index = K; index < N; index++){
                windowSum += Arr[index] - Arr[index - K];
                maxSum = max(maxSum, windowSum);
        }
        
        return maxSum;
    }
};