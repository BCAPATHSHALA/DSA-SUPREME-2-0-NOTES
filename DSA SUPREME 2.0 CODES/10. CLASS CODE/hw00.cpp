// HW 01: Re-arrange array elements (Leetcode-2149)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Size of nums
        int size=nums.size();

        // Create new vector array
        vector<int> ans(size,0);

        // Create positive index and negative index
        int posIndex=0;
        int negIndex=1;

        // Iterate the entire array
        for(int index=0;index<size;index++){
            // When element is positive then use even index in ans
            if(nums[index]>0){
                ans[posIndex]=nums[index];
                posIndex+=2;
            }
            // When element is positive then use even index in ans
            else{
                ans[negIndex]=nums[index];
                negIndex+=2;
            }
        }

        // Return new array
        return ans;
        
    }
};

// Time Complexity: O(N)

/*
Example 1:
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  

Example 2:
Input: nums = [-1,1]
Output: [1,-1]
Explanation:
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].
*/