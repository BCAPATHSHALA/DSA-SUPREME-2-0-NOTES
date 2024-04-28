// 3. Variable size window 
// Problem 02: Binary Subarrays With Sum (Leetcode-930)

/*
Problem Statement:
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,_,_]
[1,0,1,0,_]
[_,0,1,0,1]
[_,_,1,0,1]

Example 2:
Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 

Constraints:
1. 1 <= nums.length <= 3 * 10^4
2. nums[i] is either 0 or 1.
3. 0 <= goal <= nums.length

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Step 1: Initializing the start and end
        int start = 0;
        int end = 0;
        int windowSum = 0;
        int prefixZero = 0;
        int count = 0;

        // Step 2: Find the answer
        while(end < nums.size()){
            // Store the value in windowSum
            windowSum = windowSum + nums[end];

            // Minimise the window
            while(start < end && (windowSum > goal || nums[start] == 0)){
                if(nums[start] == 1){
                    prefixZero = 0;
                }
                else{
                    prefixZero += 1;
                }
                // Current element, pointed by start, should be remove from the new window
                windowSum = windowSum - nums[start];
                start++;
            }
            // Verification
            if(windowSum == goal){
                count += prefixZero + 1;
            }
            // Explore the window
            end++;
        }
        return count;
    }
};