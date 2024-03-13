DATE: 13-03-2024

## Problem 26: [ Find the Pivot Integer (Leetcode-2485) ](https://leetcode.com/problems/find-the-pivot-integer)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given a positive integer `n`, find the **pivot integer** `x` such that:

- The sum of all elements between `1` and `x` inclusively equals the sum of all elements between `x` and `n` inclusively.

Return the pivot integer `x`. If no such integer exists, return `-1`. It is guaranteed that there will be at most one pivot index for the given input.

## Examples

Example 1:

```bash
Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
```

Example 2:

```bash
Input: n = 1
Output: 1
Explanation: 1 is the pivot integer since: 1 = 1.
```

Example 3:

```bash
Input: n = 4
Output: -1
Explanation: It can be proved that no such integer exist.
```

## Constraints:

1. `1 <= n <= 1000`

**Companies**:
[Amazon](https://leetcode.com/company/amazon)
[Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:

- [Bulb Switcher (Medium)](https://leetcode.com/problems/bulb-switcher/)

## Solution 1

```cpp
/*
Optimal Approach
Time Complexity: O(N)
Space Complexity: O(1)
Author: github.com/BCAPATHSHALA
*/

class Solution {
public:
    int pivotInteger(int n) {
        int LSUM = 0;
        int RSUM = (n*(n+1))/2;

        for(int k=1; k<=n; k++){
            LSUM += k;
            RSUM -= k-1;
            if(LSUM == RSUM){
                return k;
            }
        }
        return -1;
    }
};
```
