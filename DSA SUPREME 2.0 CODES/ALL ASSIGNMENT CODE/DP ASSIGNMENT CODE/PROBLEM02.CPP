// 2. Minimum Cost for Tickets (Leetcode-983)

/*
Problem Statement:
You have planned some train traveling one year in advance. 
The days of the year in which you will travel are given as an integer array days. 
Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

Way1: a 1-day pass is sold for costs[0] dollars,
Way2: a 7-day pass is sold for costs[1] dollars, and
Way3: a 30-day pass is sold for costs[2] dollars.

Note: The passes allow that many days of consecutive travel.
For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.

Find kya karna hai: Return the minimum number of dollars you need to travel every day in the given list of days.

Example 1:
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.

Example 2:
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.

Example 3:
Input: days = [2,5], costs = [1,4,25]
Output: 2

Constraints:
1. 1 <= days.length <= 365
2. 1 <= days[i] <= 365
3. days is in strictly increasing order.
4. costs.length == 3
5. 1 <= costs[i] <= 1000

*/


// ================== Approach 1: Normal Recursion Approach ================== //
//* Time Complexity: O(3)^N
//* Space Complexity: O(N)

class Solution {
public:
    int solveUsingRec(vector<int>& days, vector<int>& costs, int i){
        // Base case
        if(i >= days.size()){
            return 0;
        }

        // Solve for one case in three different ways
        // Way 1: 1 Day Pass Taken
        int cost1 = costs[0] + solveUsingRec(days, costs, i + 1);

        // Way 2: 7 Day Pass Taken
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while(j < days.size() && days[j] <= passEndDay){
            // consecutive travel: 7daysPass se me kis kis din travel kar skta hu
            // and mujhe next pass kab kharidna hai uske j update kar doonga
            j++;
        }
        int cost7 = costs[1] + solveUsingRec(days, costs, j);

        // Way 3: 30 Day Pass Taken
        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost30 = costs[2] + solveUsingRec(days, costs, j);

        // Retunr ans
        int ans = min(cost1, min(cost7, cost30));
        return ans;

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = solveUsingRec(days, costs, 0);
        return ans;
    }
};

// ================== Approach 2: Top Down Approach ================== //
//* Time Complexity: O(3N)
//* Space Complexity: O(N)

class Solution {
public:
    int solveUsingMemo(vector<int>& days, vector<int>& costs, int i, vector<int> &dp){
        // Base case
        if(i >= days.size()){
            return 0;
        }

        // Step 3: if ans already exist then return ans
        if(dp[i] != -1){
            return dp[i];
        }

        // Step 2: store ans and return ans using DP array
        // Recursive call:
        // Solve for one case in three different ways
        // Way 1: 1 Day Pass Taken
        int cost1 = costs[0] + solveUsingMemo(days, costs, i + 1, dp);

        // Way 2: 7 Day Pass Taken
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost7 = costs[1] + solveUsingMemo(days, costs, j, dp);

        // Way 3: 30 Day Pass Taken
        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost30 = costs[2] + solveUsingMemo(days, costs, j, dp);

        // Store ans in dp
        dp[i] = min(cost1, min(cost7, cost30));
        // return ans
        return dp[i];

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        // Step 1: create DP array
        vector<int> dp(n+1, -1);
        int ans = solveUsingMemo(days, costs, 0, dp);
        return ans;
    }
};


// ================== Approach 3: Bottom-up ================== //
//* Time Complexity: O(N)^2
//* Space Complexity: O(N)

class Solution {
public:
    int solveUsingTabu(vector<int>& days, vector<int>& costs){
        // Step 1: create DP array
        // Step 2: fill initial data in DP array according to recursion base case
        int n = days.size();
        vector<int> dp(n+1, 0);

        // Step 3: fill the remaining DP array according to recursion formula/logic
        for(int i = n-1; i >= 0; i--){
            // Solve for one case in three different ways
            // Way 1: 1 Day Pass Taken
            int cost1 = costs[0] + dp[i + 1];

            // Way 2: 7 Day Pass Taken
            int passEndDay = days[i] + 7 - 1;
            int j = i;
            while(j < days.size() && days[j] <= passEndDay){
                j++;
            }
            int cost7 = costs[1] + dp[j];

            // Way 3: 30 Day Pass Taken
            passEndDay = days[i] + 30 - 1;
            j = i;
            while(j < days.size() && days[j] <= passEndDay){
                j++;
            }
            int cost30 = costs[2] + dp[j];
            dp[i] = min(cost1, min(cost7, cost30));
        }

        // Return ans
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = solveUsingTabu(days, costs);
        return ans;
    }
};