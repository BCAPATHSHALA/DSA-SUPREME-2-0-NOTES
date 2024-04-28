// 3. Variable size window 
// Problem 01: Minimum Size Subarray Sum (Leetcode-209)

/*
Problem Statement: 
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:
1. 1 <= target <= 10^9
2. 1 <= nums.length <= 10^5
3. 1 <= nums[i] <= 10^4

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Step 1: Initializing the start and end
        int start = 0;
        int end = 0;
        int windowLength = INT_MAX;
        int windowSum = 0;

        // Step 2: Find the answer
        while(end < nums.size()){
            // Store the value in windowSum
            windowSum = windowSum + nums[end];

            while(windowSum >= target){
                // Minimize the window
                if(windowSum >= target){
                    int currLength = end - start + 1;
                    windowLength = min(windowLength, currLength);
                }
                // Current element, pointed by start, should be remove from the new window
                windowSum = windowSum - nums[start];
                start++;
            }
            
            // Loop se bahar tabhi aa skte hai jab windowSize < target hoga
            // Explore the window
            end++;            
        }

        // Edge case: me hamesha ynha galti karta hu
        if(windowLength == INT_MAX){
            // Apply for example 3
            return 0;
        }
        return windowLength;
    }
};
