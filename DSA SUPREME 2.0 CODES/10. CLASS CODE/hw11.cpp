// HW 11: Remove Duplicates From Sorted Array (Leetcode-26)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int N=nums.size();
        int j=0; // J is a unique element's position
        int i=1;

        while(i<N){
            if(nums[i]==nums[j]){
                i++;
            }else{
                nums[++j]=nums[i++];
            }
        }
        return j+1;
    }
};
/*
Time Complexity: O(N), Where N is size of array
Space Complexity: O(1)
*/

/*
Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/