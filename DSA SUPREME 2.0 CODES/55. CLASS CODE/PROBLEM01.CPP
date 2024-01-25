// 1. Longest Increasing Subsequence (Leetcode-300)

/*
Problem Statement:
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:
1. 1 <= nums.length <= 2500
2. -10^4 <= nums[i] <= 10^4
 
Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/

// ================== Approach 1: Normal Recursion Approach ================== //

class Solution {
public:
    int solveUsingRec(vector<int> &nums, int curr, int prev){
        // Base case
        if(curr >= nums.size()){
            return 0;
        }

        // Recursive call
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveUsingRec(nums, curr+1, curr);
        }
        int exclude = 0 + solveUsingRec(nums, curr+1, prev);
        int ans = max(include, exclude);
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int curr = 0;
        int ans = solveUsingRec(nums, curr, prev);
        return ans;
    }
};

// ================== Approach 2: Top Down Approach ================== //
//! Runtime Error Due to Invalid Array Index (Array Index Out of Bound)
//* How to resolve this error: using index shifting concept

class Solution {
public:
    int solveUsingMemo(vector<int> &nums, int curr, int prev,  vector<vector<int>> &dp){
        // Base case
        if(curr >= nums.size()){
            return 0;
        }

        // Step 3: if ans already exist then return ans
        if(dp[curr][prev] != -1){
            return dp[curr][prev];
        }

        // Step 2: store ans and return ans using DP array
        // Recursive call
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveUsingMemo(nums, curr+1, curr, dp);
        }
        int exclude = 0 + solveUsingMemo(nums, curr+1, prev, dp);
        dp[curr][prev] = max(include, exclude);
        return dp[curr][prev];
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int curr = 0;
        int n = nums.size();
        // Step 1: create DP array
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        int ans = solveUsingMemo(nums, curr, prev, dp);
        return ans;
    }
};

// ================== Approach 2: Top Down Approach ================== //
//* Error is Resolved using index shifting concept

class Solution {
public:
    int solveUsingMemo(vector<int> &nums, int curr, int prev,  vector<vector<int>> &dp){
        // Base case
        if(curr >= nums.size()){
            return 0;
        }

        // Step 3: if ans already exist then return ans
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }

        // Step 2: store ans and return ans using DP array
        // Recursive call
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveUsingMemo(nums, curr+1, curr, dp);
        }
        int exclude = 0 + solveUsingMemo(nums, curr+1, prev, dp);
        dp[curr][prev+1] = max(include, exclude);
        return dp[curr][prev+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int curr = 0;
        int n = nums.size();
        // Step 1: create DP array
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        int ans = solveUsingMemo(nums, curr, prev, dp);
        return ans;
    }
};


// ================== Approach 3: Bottom-up ================== //

class Solution {
public:
    int solveUsingTabu(vector<int> &nums, int curr, int prev){
        // Step 1: create DP array
        // Step 2: fill initial data in DP array according to recursion base case
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        // Step 3: fill the remaining DP array according to recursion formula/logic
        for(int currIndex = n-1; currIndex >= 0; currIndex--){
            for(int prevIndex = currIndex-1; prevIndex >= -1; prevIndex--){
                // Recursive call
                int include = 0;
                if(prevIndex == -1 || nums[currIndex] > nums[prevIndex]){
                    include = 1 + dp[currIndex+1][currIndex+1];
                }
                int exclude = 0 + dp[currIndex+1][prevIndex+1];
                dp[currIndex][prevIndex+1] = max(include, exclude);
            }
        }
        // Return ans
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int curr = 0;
        int ans = solveUsingTabu(nums, curr, prev);
        return ans;
    }
};


// ================== Approach 4: Space Optimization Approach ================== //
//! Without inter changing loop
class Solution {
public:
    int solveUsingTabuOS(vector<int> &nums){
        int n = nums.size();
        vector<int> currRow (n+1, 0);
        vector<int> nextRow (n+1, 0);

        // Loop row wise hi chalana hai mujhe
        for(int currIndex = n-1; currIndex >= 0; currIndex--){
            for(int prevIndex = currIndex-1; prevIndex >= -1; prevIndex--){
                // Recursive call
                int include = 0;
                if(prevIndex == -1 || nums[currIndex] > nums[prevIndex]){
                    include = 1 + nextRow[currIndex+1];
                }
                int exclude = 0 + nextRow[prevIndex+1];
                currRow[prevIndex+1] = max(include, exclude);
            }
            // Shift Karna Bhool Jata hu
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans = solveUsingTabuOS(nums);
        return ans;
    }
};

// ================== Approach 5: Solve Using Binary Search ================== //
class Solution {
public:
    int solveUsingBS(vector<int> &nums){
        vector<int> ans;
        // initial state
        ans.push_back(nums[0]);

        for(int i=1; i<nums.size(); i++){
            if(nums[i] > ans.back()){
                // push new element when it is greater then of last element of ans
                ans.push_back(nums[i]);
            }
            else{
                // last element of ans is just greater then of new element to replace krdo
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                // replace last element of ans
                ans[index] = nums[i];
            }
        }
        // return length of ans
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans = solveUsingBS(nums);
        return ans;
    }
};