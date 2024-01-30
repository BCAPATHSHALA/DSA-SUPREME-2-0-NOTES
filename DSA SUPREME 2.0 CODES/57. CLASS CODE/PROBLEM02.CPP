// 2. Number of Dice Rolls With Target Sum (Leetcode-1155)

/*
Problem Statement:
You have n dice, and each dice has k faces numbered from 1 to k.
Given three integers n, k, and target, return the number of possible ways (out of the k^n total ways) to roll the dice, 
so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.

Example 2:
Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

Example 3:
Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 10^9 + 7.
 

Constraints:
1. 1 <= n, k <= 30
2. 1 <= target <= 1000
*/

// ================== Approach 1: Normal Recursion Approach ================== //

class Solution {
public:
    long long int MOD = 1000000000+7;
    int solveUsingRec(int n, int k, int target, int usedDice, int currSum){
        //Base case
        if(currSum == target && usedDice == n){
            return 1;
        }
        if(currSum != target && usedDice == n){
            return 0;
        }
        if(currSum == target && usedDice != n){
            return 0;
        }
        
        // Recursive call
        int ans = 0;
        for(int face = 1; face <= k; face++){
            ans = ((ans)%MOD + solveUsingRec(n, k, target, usedDice+1, currSum+face)%MOD)%MOD;
        }
        return ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        int usedDice = 0;
        int currSum = 0;
        int ans = solveUsingRec(n, k, target, usedDice, currSum);
        return ans;
    }
};

// ================== Approach 2: Top Down Approach ================== //

class Solution {
public:
    long long int MOD = 1000000007;
    int solveUsingMemo(int n, int k, int target, int usedDice, int currSum, vector<vector<int>> &dp){
        //Base case
        if(currSum == target && usedDice == n){
            return 1;
        }
        if(currSum != target && usedDice == n){
            return 0;
        }
        if(currSum == target && usedDice != n){
            return 0;
        }

        // Step 3: if ans already exist then return ans
        if(dp[usedDice][currSum] != -1){
            return dp[usedDice][currSum];
        }
        
        // Step 2: store ans and return ans using DP array
        // Recursive call
        int ans = 0;
        for(int face = 1; face <= k; face++){
            int recAns = 0;
            if(currSum+face <= target){
                // Corner Case -> resolve runtime error occurs due to array index out of bound
                recAns = solveUsingMemo(n, k, target, usedDice+1, currSum+face, dp);
            }
            ans = ((ans)%MOD + (recAns)%MOD)%MOD;
        }
        dp[usedDice][currSum] = ans;
        return dp[usedDice][currSum];
    }
    int numRollsToTarget(int n, int k, int target) {
        int usedDice = 0;
        int currSum = 0;
        // Step 1: create DP array
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        int ans = solveUsingMemo(n, k, target, usedDice, currSum, dp);
        return ans;
    }
};

// ================== Approach 3: Bottom-up ================== //

class Solution {
public:
    long long int MOD = 1000000007;
    int solveUsingTabu(int n, int k, int target){
        // Step 1: create DP array
        // Step 2: Initially, filled dp array according to base case 2, 3
        vector<vector<int>> dp(n+1, vector<int> (target+1, 0));
        // Step 2: Initially, filled dp array according to base case 1
        dp[n][target] = 1;
        
        // Step 3: fill the remaining DP array according to recursion formula/logic
        for(int usedDice = n-1; usedDice >= 0; usedDice--){
            for(int currSum = target; currSum >= 0; currSum--){
                // Recursive call
                int ans = 0;
                for(int face = 1; face <= k; face++){
                    int recAns = 0;
                    if(currSum+face <= target){
                        // Corner Case -> resolve runtime error occurs due to array index out of bound
                        recAns = dp[usedDice+1][currSum+face];
                    }
                    ans = ((ans)%MOD + (recAns)%MOD)%MOD;
                }
                dp[usedDice][currSum] = ans;
            }
        }
        return dp[0][0];
    }

    int numRollsToTarget(int n, int k, int target) {
        int ans = solveUsingTabu(n, k, target);
        return ans;
    }
};


// ================== Approach 4: Space Optimization Approach ================== //
//! Without inter changing loop

class Solution {
public:
    long long int MOD = 1000000007;
    int solveUsingTabu(int n, int k, int target){
        // Initially, filled dp array according to base case 2, 3
        vector<int> curr(target+1, 0);
        vector<int> next(target+1, 0);
        // Initially, filled dp array according to base case 1
        next[target] = 1;
        

        for(int usedDice = n-1; usedDice >= 0; usedDice--){
            for(int currSum = target-1; currSum >= 0; currSum--){
                // Recursive call
                int ans = 0;
                for(int face = 1; face <= k; face++){
                    int recAns = 0;
                    if(currSum+face <= target){
                        // Corner Case -> resolve runtime error occurs due to array index out of bound
                        recAns = next[currSum+face];
                    }
                    ans = ((ans)%MOD + (recAns)%MOD)%MOD;
                }
                curr[currSum] = ans;
            }
            // Shift Karna Bhool Jata hu
            next = curr;
        }
        return next[0];
    }

    int numRollsToTarget(int n, int k, int target) {
        int ans = solveUsingTabu(n, k, target);
        return ans;
    }
};