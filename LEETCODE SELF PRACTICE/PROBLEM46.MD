DATE: 01-06-2024

## Problem 46: [ Score of a String (Leetcode-3110) ](https://leetcode.com/problems/score-of-a-string)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

You are given a string `s`. The **score** of a string is defined as the sum of the absolute difference between the **ASCII** values of adjacent characters.

Return the **score** of `s`.

## Examples

Example 1:

```bash
Input: s = "hello"

Output: 13

Explanation:

The ASCII values of the characters in s are: 'h' = 104, 'e' = 101, 'l' = 108, 'o' = 111. So, the score of s would be |104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13.
```

Example 2:

```bash
Input: s = "zaz"

Output: 50

Explanation:

The ASCII values of the characters in s are: 'z' = 122, 'a' = 97. So, the score of s would be |122 - 97| + |97 - 122| = 25 + 25 = 50.
```

## Constraints:

1. `2 <= s.length <= 100`
2. `s` consists only of lowercase English letters.

**Related Topics**:  
[Array](https://leetcode.com/tag/string/)

## Solution 1

```cpp
// Optimal Approach
// Time Complexity: O(N)
// Space Complexity: O(1)
// Author: github.com/BCAPATHSHALA

class Solution {
public:
    int scoreOfString(string s) {
        int totalScore = 0;
        int n = s.size(), i = 0;

        while(i < (n - 1)){
            totalScore += abs(s[i] - s[i + 1]);
            i++;
        }
        return totalScore;
    }
};
```
