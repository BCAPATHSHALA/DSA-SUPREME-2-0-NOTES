// Problem 05: Sliding Window Maximum (Leetcode-239)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Initialize a deque which store the index of window
        deque<int>dq;
        // vector which store the maximum element in a each window
        vector<int>ans;

        // Step 1: For the first window
        for(int i=0;i<k;i++){
            // Remove the index which have lower value
            while(!dq.empty()&&nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }          
            // push the current index in dq
            dq.push_back(i);
        }
        // store the maximum element in a first window
        ans.push_back(nums[dq.front()]);
        
        // Step 2: for rest window
        for(int i=k;i<nums.size();i++){
            // removal
            if(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            // Insert the element index
            dq.push_back(i);
            // store ans
            ans.push_back(nums[dq.front()]);
        }
         return ans;
    }
};

/*
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
*/