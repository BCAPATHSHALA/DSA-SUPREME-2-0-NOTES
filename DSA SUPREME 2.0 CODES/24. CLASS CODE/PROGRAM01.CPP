// 📂 Program 01: Maximum sum of nod - adjacent element - House Robber (Leetcode-198)
class Solution {
public:
    int solve(vector<int>&nums, int index, int size){
        // Base case
        if(index>=size){
            return 0;
        }

        // ith house par robbering
        int opt1 = nums[index] + solve(nums, index+2, size);

        // ith house par not robbering
        int opt2 = 0 + solve(nums, index+1, size);
        
        // max ammont from both
        int maxAmmount = max(opt1, opt2);
        return maxAmmount;
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        int index = 0;
        if(size == 1)
        {
            return nums[0];
        }
        return solve(nums, index, size);
    }
};