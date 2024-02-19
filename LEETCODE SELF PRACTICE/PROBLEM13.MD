DATE: 19-02-2024

## Problem 13: [ Power of Two (Leetcode-231) ](https://leetcode.com/problems/power-of-two/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given an integer `n`, return `true` if it is a power of two. Otherwise, return `false`.

An integer `n` is a power of two, if there exists an integer `x` such that` n == 2^x`.


## Examples

- Example 1:

```bash
Input: n = 1
Output: true
Explanation: 20 = 1
```

Example 2:

```bash
Input: n = 16
Output: true
Explanation: 24 = 16
```

Example 3:

```bash
Input: n = 3
Output: false
```
Example 4:

```bash
Input: n = 6
Output: false
```

## Constraints:

Constraints:

1. `-2^31 <= n <= 2^(31) - 1`

**Follow up:** Could you solve it without `loops`/`recursion`?

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Snapchat](https://leetcode.com/company/snapchat), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Number of 1 Bits (Easy)](https://leetcode.com/problems/number-of-1-bits/)
* [Power of Three (Easy)](https://leetcode.com/problems/power-of-three/)
* [Power of Four (Easy)](https://leetcode.com/problems/power-of-four/)

## Solution 1

```cpp
/*
Brute force approach: Using Reminder-divident method
Time Complexity: O(logN)
Space Complexity: O(1)
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) {
            return false;
        }
        while(n%2==0) {
            n/=2;
        }
        return n==1;
    }
};

```

## Solution 2

```cpp
/*
Optimal approach: Using Bit manipulation
Time Complexity: O(1)
Space Complexity: O(1)
Author: github.com/BCAPATHSHALA
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) {
            return false;
        }
        return ((n&(n-1))==0);
    }
};

/*
Now consider :-
bit representation of 7  -> 0111
bit representation of 8  -> 1000
bitwise AND of 7 and 8 -> 0000
we are gonna use this property for for all numbers which are powers of two
*/
```
