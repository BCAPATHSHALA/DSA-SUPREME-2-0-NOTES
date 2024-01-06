// Find Nth Fibonacci Number (Leetcode-509)

// ================== Approach 1: Normal Recursion Approach ================== //
class Solution {
public:
    int solveUsingRec(int n) {
        // Base case
        if(n == 0 || n == 1){
            return n;
        }

        // Recursive relation
        int ans = solveUsingRec(n-1) + solveUsingRec(n-2);
        return ans;
    }

    int fib(int n) {
        int ans = solveUsingRec(n);
        return ans;
    }
};

// ================== Approach 2: Top Down Approach ================== //
class Solution {
public:
    int solveUsingMem(int n, vector<int> &dp) {
        // Base case
        if(n == 0 || n == 1){
            dp[n] = n;
            return dp[n];
        }

        // Step 3: if ans already exist then return ans
        if(dp[n] != -1){
            return dp[n];
        }

        // Step 2: store ans and return ans using DP array
        dp[n] = solveUsingMem(n-1, dp) + solveUsingMem(n-2, dp);
        return dp[n];
    }

    int fib(int n) {
        // Step 1: create DP array
        vector<int> dp(n+1, -1);
        int ans = solveUsingMem(n, dp);
        return ans;
    }
};


// ================== Approach 3: Bottom-up Approach ================== //
class Solution {
public:
    int solveUsingTab(int n) {
        // Step 1: create DP array
        vector<int> dp(n+1, -1);

        // Step 2: fill initial data in DP array according to recursion base case
        dp[0] = 0;
        if(n == 0 ){
            return dp[0];
        }
        dp[1] = 1;

        // Step 3: fill the remaining DP array according to recursion formula/logic
        for(int i=2; i<=n; i++){
            // Copy paste the recursive relation 
            // Replace recursive call with DP array
            // Make sure DP array is using looping variable "i" 
            dp[i] = dp[i-1] + dp[i-2];
        }     

        // return ans 
        return dp[n];
    }
    int fib(int n) {
        int ans = solveUsingTab(n);
        return ans;
    }
};


// ================== Approach 4: Space Optimization Approach ================== //
class Solution {
public:
    int solveUsingTabSpaceOpt(int n) {
        
        int prev = 0;
        if(n == 0 ){
            return prev;
        }

        int curr = 1;
        if(n == 1 ){
            return curr;
        }

        int ans = 0;
        
        for(int i=2; i<=n; i++){
            ans = prev + curr;
            // Move both prev and curr -> 1 step forward 
            prev = curr;
            curr = ans;
        }     

        // return ans 
        return ans;
    }
    int fib(int n) {
        int ans = solveUsingTabSpaceOpt(n);
        return ans;
    }
};