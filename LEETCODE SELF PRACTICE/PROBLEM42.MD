DATE: 02-05-2024

## Problem 42: [ Largest Positive Integer That Exists With Its Negative (Leetcode-2441) ](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given an integer array `nums` that **does not contain any zeros**, find the **largest positive integer** `k` such that `-k` also exists in the array.

Return the positive integer `k`. If there is no such integer, return `-1`.

## Examples

Example 1:

```bash
Input: nums = [-1,2,-3,3]
Output: 3
Explanation: 3 is the only valid k we can find in the array.
```

Example 2:

```bash
Input: nums = [-1,10,6,7,-7,1]
Output: 7
Explanation: Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.
```

Example 3:

```bash
Input: nums = [-10,8,6,7,-2,-3]
Output: -1
Explanation: There is no a single valid k, we return -1.
```

Example 4:

```bash
Input: nums = [-10,-7,-3,-2,6,7,8,9]
Output: 7
```

Example 5:

```bash
Input: nums = [7,7]
Output: -1
```

## Constraints:

1. `1 <= nums.length <= 1000`
2. `-1000 <= nums[i] <= 1000`
3. `nums[i] != 0`

**Companies**:
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:

- [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)

## Solution 1

```cpp
// Two Pointer Approach
// Time Complexity: O(n log n)
// Space Complexity: O(1)
// Author: github.com/BCAPATHSHALA

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        // Step 1: sort the nums
        sort(nums.begin(), nums.end());

        // Step 2: compare start and end element in shorted element
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;

        // Corner Case: all are positive element in nums
        if(nums[start] > 0){
            return -1;
        }

        while(start < end){
            int startElement = abs(nums[start]);
            int endElement = nums[end];

            if( startElement == endElement){
                ans = startElement;
                break;
            }
            else if(startElement > endElement){
                start++;
            }
            else if(startElement < endElement){
                end--;
            }
        }
        return ans;
    }
};
```
