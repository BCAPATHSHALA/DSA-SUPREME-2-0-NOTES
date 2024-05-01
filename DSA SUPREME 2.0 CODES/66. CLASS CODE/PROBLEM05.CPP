// 4. Two pointer approach
// Problem 01: Two Sum (Leetcode-1)

/*
Problem Statement:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:
1. 2 <= nums.length <= 10^4
2. -10^9 <= nums[i] <= 10^9
3. -10^9 <= target <= 10^9
4. Only one valid answer exists.
*/

// Approach 1: Using two pointer approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Step 1: Create the array of pair<value, index> due to not shorted input array
        vector<pair<int,int>> temp;
        for(int i=0; i<nums.size(); i++){
            temp.push_back({nums[i], i});
        }

        // Step 2: Short the temp array based on value
        sort(temp.begin(), temp.end());

        // Step 3: Apply two pointer approach to get the intent output
        int start = 0;
        int end = nums.size()-1;
        vector<int> ans;

        while(start < end){
            int sum = temp[start].first + temp[end].first;
            if(sum == target){
                ans.push_back(temp[start].second);
                ans.push_back(temp[end].second);
                break;
            }
            else if(sum > target){
                end--;
            }
            else{
                start++;
            }
        }
        return ans;
    }
};