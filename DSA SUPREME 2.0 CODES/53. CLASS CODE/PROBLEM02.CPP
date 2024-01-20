// 2. 0/1 Knapsack Problem (GFG)

/*
Problem Statement:
Given N items where each item has some weight and profit associated with it and also given a bag with capacity W, 
[i.e., the bag can hold at most W weight in it]. The task is to put the items into the bag such that the sum of 
profits associated with them is the maximum possible. 

Note: The constraint here is we can either put an item completely into the bag or cannot put it at all 
[It is not possible to put a part of an item into the bag].

Examples:

Input: N = 3, W = 50,  weight[] = {10, 20, 30}, profit[] = {60, 100, 120}
Output: 220

Input: N = 3, W = 4,  weight[] = {4, 5, 1}, profit[] = {1, 2, 3}
Output: 3

Input: N = 3, W = 6,  weight[] = {1, 2, 3}, profit[] = {10, 15, 40}
Output: 65

Input: N = 3, W = 3, weight[] = {4, 5, 6}, profit[] = {1, 2, 3}
Output: 0
*/


// ================== Approach 1: Normal Recursion Approach ================== //

#include<iostream>
using namespace std;

int solveUsingRec(int capacity, int weight[], int profit[], int index, int n){
    // Base case
    if(index >= n){
        // Index outofbound hai to only exclusion ho skta hai
        // Mtlb add 0 profit
        return 0;
    }

    // Recursive relation (Inclusion or exclusion)
    int include = 0;
    if(weight[index] <= capacity){
        include = profit[index] + solveUsingRec(capacity - weight[index], weight, profit, index + 1, n);
    }
    int exclude = 0 + solveUsingRec(capacity, weight, profit, index + 1, n);
    int maxProfitAns = max(include, exclude);
    return maxProfitAns;
}

int main(){
    int capacity = 50;
    int n = 3;
    int weight[] = {10, 20, 30};
    int profit[] = {60, 100, 120};
    int index = 0;

    int ans = solveUsingRec(capacity, weight, profit, index, n);
    cout << "Max Profit: " << ans << endl;
    return 0;
}


// ================== Approach 2: Top Down Approach ================== //

#include<iostream>
#include<vector>
using namespace std;

int solveUsingMemo(int capacity, int weight[], int profit[], int index, int n, vector<vector<int>> &dp){
    // Base case
    if(index >= n){
        return 0;
    }

    // Step 3: if ans already exist then return ans
    if(dp[capacity][index] != -1){
        return dp[capacity][index];
    }

    // Step 2: store ans and return ans using DP array
    // Recursive relation (Inclusion or exclusion)
    int include = 0;
    if(weight[index] <= capacity){
        include = profit[index] + solveUsingMemo(capacity - weight[index], weight, profit, index + 1, n, dp);
    }
    int exclude = 0 + solveUsingMemo(capacity, weight, profit, index + 1, n, dp);
    dp[capacity][index] = max(include, exclude);
    return dp[capacity][index];
}

int main(){
    int capacity = 50;
    int n = 3;
    int weight[] = {10, 20, 30};
    int profit[] = {60, 100, 120};
    int index = 0;

    // Step 1: create DP array 
    // (Capacity and index change ho rhe hai iss liye 2DP Array Create Kiya hai)
    vector<vector<int>> dp(capacity+1, vector<int>(n+1, -1));

    int ans = solveUsingMemo(capacity, weight, profit, index, n, dp);
    cout << "Max Profit: " << ans << endl;
    return 0;
}

// ================== Approach 3: Bottom Up Approach ================== //

#include<iostream>
#include<vector>
using namespace std;

int solveUsingTabu(int capacity, int weight[], int profit[], int index, int n){
    // Step 1: create DP array 
    // (Capacity and index change ho rhe hai iss liye 2DP Array Create Kiya hai)
    vector<vector<int>> dp(capacity+1, vector<int>(n+1, -1));

    // Step 2: fill initial data in DP array according to recursion base case
    // Last Column ko zero se fill krna hai according to base case
    for(int row = 0; row<=capacity; row++){
        dp[row][n] = 0;
    }

    // Step 3: fill the remaining DP array according to recursion formula/logic
    for(int row=0; row<=capacity; row++){
        for(int col=n-1; col>=0; col--){
            // Recursive relation (Inclusion or exclusion)
            int include = 0;
            if(weight[col] <= row){
                include = profit[col] + dp[row - weight[col]][col + 1];
            }
            int exclude = 0 + dp[row][col + 1];
            dp[row][col] = max(include, exclude);
        }
    }
    // return ans    
    return dp[capacity][0];
}

int main(){
    int capacity = 50;
    int n = 3;
    int weight[] = {10, 20, 30};
    int profit[] = {60, 100, 120};
    int index = 0;

    int ans = solveUsingTabu(capacity, weight, profit, index, n);
    cout << "Max Profit: " << ans << endl;
    return 0;
}


// ================== Approach 4: Space Optimization Approach ================== //
#include<iostream>
#include<vector>
using namespace std;

int solveUsingTabuSO(int capacity, int weight[], int profit[], int index, int n){
    vector<int> next(capacity+1, 0);
    vector<int> curr(capacity+1, -1);

    for(int col=n-1; col>=0; col--){
        for(int row=0; row<=capacity; row++){
            // Recursive relation (Inclusion or exclusion)
            int include = 0;
            if(weight[col] <= row){
                include = profit[col] + next[row - weight[col]];
            }
            int exclude = 0 + next[row];
            curr[row] = max(include, exclude);
        }
        // Shift Karna Bhool Jata hu
        next = curr;
    }
    // return ans    
    return curr[capacity];
}

int main(){
    int capacity = 50;
    int n = 3;
    int weight[] = {10, 20, 30};
    int profit[] = {60, 100, 120};
    int index = 0;

    int ans = solveUsingTabuSO(capacity, weight, profit, index, n);
    cout << "Max Profit: " << ans << endl;
    return 0;
}

// ================== Approach 5: Space Optimization Approach 2 ================== //
#include<iostream>
#include<vector>
using namespace std;

int solveUsingTabuSO2(int capacity, int weight[], int profit[], int index, int n){
    vector<int> next(capacity+1, 0);

    for(int col=n-1; col>=0; col--){
        for(int row=capacity; row>=0; row--){
            // Recursive relation (Inclusion or exclusion)
            int include = 0;
            if(weight[col] <= row){
                include = profit[col] + next[row - weight[col]];
            }
            int exclude = 0 + next[row];
            next[row] = max(include, exclude);
        }
    }
    // return ans    
    return next[capacity];
}

int main(){
    int capacity = 50;
    int n = 3;
    int weight[] = {10, 20, 30};
    int profit[] = {60, 100, 120};
    int index = 0;

    int ans = solveUsingTabuSO2(capacity, weight, profit, index, n);
    cout << "Max Profit: " << ans << endl;
    return 0;
}

