// 1. Longest Common Subsequence (Leetcode-1143)
/*
Problem Statement:
Given two strings text1 and text2, return the length of their longest common subsequence. 
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some 
characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

Constraints:
1. 1 <= text1.length, text2.length <= 1000
2. text1 and text2 consist of only lowercase English characters.
*/



// ================== Approach 1: Normal Recursion Approach ================== //

class Solution {
public:
    int solveUsingRec(string a, string b, int i, int j) {
        // Base case
        if( i >= a.length()) {
            return 0;
        }
        if(j >= b.length()) {
            return 0;
        }

        // Recursive call
        int ans = 0;
        if(a[i] == b[j]) {
            // Does match the subsequence character
            ans = 1 + solveUsingRec(a,b, i+1, j+1);
        }
        else {
            // Does not match the subsequence character
            // Yanha mere pass two option hai (Neglect ch from str1 or str2)
            ans = 0 + max(solveUsingRec(a,b, i, j+1),
                        solveUsingRec(a,b, i+1, j));
        }
        return ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        int ans = solveUsingRec(text1, text2, i, j);
        return ans;
    }
};

// ================== Approach 2: Top Down Approach ================== //

class Solution {
public:
        int solveUsingMemo(string &a, string &b, int i, int j, vector<vector<int>> &dp) {
        // Base case
        if( i >= a.length()) {
            return 0;
        }
        if(j >= b.length()) {
            return 0;
        }

        // Step 3: if ans already exist then return ans
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // Step 2: store ans and return ans using DP array
        // Recursive call
        if(a[i] == b[j]) {
            // Does match the subsequence character
            dp[i][j] = 1 + solveUsingMemo(a,b, i+1, j+1,dp);
        }
        else {
            // Does not match the subsequence character
            dp[i][j] = 0 + max(solveUsingMemo(a,b, i, j+1, dp),
                        solveUsingMemo(a,b, i+1, j, dp));
        }
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        // Step 1: create DP array
        vector<vector<int>> dp (text1.length()+1,vector<int> (text2.length()+1, -1));
        int ans = solveUsingMemo(text1, text2, i, j, dp);
        return ans;
    }
};

// ================== Approach 3: Bottom-up ================== //

class Solution {
public:
        int solveUsingTabu(string &a, string &b, int i, int j) {
        // Step 1: create DP array
        // Step 2: fill initial data in DP array according to recursion base case
        vector<vector<int>> dp (a.length()+1,vector<int> (b.length()+1, 0));

        // Step 3: fill the remaining DP array according to recursion formula/logic
        for(int i = a.length()-1; i >= 0; i--){
            for(int j = b.length()-1; j >= 0; j--){
                // Recursive call
                if(a[i] == b[j]) {
                    // Does match the subsequence character
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else {
                    // Does not match the subsequence character
                    dp[i][j] = 0 + max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        // Return ans
        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        int ans = solveUsingTabu(text1, text2, i, j);
        return ans;
    }
};


// ================== Approach 4: Space Optimization Approach ================== //

class Solution {
public:
        int solveUsingTabuOS(string &a, string &b, int i, int j) {
        vector<int> curr (a.length()+1, 0);
        vector<int> next (a.length()+1, 0);

        for(int j = b.length()-1; j >= 0; j--){
            for(int i = a.length()-1; i >= 0; i--){
                // Recursive call
                int ans = 0;
                if(a[i] == b[j]) {
                    // Does match the subsequence character
                    ans = 1 + next[i+1];
                }
                else {
                    // Does not match the subsequence character
                    ans = 0 + max(next[i], curr[i+1]);
                }
                curr[i] = ans;
            }
            // Shift Karna Bhool Jata hu
            next = curr;
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        int ans = solveUsingTabuOS(text1, text2, i, j);
        return ans;
    }
};


// ================== Approach 4: Space Optimization Approach (Without Changing Loop) ================== //

class Solution {
public:
        int solveUsingTabuOSNoChangingLoop(string &a, string &b, int i, int j) {
        vector<int> curr (b.length()+1, 0);
        vector<int> next (b.length()+1, 0);

        for(int i = a.length()-1; i >= 0; i--){
            for(int j = b.length()-1; j >= 0; j--){
                // Recursive call
                int ans = 0;
                if(a[i] == b[j]) {
                    // Does match the subsequence character
                    ans = 1 + next[j+1];
                }
                else {
                    // Does not match the subsequence character
                    ans = 0 + max(curr[j+1], next[j]);
                }
                curr[j] = ans;
            }
            // shifting
            next = curr;
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        int ans = solveUsingTabuOSNoChangingLoop(text1, text2, i, j);
        return ans;
    }
};