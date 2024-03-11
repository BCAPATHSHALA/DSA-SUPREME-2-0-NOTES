DATE: 11-03-2024

## Problem 24: [ Custom Sort String (Leetcode-791) ](https://leetcode.com/problems/custom-sort-string)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

You are given two strings `order` and `s`. All the characters of `order` are **unique** and were sorted in some custom order previously.

Permute the characters of `s` so that they match the order that `order` was sorted. More specifically, if a character `x` occurs before a character `y` in `order`, then `x` should occur before `y` in the permuted string.

Return any permutation of `s` that satisfies this property.

## Examples

Example 1:

```bash
Input:  order = "cba", s = "abcd"
Output:  "cbad"
Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
```

Example 2:

```bash
Input:  order = "bcafg", s = "abcd"
Output:  "bcad"
Explanation: The characters "b", "c", and "a" from order dictate the order for the characters in s. The character "d" in s does not appear in order, so its position is flexible.

Following the order of appearance in order, "b", "c", and "a" from s should be arranged as "b", "c", "a". "d" can be placed at any position since it's not in order. The output "bcad" correctly follows this rule. Other arrangements like "bacd" or "bcda" would also be valid, as long as "b", "c", "a" maintain their order.
```

## Constraints:

1. `1 <= order.length <= 26`
2. `1 <= s.length <= 200`
3. `order` and `s` consist of lowercase English letters.
4. All the characters of `order` are **unique**.

**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1

```cpp
/*
Time Complexity: O(L) + O(NlogN)
Space Complexity: O(1)
Author: github.com/BCAPATHSHALA

where
L is the length of the string order
N is a length of string s
*/

class Solution {
public:
    // Step 02: in custom comparator, find character's position of s string in string order
    static string orderStr;
    static bool compare(char ch1, char ch2){
        int a = orderStr.find(ch1);
        int b = orderStr.find(ch2);
        return a < b;
    }

    string customSortString(string order, string s) {

        orderStr = order;

        // Step 01: Use custom comparator to arrange character of string s according to string order
        sort(s.begin(), s.end(), compare);

        // Step 03: Return arranged string s
        return s;
    }
};
string Solution::orderStr;
```
