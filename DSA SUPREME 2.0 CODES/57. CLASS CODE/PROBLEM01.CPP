// 1. Partition Equal Subset Sum (Leetcode-416)

/*
Problem Statement:
Given an integer array nums, return true if you can partition the array into two subsets 
such that the sum of the elements in both subsets is equal or false otherwise.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

Constraints:
1. 1 <= nums.length <= 200
2. 1 <= nums[i] <= 100
*/

// ================== Approach 1: Normal Recursion Approach ================== //

class Solution {
public:
    bool solveUsingRec(vector<int> &nums, int index, int currSum, int target){
        // Base case
        if(index >= nums.size()){
            return false;
        }
        if(currSum > target){
            return false;
        }
        if(currSum == target){
            return true;
        }

        // Recursive call
        bool include = solveUsingRec(nums, index+1, currSum+nums[index], target);
        bool exclude = solveUsingRec(nums, index+1, currSum+0, target);
        bool ans = include || exclude;
        return ans;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i=0; i<nums.size(); i++){
            totalSum += nums[i];
        }
        
        if(totalSum & 1){
            // Odd can't be partioned
            return false;
        }

        int target = totalSum/2;
        int index = 0;
        int currSum = 0;
        bool ans = solveUsingRec(nums, index, currSum, target);
        return ans;
    }
};

// ================== Approach 2: Top Down Approach ================== //

class Solution {
public:
    bool solveUsingMemo(vector<int> &nums, int index, int currSum, int target, vector<vector<int>> &dp){
        // Base case
        if(index >= nums.size()){
            return false;
        }
        if(currSum > target){
            return false;
        }
        if(currSum == target){
            return true;
        }

        // Step 3: if ans already exist then return ans
        if(dp[index][currSum] != -1){
            return dp[index][currSum];
        }

        // Step 2: store ans and return ans using DP array
        // Recursive call
        bool include = solveUsingMemo(nums, index+1, currSum+nums[index], target, dp);
        bool exclude = solveUsingMemo(nums, index+1, currSum+0, target, dp);
        dp[index][currSum] = include || exclude;
        return dp[index][currSum];
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i=0; i<nums.size(); i++){
            totalSum += nums[i];
        }
        
        if(totalSum & 1){
            // Odd can't be partioned
            return false;
        }

        int target = totalSum/2;
        int index = 0;
        int currSum = 0;
        // Step 1: create DP array
        vector<vector<int>> dp(nums.size()+1, vector<int> (target+1, -1));
        bool ans = solveUsingMemo(nums, index, currSum, target, dp);
        return ans;
    }
};

// ================== Approach 3: Bottom-up ================== //

class Solution {
public:
    bool solveUsingTabu(vector<int> &nums, int target){
        // Step 1: create DP array
        // Step 2: fill initial data in DP array according to recursion base case
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (target+1, 0));        
        for(int row=0; row<=n; row++){
            dp[row][target] = 1;
        }

        // Step 3: fill the remaining DP array according to recursion formula/logic
        for(int index = n-1; index >= 0; index--){
            for(int currSum = target; currSum >= 0; currSum--){
                // Recursive call
                bool include = 0;
                if(currSum+nums[index] <= target){
                    include = dp[index+1][currSum+nums[index]];
                }
                bool exclude = dp[index+1][currSum+0];
                dp[index][currSum] = include || exclude;
            }
        }        
        return dp[0][0];
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i=0; i<nums.size(); i++){
            totalSum += nums[i];
        }
        
        if(totalSum & 1){
            // Odd can't be partioned
            return false;
        }

        int target = totalSum/2;
        bool ans = solveUsingTabu(nums, target);
        return ans;
    }
};

// ================== Approach 4: Space Optimization Approach ================== //
//! Without inter changing loop
class Solution {
public:
    bool solveUsingTabuOS(vector<int> &nums, int target){
        int n = nums.size();
        vector<int> curr(target+1,0);
        vector<int> next(target+1,0);
        
        curr[target] = 1;
        next[target] = 1;

        // Loop row wise hi chalana hai mujhe
        for(int index = n-1; index >= 0; index--){
            for(int currSum = target; currSum >= 0; currSum--){
                // Recursive call
                bool include = 0;
                if(currSum+nums[index] <= target){
                    include = next[currSum+nums[index]];
                }
                bool exclude = next[currSum+0];
                curr[currSum] = include || exclude;
            }
            // Shift Karna Bhool Jata hu
            next = curr;
        }        
        return next[0];
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i=0; i<nums.size(); i++){
            totalSum += nums[i];
        }
        
        if(totalSum & 1){
            // Odd can't be partioned
            return false;
        }

        int target = totalSum/2;
        bool ans = solveUsingTabuOS(nums, target);
        return ans;
    }
};