// HW 01: Find pivot element (Leetcode-724)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int rightSum=0;
        int leftSum=0;
        
        // Step 01: total sum as right sum
        for(int i=0;i<n;i++){
            rightSum+=nums[i];
        }
        
        for(int i=0;i<n;i++){
            rightSum-=nums[i]; // Subtract element one by one from right sum until left sum equal to right sum
            if(rightSum==leftSum){
                return i; // when leftsum and rigt sum are equal then return index to break the loop
            }
            leftSum+=nums[i]; // left sum is increment by nums[i] element
        }
        return -1; // when there is no index that satisfies the conditions in the problem statement, then return -1
    }
};


// Time Complexity: O(N)


/*
Example 1:
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

Example 2:
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
*/