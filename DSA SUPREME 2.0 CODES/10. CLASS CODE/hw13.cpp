// HW 13: Find Pivot Index with prefix sum approach (Leetcode-724)
class Solution {
public:
    /*
    First Approach
    APPROACH PSEUDO CODE:
    Step 01: find total sum of array as right sum
    Step 02: subtract element one by one from right sum until left sum is equal to right sum
    Step 03: return the index which terminate the loop

    TIME COMPLEXITY: O(N), Where N is length of nums
    SPACE COMPLEXITY: O(1), No extra space used
    */
    int totalSum(vector<int>& nums){
        int n=nums.size();
        int rightSum=0;
        int leftSum=0;
        
        // Total sum and right sum
        for(int i=0;i<n;i++){
            rightSum+=nums[i];
        }
        // Check rightsum == leftSum and return index
        for(int i=0;i<n;i++){
            rightSum-=nums[i];
            if(rightSum==leftSum){
                return i;
            }
            leftSum+=nums[i];
        }
        return -1;
    }

    
    /*
    Second Approach
    APPROACH PSEUDO CODE:
    Step 01: create two vector rightSum and leftSum to prefix sum
    Step 02: iterate nums till rightSum[i]==leftSum[i]
    Step 03: return the index which terminate the loop

    TIME COMPLEXITY: O(N), Where N is length of nums
    SPACE COMPLEXITY: O(N), Where N is length of rightSum and leftSum
    */
    int prefixSum(vector<int>& nums){
        int n=nums.size();
        vector<int> rightSum(n,0);
        vector<int> leftSum(n,0);

        // leftSum
        for(int i=1;i<n;i++){
            leftSum[i] = nums[i-1] + leftSum[i-1];
        }

        // rightSum
        for(int i=n-2;i>=0;i--){
            rightSum[i] = nums[i+1] + rightSum[i+1];
        }

        // Compare rightSum and leftSum to find pivot
        for(int i=0;i<n;i++){
            if(leftSum[i]==rightSum[i]){
                return i;
            }
        }

        return -1;
    }

    // Find Pivot Index
    int pivotIndex(vector<int>& nums) {
        int ans1 = prefixSum(nums);
        return ans1;
    }
};

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