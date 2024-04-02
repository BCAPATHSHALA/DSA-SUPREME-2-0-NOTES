DATE: 02-04-2024

## Problem 40: [ Length of Last Word (Leetcode-58) ](https://leetcode.com/problems/length-of-last-word)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given a string `s` consisting of words and spaces, return the length of the **last** word in the string.

A **word** is a maximal _substring_ consisting of non-space characters only.

## Examples

Example 1:

```bash
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
```

Example 2:

```bash
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
```

Example 3:

```bash
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
```

## Constraints:

1. `1 <= s.length <= 10^4`
2. `s` consists of only English letters and spaces `' '`.
3. There will be at least one word in `s`.

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1

```cpp
// Optimal Approach
// Time Complexity: O(N)
// Space Complexity: O(1)
// Author: github.com/BCAPATHSHALA

class Solution {
public:
    int lengthOfLastWord(string s) {
        // Step 1: trim the string from end
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' '){
            i--;
        }

        // Step 2: get last word length
        int j = i;
        while (i >= 0 && s[i] != ' '){
            i--;
        }
        int lengthOfLastWord = j - i;
        return lengthOfLastWord;
    }
};
```
