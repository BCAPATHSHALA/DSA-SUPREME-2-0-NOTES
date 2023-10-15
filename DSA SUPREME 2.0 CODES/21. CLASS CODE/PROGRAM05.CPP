// ✅Program 05: Coin change (Leetcode-322)
class Solution {
public:
    int solve(vector<int>& coins, int amount){
        // Base Case
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }

        // Processing
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int coin = coins[i]; // current coin is already used

            // Current coin ko tabhi use karenge jab uski
            // value <= amount hogi
            if(coin <= amount){
                // Relation
                int recAns = solve(coins, amount - coin); 
                // agar recAns INT_MAX ke equal hai or usme 1 add kar diya to 
                // ans ki value integer ki range se bahar hojayegi
                if(recAns != INT_MAX){
                    int ans = 1 + recAns;
                    mini = min(ans, mini);
                }
            }
        }
        return mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);

        // agar ans = INT_MAX aa rha hai to me coin change nhi kar skta hu
        if(ans == INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};

/*
Find kya karna hai: Return the fewest number of coins (SABSE KUM NUMBER OF COINS)
Notes: You may assume that you have an infinite number of each kind of coin. 

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0
*/