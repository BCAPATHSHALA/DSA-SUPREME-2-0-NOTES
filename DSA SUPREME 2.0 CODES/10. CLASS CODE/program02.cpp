// Program 02: Sort Colors (Leetcode-75) 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int index=0;

        while(index<=end){
            if(nums[index]==0){
                swap(nums[index],nums[start]);
                index++;
                start++;
            }
            else if(nums[index]==1){
                index++;
            }
            else if(nums[index]==2){
                swap(nums[index],nums[end]);
                end--; // Yaha par mujhse galti ho skti hai
            }
        }
    }
};
// Time Complexity: O(N)

/*
Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]
*/