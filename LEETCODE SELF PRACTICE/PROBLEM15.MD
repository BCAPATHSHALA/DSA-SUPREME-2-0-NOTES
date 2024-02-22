DATE: 21-02-2024

## Problem 15: [ Bitwise AND of Numbers Range (Leetcode-201) ](https://leetcode.com/problems/bitwise-and-of-numbers-range/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given two integers `left` and `right` that represent the range `[left, right]`, return the bitwise **AND** of all numbers in this range, **inclusive**.

## Examples

Example 1:

```bash
Input: left = 5, right = 7
Output: 4
```

Example 2:

```bash
Input: left = 0, right = 0
Output: 0
```

Example 3:

```bash
Input: left = 1, right = 2147483647
Output: 0
```

## Constraints:

1. `0 <= left <= right <= 2^31 - 1`

**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1

```cpp
/*
Optimal approach: Using Bitwise
Time Complexity: O(1)
Space Complexity: O(1)
Author: github.com/BCAPATHSHALA
*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        while(left != right){
            left = left >> 1;
            right = right >> 1;
            count++;
        }
        return right << count;
    }
};

```
