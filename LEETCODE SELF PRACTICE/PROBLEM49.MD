DATE: 05-11-2024

## Problem 49: [ Minimum Number of Changes to Make Binary String Beautiful (Leetcode-2914) ](https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful)

## Solution 1

```cpp
// Optimal Approach
// Time Complexity: O(N)
// Space Complexity: O(1)
// Author: github.com/BCAPATHSHALA

class Solution {
public:
    int minChanges(string s) {
        int minCount = 0;
        for(int i = 0; i < s.size() - 1; i += 2){
            if(s[i] != s[i + 1]){
                minCount++;
            }
        }
        return minCount;
    }
};
```

![Leetcode-2914]()
