// 3. Edit distance (Leetcode-72)

/*
Problem Statement:
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 
Constraints:
1. 0 <= word1.length, word2.length <= 500
2. word1 and word2 consist of lowercase English letters.
*/

// ================== Approach 1: Normal Recursion Approach ================== //

class Solution {
public:
    int solveUsingRec(string& word1, string& word2, int i, int j){
        // Base Case
        if(i >= word1.length()){
            return word2.length() - j;
        }
        if(j >= word2.length()){
            return word1.length() - i;
        }

        // Recursive call
        int ans;
        if(word1[i] == word2[j]){ 
            // does match -> skip both 
            ans = 0 + solveUsingRec(word1, word2, i+1, j+1);
        }
        else{ 
            //does not match -> count operation
            // insert
            int insertOpt = 1 + solveUsingRec(word1, word2, i, j+1);
            // delete
            int deleteOpt = 1 + solveUsingRec(word1, word2, i+1, j);
            // replace
            int replaceOpt = 1 + solveUsingRec(word1, word2, i+1, j+1);
            // minimum operation
            ans = min(insertOpt,min(deleteOpt, replaceOpt));
        }
        return ans;
    }

    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        int ans = solveUsingRec(word1, word2, i, j);
        return ans;
    }
};

// ================== Approach 2: Top Down Approach ================== //

class Solution {
public:
    int solveUsingMemo(string& word1, string& word2, int i, int j, vector<vector<int>> &dp){
        // Base Case
        if(i >= word1.length()){
            return word2.length() - j;
        }
        if(j >= word2.length()){
            return word1.length() - i;
        }

        // Step 3: if ans already exist then return ans
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // Step 2: store ans and return ans using DP array
        // Recursive call
        if(word1[i] == word2[j]){ 
            // does match -> skip both 
            dp[i][j] = 0 + solveUsingMemo(word1, word2, i+1, j+1, dp);
        }
        else{ 
            //does not match -> count operation
            // insert
            int insertOpt = 1 + solveUsingMemo(word1, word2, i, j+1, dp);
            // delete
            int deleteOpt = 1 + solveUsingMemo(word1, word2, i+1, j, dp);
            // replace
            int replaceOpt = 1 + solveUsingMemo(word1, word2, i+1, j+1, dp);
            // minimum operation
            dp[i][j] = min(insertOpt,min(deleteOpt, replaceOpt));
        }
        // Return ans
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        // Step 1: create DP array
        vector<vector<int>> dp (word1.length()+1, vector<int> (word2.length()+1, -1));
        int ans = solveUsingMemo(word1, word2, i, j, dp);
        return ans;
    }
};


// ================== Approach 3: Bottom-up ================== //

class Solution {
public:
    int solveUsingTabu(string& word1, string& word2, int i, int j){
        // Step 1: create DP array
        vector<vector<int>> dp (word1.length()+1, vector<int> (word2.length()+1, -1));

        // Step 2: fill initial data in DP array according to recursion base case
        for(int col = 0; col<= word2.length(); col++){
            // Mujhe last row ko fil karna hai➡️
            dp[word1.length()][col] = word2.length() - col;
        }
        for(int row = 0; row<= word1.length(); row++){
           // Mujhe last col ko fil karna hai⬇️
            dp[row][word2.length()] = word1.length() - row;
        }

        // Step 3: fill the remaining DP array according to recursion formula/logic
        for(int i = word1.length()-1; i>=0; i--){
            for(int j = word2.length()-1; j>=0; j--){
                // Recursive call
                int ans = 0;
                if(word1[i] == word2[j]){ 
                    // does match -> skip both 
                    ans = 0 + dp[i+1][j+1];
                }
                else{ 
                    //does not match -> count operation
                    // insert
                    int insertOpt = 1 + dp[i][j+1];
                    // delete
                    int deleteOpt = 1 + dp[i+1][j];
                    // replace
                    int replaceOpt = 1 + dp[i+1][j+1];
                    // minimum operation
                    ans = min(insertOpt,min(deleteOpt, replaceOpt));
                }
                dp[i][j] = ans;
            }
        }
        // Return ans
        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        int ans = solveUsingTabu(word1, word2, i, j);
        return ans;
    }
};


// ================== Approach 4: Space Optimization Approach ================== //

class Solution {
public:
    int solveUsingTabuOS(string& word1, string& word2, int i, int j){
        vector<int> next (word1.length()+1, 0);
        vector<int> curr (word1.length()+1, 0);
        
        //abhi k liye bhul jao
        // for(int col=0; col<=b.length(); col++) {
        //     dp[a.length()][col] = b.length()-col;
        // }
        //iska kuch n kuch toh karna padega, nahi toh galti krdenge - IMP
        //toh mujhe curr col ka last dabbe me b.length()-j save krna h 

        for(int row = 0; row<= word1.length(); row++){
           // Mujhe last col ko fil karna hai
            next[row] = word1.length() - row;
        }

        for(int j = word2.length()-1; j>=0; j--){
            
            // IMP: Har ek new column (curr) ke last box ko mujhe fill krna hai
            curr[word1.length()] = word2.length() - j;

            for(int i = word1.length()-1; i>=0; i--){
                // Recursive call
                int ans = 0;
                if(word1[i] == word2[j]){ 
                    // does match -> skip both 
                    ans = 0 + next[i+1];
                }
                else{ 
                    //does not match -> count operation
                    // insert
                    int insertOpt = 1 + next[i];
                    // delete
                    int deleteOpt = 1 + curr[i+1];
                    // replace
                    int replaceOpt = 1 + next[i+1];
                    // minimum operation
                    ans = min(insertOpt,min(deleteOpt, replaceOpt));
                }
                curr[i] = ans;
            }
            // shifting
            next = curr;
        }
        // Return ans
        return next[0];
    }

    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        int ans = solveUsingTabuOS(word1, word2, i, j);
        return ans;
    }
};