// HW 03: Find Duplicate Number (Leetcode-287)

// Solution 01: Sorting method
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Step 01: Sort nums
        sort(nums.begin(), nums.end());

        // Step 02: Iterate sorted array
        int duplicate=-1;
        for(int i=0;i<nums.size()-1;i++){
          	// Check duplicate number
            if(nums[i]==nums[i+1]){
                duplicate = nums[i];
                break;
            }
        }
        return duplicate;
    }
};

// T.C. = O(NlogN)
// S.C. = O(N)

// Solution 02: Negative marking method
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int duplicate=-1;
        for(int i=0;i<nums.size();i++){

            // Store absolute position temporary
            int index=abs(nums[i]);

            // Not visited position
            if(nums[index]>0){
                nums[index]*=-1;
            }
            // Already visited position
            else{
                duplicate=index;
                return duplicate;
            }
        }
        return duplicate;
    }
};

// T.C. = O(N)
// S.C. = O(1)

// Solution 03: Position and swaping marking method
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(nums[0]!=nums[nums[0]]){
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
    }
};

// T.C. = O(N)
// S.C. = O(1)


/*
Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3

Example 3:
Input: nums = [2,2,2,2,2]
Output: 2

Example 4:
Input: nums = [1,2,3,4]
Output: -1
*/