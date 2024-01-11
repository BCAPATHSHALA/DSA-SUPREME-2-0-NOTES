// 2. Coin Change (Leetcode-322)

// ================== Exploring All Possible Ways Pattern ========================= //


// ================== Approach 1: Normal Recursion Approach ================== //
class Solution {
public:
    int solveUsingRec(vector<int>& coins, int amount){
        // Base case
        if(amount == 0){
            return 0;
        }

        // Recursive relation
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int coin = coins[i];

            // Jav amount >= coin se tabhi change kr skte hai
            if(amount - coin >= 0){
                int recKaAns = solveUsingRec(coins, amount - coin);
                // Recursion ka ans (INT_MAX + 1) outOfRange to nhi hai check krlo
                if(recKaAns != INT_MAX ){
                    int ans = 1 + recKaAns;
                    mini = min(mini, ans);
                }
            }
        }
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solveUsingRec(coins, amount);
        if(ans == INT_MAX){
            // Invalid ans hai
            return -1;
        }
        else{
            // Valid ans hai
            return ans;
        }
    }
};
// ================== Approach 2: Top Down Approach ================== //
class Solution {
public:
    int solveUsingMemo(vector<int>& coins, int amount, vector<int>&dp){
        // Base case
        if(amount == 0){
            return 0;
        }
        
        // Step 3: if ans already exist then return ans
        if(dp[amount] != -1){
            return dp[amount];
        }

        // Step 2: store ans and return ans using DP array
        // TOP DOWN: Traverse from amount to 0
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int coin = coins[i];

            // Jav amount >= coin se tabhi change kr skte hai
            if(amount - coin >= 0){
                int recKaAns = solveUsingMemo(coins, amount - coin, dp);
                // Recursion ka ans (INT_MAX + 1) outOfRange to nhi hai check krlo
                if(recKaAns != INT_MAX ){
                    int ans = 1 + recKaAns;
                    mini = min(mini, ans);
                }
            }
        }
        // Store ANS
        dp[amount] = mini;
        // return ANS
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        // Step 1: create DP array
        int n = amount;
        vector<int> dp(n+1, -1);

        int ans = solveUsingMemo(coins, amount, dp);
        if(ans == INT_MAX){
            // Invalid ans hai
            return -1;
        }
        else{
            // Valid ans hai
            return ans;
        }
    }
};


// ================== Approach 3: Bottom-up ================== //
class Solution {
public:
    int solveUsingTabu(vector<int>& coins, int amount) {
        // Step 1: create DP array
        int n = amount;
        vector<int> dp(n+1, INT_MAX);

        // Step 2: fill initial data in DP array according to recursion base case
        dp[0] = 0;

        // Step 3: fill the remaining DP array according to recursion formula/logic
        // BOTTOM UP: Traverse from 0 to amount
        for( int value = 1; value<=amount; value++) {
            int mini = INT_MAX;
            for(int i=0; i<coins.size(); i++) {
            
                if(value - coins[i] >= 0) {
                    int recKaAns = dp[value - coins[i] ];
                    
                    if(recKaAns != INT_MAX) {
                        
                        int ans = 1 + recKaAns;
                        mini  = min(mini, ans);
                    }
                }
            }
            dp[value] = mini;
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solveUsingTabu(coins, amount);
        if(ans == INT_MAX){
            // Invalid ans hai
            return -1;
        }
        else{
            // Valid ans hai
            return ans;
        }
    }
};



