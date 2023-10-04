// HW 12: Majority Element (Leetcode-169)

/*
🔗PROBLEM STATEMENT:
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.

✅ISKA MTLB YEH HAI: majority element always equal to (mid) index par exist krega jab array sorted form me hogaa;
 
Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

🖊️BRUTE FORCE APPROACH 01:
Step 01: count each elements
Step 02: compare each elements
Step 03: return highest counted element = majority element

Time Complexity: O(N^2), where N is length of array
Space Complexity: O(1), no extra space used

🖊️BINARY SEARCH APPROACH 02:
Step 01: first occurrence of mid
Step 02: last occurrence of mid
Step 03: total occurrence of mid = majority element

Time Complexity: O(N log N), where N is length of array
Space Complexity: O(1), no extra space used

🖊️SORTING APPROACH 03:
Step 01: sort the array
Step 02: return the mid index element = majority element

Time Complexity: O(N log N), where N is length of array
Space Complexity: O(1), no extra space used

*/



// 🖊️SORTING APPROACH 03:
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int midIndex = (0 + nums.size()-1)/2;
        return nums[midIndex];
    }
};