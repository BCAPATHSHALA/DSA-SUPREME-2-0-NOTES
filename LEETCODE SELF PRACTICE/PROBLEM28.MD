DATE: 16-03-2024

## Problem 28: [ Find Peak Element (Leetcode-162) ](https://leetcode.com/problems/find-peak-element)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

A peak element is an element that is strictly greater than its neighbors.

Given a **0-indexed** integer array `nums`, find a peak element, and return its index. If the array contains multiple peaks, return the index to **any of the peaks**.

You may imagine that `nums[-1] = nums[n] = -∞`. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in `O(log n)` time.

## Examples

Example 1:

```bash
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
```

Example 2:

```bash
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
```

## Constraints:

1. `1 <= nums.length <= 1000`
2. `-2^31 <= nums[i] <= 2^31 - 1`
3. `nums[i] != nums[i + 1]` for all valid `i`.

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Peak Index in a Mountain Array (Easy)](https://leetcode.com/problems/peak-index-in-a-mountain-array/)

## Solution 1

```cpp
// Optimal Approach: Using Binary Search
// Time Complexity: O(logN)
// Space Complexity: O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // Edge Case 1: Nums contains only one element
        if(n == 1){
            return 0;
        }
        // Edge Case 2: Nums[-1] = -∞
        if(nums[0] > nums[1]){
            return 0;
        }
        // Edge Case 3: Nums[n] = -∞
        if(nums[n-1] > nums[n-2]){
            return n-1;
        }

        // Now apply the Binary Search
        // Me already nums[0] and nums[n-1] ko check kar chuka hu
        int start = 1;
        int end = n - 2;
        int mid = start + (end - start) / 2;
        while(start <= end){
            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]){
                // Found the peak index
                return mid;
            }
            else if(nums[mid] > nums[mid-1]){
                // Go to right side
                start = mid + 1;
            }
            else{
                // Go to left side
                end = mid - 1;
            }
            // Updating the mid
            mid = start + (end - start) / 2;
        }
        // when not found the peak index then return -1
        return -1;
    }
};
```
