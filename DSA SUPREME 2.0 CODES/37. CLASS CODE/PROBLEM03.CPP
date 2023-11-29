// 3. Sliding Window Maximum (Leetcode-239)

/*
Problem Statement:
You are given an array of integers nums, there is a sliding window of size k which is moving 
from the very left of the array to the very right. You can only see the k numbers in the window. 
Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:
1. 1 <= nums.length <= 10^5
2. -10^4 <= nums[i] <= 10^4
3. 1 <= k <= nums.length

APPROACH 1: USING QUEUE (Window Sliding Pattern)
Time Complexity: O(N), where N is size of array
Space Complexity: O(K), where K is the size of the window
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q; // store the max element's index
        vector<int> ans; // store the max element

        // Step 1: process the first window for "k time"
        for(int index = 0; index < k; index++){
            int element = nums[index];

            // Agar queue me element chotta hai
            while(!q.empty() && element > nums[q.back()]){
                q.pop_back();
            }

            // Yanha tabhi pahuch skta hu
            // Ya to queue me element chotta nhi hai
            // Ya queue empty ho chuka hai
            q.push_back(index);
        }

        // Step 2: process remaning windows
        for(int index = k; index < nums.size(); index++){
            // Purani window ka ans store kardo
            ans.push_back(nums[q.front()]);

            // Remove
            // I -> remove the out of range index from queue
            if(!q.empty() && index - q.front() >= k){
                q.pop_front();
            }

            // II -> remove chotta index from queue
            // Agar queue me element chotta hai
            while(!q.empty() && nums[index] > nums[q.back()]){
                q.pop_back();
            }

            // Addition
            // Yanha tabhi pahuch skta hu
            // Ya to queue me element chotta nhi hai
            // Ya queue empty ho chuka hai
            q.push_back(index);
        }

        // Last window ka ans store karlo
        ans.push_back(nums[q.front()]);

        return ans;
    }
};