DATE: 27-05-2024

## Problem 45: [ Special Array With X Elements Greater Than or Equal X (Leetcode-1605) ](https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

You are given an array `nums` of non-negative integers. `nums` is considered **special** if there exists a number `x` such that there are **exactly** `x` numbers in `nums` that are **greater than or equal to** `x`.

**Notice** that `x` **does not** have to be an element in `nums`.

Return `x` if the array is **special**, otherwise, return `-1`. It can be proven that if `nums` is special, the value for `x` is **unique**.

## Examples

Example 1:

```bash
Input: nums = [3,5]
Output: 2
Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.
```

Example 2:

```bash
Input: nums = [0,0]
Output: -1
Explanation: No numbers fit the criteria for x.
If x = 0, there should be 0 numbers >= x, but there are 2.
If x = 1, there should be 1 number >= x, but there are 0.
If x = 2, there should be 2 numbers >= x, but there are 0.
x cannot be greater since there are only 2 numbers in nums.
```

Example 3:

```bash
Input: nums = [0,4,3,0,4]
Output: 3
Explanation: There are 3 values that are greater than or equal to 3.
```

Example 4:

```bash
Input: nums = [4,4,3,4,4]
Output: 4
Explanation: There are 4 values that are greater than or equal to 4.
```

Example 5:

```bash
Input: nums = [4,4,4,4,4]
Output: -1
```

Example 6:

```bash
Input: nums = [4,4,4,4]
Output: 4
```

## Constraints:

1. `1 <= nums.length <= 100`
2. `0 <= nums[i] <= 1000`

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)


## Solution 1

```cpp
// Brute Force Approach
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// Author: github.com/BCAPATHSHALA

class Solution {
public:
    
    int specialArray(vector<int>& nums) {
        int count = 0;
        for(int x = 0; x <= nums.size(); x++){
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] >= x){
                    count++;
                }
            }
            if(count == x){
                return x;
            }
            count = 0;
        }
        return -1;
    }
};
```
