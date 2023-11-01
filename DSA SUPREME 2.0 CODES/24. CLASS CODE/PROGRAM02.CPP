// 📂 Program 02: House Robber II (Leetcode-213)
/*
All houses at this place are arranged in a circle.
That means the first house is the neighbor of the last one.
Find kya karna hai : maximum amount of money you can rob tonight
*/

class Solution {
public:
    int solve(vector<int>& nums, int s, int e){
        // Base Case
        if(s > e){
            return 0;
        }

        // Robbering Karlo --> ith index par
        int opt1 = nums[s] + solve(nums, s+2, e);

        // Robbering mat Karo --> ith index par
        int opt2 = 0 + solve(nums, s+1, e);

        // Maximum amount of money
        int maxAmount = max(opt1, opt2);

        return maxAmount;

    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Single element --> yanha par maine galti ki thi
        if(n == 1){
            return nums[0];
        }
        
        int opt1 = solve(nums, 0, n-2);
        int opt2 = solve(nums, 1, n-1);
        int ans = max(opt1, opt2);
        
        return ans;
    }
};