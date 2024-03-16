DATE: 15-03-2024

## Problem 27: [ Product of Array Except Self (Leetcode-238) ](https://leetcode.com/problems/product-of-array-except-self)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.

## Examples

Example 1:

```bash
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
```

Example 2:

```bash
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
```

Example 3:

```bash
Input: nums = [-1,2,3,4]
Output: [24,-12,-8,-6]
```

## Constraints:

1. `2 <= nums.length <= 10^5`
2. `-30 <= nums[i] <= 30`
3. The product of any prefix or suffix of nums is **guaranteed** to fit in a **32-bit** integer.

**Follow up:** Can you solve the problem in `O(1)` extra space complexity? (The output array **does not** count as extra space for space complexity analysis.)

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft), [Asana](https://leetcode.com/company/asana), [Adobe](https://leetcode.com/company/adobe), [Nutanix](https://leetcode.com/company/nutanix), [Lyft](https://leetcode.com/company/lyft), [Nvidia](https://leetcode.com/company/nvidia), [Intel](https://leetcode.com/company/intel), [VMware](https://leetcode.com/company/vmware)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:

- [Trapping Rain Water (Hard)](https://leetcode.com/problems/trapping-rain-water/)
- [Maximum Product Subarray (Medium)](https://leetcode.com/problems/maximum-product-subarray/)
- [Paint House II (Hard)](https://leetcode.com/problems/paint-house-ii/)

## Solution 1

```cpp
// Optimal Approach: Prefix and suffix technique
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // Step 1: Create two arrays, prefix and suffix to hold the product of elements
        // before and after each index in nums
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        // Step 2: Calculate the prefix products
        for(int index = 1; index < n; index++){
            prefix[index] = prefix[index - 1] * nums[index - 1];
        }

        // Step 3: Calculate the suffix products
        for(int index = n-2; index >= 0; index--){
            suffix[index] = suffix[index + 1] * nums[index + 1];
        }

        // Step 4: Multiply the corresponding prefix and suffix products
        // for each index to get the final result
        vector<int> answer(n);
        for (int index = 0; index < n; index++) {
            answer[index] = prefix[index] * suffix[index];
        }
        return answer;
    }
};
```

## Solution 2

```cpp
// Optimal Approach: Prefix and suffix technique
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // Create prefix as answer to hold the product of elements
        // before each index in nums
        vector<int> prefix(n, 1);

        // Calculate the prefix products
        for(int index = 1; index < n; index++){
            prefix[index] = prefix[index - 1] * nums[index - 1];
        }

        // Create suffix variable as product of elements
        // after each index in nums
        int suffix = 1;

        // Traverse on entire arrays nums & prefix from end of nums
        for (int index = n-1; index >= 0; index--) {
            prefix[index] = prefix[index] * suffix;
            // Calculate the suffix products
            suffix = suffix * nums[index];
        }
        return prefix;
    }
};
```
