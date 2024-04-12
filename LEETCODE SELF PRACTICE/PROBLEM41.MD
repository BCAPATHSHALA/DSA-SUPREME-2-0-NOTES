DATE: 12-04-2024

## Problem 41: [ Remove K Digits (Leetcode-402) ](https://leetcode.com/problems/remove-k-digits/description/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given string `num` representing a non-negative integer `num`, and an integer `k`, return the smallest possible integer after removing `k` digits from `num`.

## Examples

Example 1:

```bash
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
```

Example 2:

```bash
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
```

Example 3:

```bash
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
```

## Constraints:

1. `1 <= k <= num.length <= 10^5`
2. `num` consists of only digits.
3. `num` does not have any leading zeros except for the zero itself.

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Adobe](https://leetcode.com/company/adobe), [MakeMyTrip](https://leetcode.com/company/makemytrip)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack/)

**Similar Questions**:

- [Create Maximum Number (Hard)](https://leetcode.com/problems/create-maximum-number/)
- [Monotone Increasing Digits (Medium)](https://leetcode.com/problems/monotone-increasing-digits/)
- [Find the Most Competitive Subsequence (Medium)](https://leetcode.com/problems/find-the-most-competitive-subsequence/)
- [Minimum Operations to Make a Special Number (Medium)](https://leetcode.com/problems/minimum-operations-to-make-a-special-number/)
- [Remove Digit From Number to Maximize Result (Easy)](https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/description/)
- [Append K Integers With Minimal Sum (Medium)](https://leetcode.com/problems/append-k-integers-with-minimal-sum/description/)

## Solution 1

```cpp
// Optimal Approach
// Time Complexity: O(N)
// Space Complexity: O(N)
// Author: github.com/BCAPATHSHALA

class Solution {
public:
    string removeKdigits(std::string num, int k) {
        // initial state
        stack<char> stack;

        for (char digit : num) {
            // Case 1: Remove k elements from left
            while (!stack.empty() && k > 0 && stack.top() > digit) {
                stack.pop();
                k--;
            }
            stack.push(digit);
        }

        // Case 2: Remove k elements from the right
        while (k > 0 && !stack.empty()) {
            stack.pop();
            k--;
        }

        // Getting  intend output from the stack
        string tempAns;
        while (!stack.empty()) {
            tempAns += stack.top();
            stack.pop();
        }

        // Reverse ans to get the correct order
        reverse(tempAns.begin(), tempAns.end());

        // Case 3: remove leading zeros from tempAns string
        int nSize = tempAns.size();
        string result = "";
        int markingAsNonZero = 0;

        for(int i = 0; i < nSize; i++){
            if(tempAns[i] == '0' && markingAsNonZero == 0){
                continue;
            }
            else{
                result.push_back(tempAns[i]);
                markingAsNonZero = 1;
            }
        }

        // Case 4: If the result is empty, return "0"
        return result.size() == 0 ? "0" : result;
    }
};
```
