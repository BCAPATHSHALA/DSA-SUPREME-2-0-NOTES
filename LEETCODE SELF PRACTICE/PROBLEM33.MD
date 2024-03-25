DATE: 25-03-2024

## Problem 33: [ Find All Duplicates in an Array (Leetcode-442) ](https://leetcode.com/problems/find-all-duplicates-in-an-array)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given an integer array `nums` of length `n` where all the integers of `nums` are in the range `[1, n]` and each integer appears **once** or **twice**, return an array of all the integers that appears **twice**.

You must write an algorithm that runs in `O(n)` time and uses only constant extra space.

## Examples

Example 1:

```bash
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
```

Example 2:

```bash
Input: nums = [1,1,2]
Output: [1]
```

Example 3:

```bash
Input: nums = [1]
Output: []
```

## Constraints:

1. `n == nums.length`
2. `1 <= n <= 10^5`
3. `1 <= nums[i] <= n`
4. Each element in `nums` appears **once** or **twice**.

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:

- [Find All Numbers Disappeared in an Array (Easy)](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)

## Solution 1

```cpp
// Optimal Approach
// Time Complexity: O(N)
// Space Complexity: O(1)
// Author: github.com/BCAPATHSHALA

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for(int i=0; i<n; i++){
            int index = abs(nums[i]);
            if(nums[index-1] < 0){
                // Repeat the index means a duplicate number occurred 
                ans.push_back(index);
            }
            // Marking the index value as -ve if +ve or +ve if -ve
            nums[index-1] *= -1;
        }
        return ans;
    }
};
```
