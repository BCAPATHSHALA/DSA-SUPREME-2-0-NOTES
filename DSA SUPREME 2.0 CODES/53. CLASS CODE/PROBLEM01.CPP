// 1. Painting Fence Algorithm (GFG)
/*
Problem Statement:
The painting fence algorithm determines the number of ways to paint a fence with multiple 'N' posts and 'K' colors. 
The algorithm ensures that at most 2 adjacent posts (no more than two adjacent posts) have the same color. 
Since answer can be large return it modulo 10^9 + 7 (1000000007).

Examples:

Input : N = 1 K = 3
Output : 3

Input : N = 2 K = 3
Output : 9

Input : N = 3 K = 3
Output : 24

Input : N = 4 K = 3
Output : 66
*/



// ================== Approach 1: Normal Recursion Approach ================== //

#include<iostream>
using namespace std;

int solveUsingRec(int n, int k){
    // Base Case
    if(n == 1){
        return k;
    }
    if(n == 2){
        return (k + (k*(k-1)));
    }

    // Recursive Relation
    int ans = (k-1) * (solveUsingRec(n-2,k) + solveUsingRec(n-1, k));
    return ans;
}

int main(){
    int n = 3; // Posts
    int k = 3; // Colors

    int ans = solveUsingRec(n,k);
    cout<<"Total Ways: "<< ans <<endl;
}

// ================== Approach 2: Top Down Approach ================== //

#include<iostream>
#include<vector>
using namespace std;

int solveUsingMemo(int n, int k, vector<int> &dp){
    // Base Case
    if(n == 1){
        return k;
    }
    if(n == 2){
        return (k + (k*(k-1)));
    }

    // Step 3: if ans already exist then return ans
    if(dp[n] != -1){
        return dp[n];
    }

    // Step 2: store ans and return ans using DP array
    // Recursive Relation
    dp[n] = (k-1) * (solveUsingMemo(n-2, k, dp) + solveUsingMemo(n-1, k, dp));
    return dp[n];
}

int main(){
    int n = 3; // Posts
    int k = 3; // Colors

    // Step 1: create DP array
    vector<int> dp(n+10, -1);
    int ans = solveUsingMemo(n, k, dp);
    cout<<"Total Ways: "<< ans <<endl;
}

// ================== Approach 3: Bottom-up ================== //

#include<iostream>
#include<vector>
using namespace std;

int solveUsingTabu(int n, int k){

    // Step 1: create DP array
    vector<int> dp(n+10, -1);

    // Step 2: fill initial data in DP array according to recursion base case
    dp[1] = k;
    dp[2] = (k + (k*(k-1)));

    // Step 3: fill the remaining DP array according to recursion formula/logic
    for(int i = 3; i<=n; i++){
        // Recursive Relation
        dp[i] = (k-1) * (dp[i-2] + dp[i-1]);
    }
    // return ans
    return dp[n];
}

int main(){
    int n = 3; // Posts
    int k = 3; // Colors

    
    int ans = solveUsingTabu(n, k);
    cout<<"Total Ways: "<< ans <<endl;
}

// ================== Approach 4: Space Optimization Approach ================== //

#include<iostream>
using namespace std;

int solveUsingTabuOS(int n, int k){

    int prev2 = k;
    int prev1 = (k + (k*(k-1)));

    // Corner Cases
    //(agar N ki value at least 3 hoti to corner case ki koi need hi nhi thi)
    if(n == 1){
        return prev2;
    }
    if (n == 2)
    {
        return prev1;
    }
    
    int curr;

    for(int i = 3; i<=n; i++){
        // Recursive Relation
        curr = (k-1) * (prev1 + prev2);

        // Shift Karna Bhool Jata hu
        prev2 = prev1;
        prev1 = curr;
    }

    // return ans
    return curr;
}

int main(){
    int n = 3; // Posts
    int k = 3; // Colors
    
    int ans = solveUsingTabuOS(n, k);
    cout<<"Total Ways: "<< ans <<endl;
}
