// 1. House Robber (Leetcode-198)

// ================== Inclusive and Exclusive Pattern ========================= //

// ================== Approach 1: Normal Recursion Approach ================== //

class Solution {
public:
    int solveUsingRecursion(vector<int>&nums, int index){
        // Base case
        if(index >= nums.size()){
            return 0;
        }

        // Recursive Relation
        int include = nums[index] + solveUsingRecursion(nums, index+2);
        int exclude = 0 + solveUsingRecursion(nums, index+1);
        
        // Getting max ammont from both
        int maxAmmount = max(include, exclude);
        return maxAmmount;
    }
    int rob(vector<int>& nums) {
        int index = 0;
        return solveUsingRecursion(nums, index);
    }
};

// ================== Approach 2: Top Down Approach ================== //
class Solution {
public:
    int solveUsingMemo(vector<int>&nums, int index, vector<int> &dp){
        // Base case
        if(index >= nums.size()){
            return 0;
        }

        // Step 3: if ans max amount already exist then return ans
        if(dp[index] != -1){
            return dp[index];
        }

        // Step 2: store ans max amount and return ans using DP array
        // TOP DOWN: Traverse from 0 to N
        int include = nums[index] + solveUsingMemo(nums, index+2, dp);
        int exclude = 0 + solveUsingMemo(nums, index+1, dp);        
        dp[index] = max(include, exclude);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        // Step 1: create DP array
        int n = nums.size();
        vector<int> dp(n, -1);
        int index = 0;
        return solveUsingMemo(nums, index, dp);
    }
};

// ================== Approach 3: Bottom-up ================== //
class Solution {
public:
    int solveUsingTabu(vector<int>&nums, int index){
        // Step 1: create DP array
        int n = nums.size();
        vector<int> dp(n, -1);

        // Step 2: fill initial data in DP array according to recursion base case
        dp[n-1] = nums[n-1];

        // Step 3: fill the remaining DP array according to recursion formula/logic
        // BOTTOM UP: Traverse from N to 0
        for(int index = n - 2; index >= 0; index--){
            int tempAns = 0;
            if(index + 2 < n){
                // Corner Case
                tempAns = dp[index+2];
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + dp[index+1];        
            dp[index] = max(include, exclude);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        int index = 0;
        return solveUsingTabu(nums, index);
    }
};

// ================== Approach 4: Space Optimization Approach ================== //
class Solution {
public:
    int solveUsingSO(vector<int>&nums, int index){
        // Step 1: create DP array
        int n = nums.size();
        int next = 0;
        int prev = nums[n-1];
        int curr = 0;

        for(int index = n - 2; index >= 0; index--){
            int tempAns = 0;
            if(index + 2 < n){
                // Corner Case
                tempAns = next;
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + prev;        
            curr = max(include, exclude);

            // Update krna bhool jata hu
            next = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int index = 0;
        return solveUsingSO(nums, index);
    }
};