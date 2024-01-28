// 2. Minimum Cost Tree From Leaf Values (Leetcode-1130)

/*
Problem statement:
Given an array arr of positive integers, consider all binary trees such that:

1. Each node has either 0 or 2 children;
2. The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
3. The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.

Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

Note: A node is a leaf if and only if it has zero children.

Example 1:
Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.

Example 2:
Input: arr = [4,11]
Output: 44

Constraints:

1. 2 <= arr.length <= 40
2. 1 <= arr[i] <= 15
3. It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 2^31).
*/

// ================== Approach 1: Normal Recursion Approach ================== //

class Solution {
public:
    int solveUsingRec(vector<int>& arr, map<pair<int,int>, int> &maxi, int start, int end){
        // Base case
        if(start >= end){
            return 0;
        }

        // Recursive call
        int ans = INT_MAX;
        for(int i = start; i < end; i++){
            // i used for partitioning
            int sum = maxi[{start,i}] * maxi[{i+1,end}] 
                      + solveUsingRec(arr, maxi,start,i)
                      + solveUsingRec(arr, maxi,i+1,end);
            ans = min(ans, sum);
        }
        return ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        // Pre computation: 
        // to store the maxValue of all possible partitions of input array
        map<pair<int,int>, int> maxi;
        for(int i=0; i<arr.size(); i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1; j<arr.size(); j++){
                maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        int n = arr.size();
        int start = 0;
        int end = n-1;
        int ans = solveUsingRec(arr, maxi, start, end);
        return ans;
    }
};

// ================== Approach 2: Top Down Approach ================== //

class Solution {
public:
    int solveUsingMemo(vector<int>& arr, map<pair<int,int>, int> &maxi, int start, int end, vector<vector<int>> &dp){
        // Base case
        if(start >= end){
            return 0;
        }

        // Step 3: if ans already exist then return ans
        if(dp[start][end] != -1){
            return dp[start][end];
        }

        // Step 2: store ans and return ans using DP array
        // Recursive call
        int ans = INT_MAX;
        for(int i = start; i < end; i++){
            // i used for partitioning
            int sum = maxi[{start,i}] * maxi[{i+1,end}] 
                      + solveUsingMemo(arr, maxi,start,i,dp)
                      + solveUsingMemo(arr, maxi,i+1,end,dp);
            ans = min(ans, sum);
        }
        dp[start][end] = ans;
        return dp[start][end];
    }
    int mctFromLeafValues(vector<int>& arr) {
        // Pre computation: 
        // to store the maxValue of all possible partitions of input array
        map<pair<int,int>, int> maxi;
        for(int i=0; i<arr.size(); i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1; j<arr.size(); j++){
                maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        int n = arr.size();
        int start = 0;
        int end = n-1;
        // Step 1: create DP array
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        int ans = solveUsingMemo(arr, maxi, start, end, dp);
        return ans;
    }
};

// ================== Approach 3: Bottom-up ================== //

class Solution {
public:
    int solveUsingTabu(vector<int>& arr, map<pair<int,int>, int> &maxi){
        int n = arr.size();
        // Step 1: create DP array
        // Step 2: fill initial data in DP array according to recursion base case
        vector<vector<int>> dp(n+2, vector<int> (n+1, 0));

        // Step 3: fill the remaining DP array according to recursion formula/logic
        for(int start = n; start >= 0; start--){
            for(int end = 0; end <= n-1; end++){

                if(start >= end){
                    // Skip for invalid range
                    continue;
                }

                // Recursive call
                int ans = INT_MAX;
                for(int i = start; i < end; i++){
                    // i used for partitioning
                    int sum = maxi[{start,i}] * maxi[{i+1,end}] 
                            + dp[start][i]
                            + dp[i+1][end];
                    ans = min(ans, sum);
                }
                dp[start][end] = ans;
            }
        }
        // return ans
        return dp[0][n-1];
    }
    int mctFromLeafValues(vector<int>& arr) {
        // Pre computation: 
        // to store the maxValue of all possible partitions of input array
        map<pair<int,int>, int> maxi;
        for(int i=0; i<arr.size(); i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1; j<arr.size(); j++){
                maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }
        int ans = solveUsingTabu(arr, maxi);
        return ans;
    }
};