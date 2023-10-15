// ✅Program 06: House Robber (Leetcode-198)
class Solution {
public:
    int solve(vector<int>& nums, int size, int index){
        // Base Case
        if(index >= size){
            return 0;
        }

        // Chori karlo --> ith index par
        int option1 = nums[index] + solve(nums, size, index + 2);

        // Chori mat karo --> ith index par
        int option2 = 0 + solve(nums, size, index + 1);

        // return the Maximum Amount
        int finalAns = max(option1, option2);
        return finalAns;
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        int index = 0;
        int ans = solve(nums, size, index);
        return ans;        
    }
};

/*
Given an integer array "nums" representing the amount of money of each house, 
return the "maximum amount of money" you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/