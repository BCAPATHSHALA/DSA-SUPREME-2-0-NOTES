// 1. Guess Number Higher or Lower II (Leetcode-375)

/*
Problem statement:
We are playing the Guessing Game. The game will work as follows:

1. I pick a number between 1 and n.
2. You guess a number.
3. If you guess the right number, you win the game.
4. If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
5. Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.

Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

Example 1:
Input: n = 10
Output: 16
Explanation: The winning strategy is as follows:
- The range is [1,10]. Guess 7.
    - If this is my number, your total is $0. Otherwise, you pay $7.
    - If my number is higher, the range is [8,10]. Guess 9.
        - If this is my number, your total is $7. Otherwise, you pay $9.
        - If my number is higher, it must be 10. Guess 10. Your total is $7 + $9 = $16.
        - If my number is lower, it must be 8. Guess 8. Your total is $7 + $9 = $16.
    - If my number is lower, the range is [1,6]. Guess 3.
        - If this is my number, your total is $7. Otherwise, you pay $3.
        - If my number is higher, the range is [4,6]. Guess 5.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $5.
            - If my number is higher, it must be 6. Guess 6. Your total is $7 + $3 + $5 = $15.
            - If my number is lower, it must be 4. Guess 4. Your total is $7 + $3 + $5 = $15.
        - If my number is lower, the range is [1,2]. Guess 1.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $1.
            - If my number is higher, it must be 2. Guess 2. Your total is $7 + $3 + $1 = $11.
The worst case in all these scenarios is that you pay $16. Hence, you only need $16 to guarantee a win.

Example 2:
Input: n = 1
Output: 0
Explanation: There is only one possible number, so you can guess 1 and not have to pay anything.

Example 3:
Input: n = 2
Output: 1
Explanation: There are two possible numbers, 1 and 2.
- Guess 1.
    - If this is my number, your total is $0. Otherwise, you pay $1.
    - If my number is higher, it must be 2. Guess 2. Your total is $1.
The worst case is that you pay $1.
 

Constraints:
1. 1 <= n <= 200
*/


// ================== Approach 1: Normal Recursion Approach ================== //

class Solution {
public:
    int solveUsingRec(int start, int end){
        // Base case
        if(start >= end){
            return 0;
        }

        // Recursive call
        int ans = INT_MAX;
        for(int i = start; i<=end; i++){
            ans = min(ans, i + max(solveUsingRec(start, i-1), solveUsingRec(i+1, end)));
        }
        return ans;        
    }

    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;
        int ans = solveUsingRec(start, end);
        return ans;
    }
};


// ================== Approach 2: Top Down Approach ================== //

class Solution {
public:
    int solveUsingMemo(int start, int end, vector<vector<int>> &dp){
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
        for(int i = start; i<=end; i++){
            ans = min(ans, i + max(solveUsingMemo(start, i-1, dp), solveUsingMemo(i+1, end, dp)));
        }
        dp[start][end] = ans;
        return dp[start][end];        
    }
    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;
        // Step 1: create DP array
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        int ans = solveUsingMemo(start, end, dp);
        return ans;
    }
};

// ================== Approach 3: Bottom-up ================== //

class Solution {
public:
    int solveUsingTabu(int n){
        // Step 1: create DP array
        // Step 2: fill initial data in DP array according to recursion base case
        vector<vector<int>> dp(n+2, vector<int> (n+1, 0));

        // Step 3: fill the remaining DP array according to recursion formula/logic
        for(int start = n; start >= 1; start--){
            for(int end = 1; end <= n; end++){

                if(start >= end){
                    // Skip for invalid range
                    continue;
                }

                // Recursive call
                int ans = INT_MAX;
                for(int i = start; i<=end; i++){
                    ans = min(ans, i + max(dp[start][i-1], dp[i+1][end]));
                }
                dp[start][end] = ans;
            }
        }
        // return ans
        return dp[1][n];        
    }
    int getMoneyAmount(int n) {
        int ans = solveUsingTabu(n);
        return ans;
    }
};