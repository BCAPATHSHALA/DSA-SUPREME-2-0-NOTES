// HW 01: K-Diff Pairs in An Array (Leetcode-532)

/*
Two Pointer Approach
Step 01: sort the array
Step 02: when diff of nums[i] and nums[j] equal to k then store different ans pair
		i++ and j++
Step 03: when diff of nums[i] and nums[j] greater than k then
		i++
Step 04: when diff of nums[i] and nums[j] less than k then
		j++
Step 05: when i equal to j then i++ because i!=j
Step 06: return numbers of diff pair

Time Complexity: O(NlogN), where N is length of array nums
Space Complexity: O(1), no extra space used
*/
class Solution {
public:
    int twoPointerSol(vector<int>& nums, int k){
        sort(nums.begin(),nums.end());
        set<pair<int,int>> ans;
        int n = nums.size();
        int i = 0;
        int j = 1;

        while(j < n){
            if(nums[j] - nums[i] == k){
                ans.insert({nums[i],nums[j]});
                i++;
                j++;
            }
            else if(nums[j] - nums[i] < k){
                j++;
            }
            else{
                i++;
            }
            if(i==j){
                j++;
            }
        }
        return ans.size();
    }
    
    int findPairs(vector<int>& nums, int k) {
        return twoPointerSol(nums, k);
    }
};

/*
Binary Search Approach
Step 01: sort the array
Step 02: apply binary search

Time Complexity: O(NlogN), where N is length of array nums
Space Complexity: O(1), no extra space used
*/
class Solution {
public:
    // Binary Search Approach
    bool bs(vector<int>& nums,int start,int target){
        int end = nums.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]>target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return false;
    }
    int binarySortingSol(vector<int>& nums, int k){
        sort(nums.begin(),nums.end());
        set<pair<int,int>> ans;

        for(int i=0;i<nums.size();i++){
            bool target = bs(nums,i+1,nums[i]+k);

            if(target){
                ans.insert({nums[i],nums[i]+k});
            }
        }
        return ans.size();
    }
    
    int findPairs(vector<int>& nums, int k) {
        return binarySortingSol(nums, k);
    }
};

/*
Example 1:
Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.

Example 2:
Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

Example 3:
Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).

Example 4:
Input: nums = [1,1,1,1,1], k = 0
Output: 1

Example 5:
Input: nums = [-1,1], k = 0
Output: 0
*/