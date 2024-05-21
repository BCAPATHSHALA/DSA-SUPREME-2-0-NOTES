DATE: 21-05-2024

## Problem 44: [ Subsets (Leetcode-78) ](https://leetcode.com/problems/subsets)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given an integer array `nums` of _*unique*_ elements, return all possible subsets _*(the power set)*_.

The solution set **must not** contain duplicate subsets. Return the solution in any order.

## Examples

Example 1:

```bash
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

Example 2:

```bash
Input: nums = [0]
Output: [[],[0]]
```

## Constraints:

1. `1 <= nums.length <= 10`
2. `-10 <= nums[i] <= 10`
3. All the numbers of nums are `unique`.

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Subsets II (Medium)](https://leetcode.com/problems/subsets-ii/)
* [Generalized Abbreviation (Medium)](https://leetcode.com/problems/generalized-abbreviation/)
* [Letter Case Permutation (Medium)](https://leetcode.com/problems/letter-case-permutation/)
* [Find Array Given Subset Sums (Hard)](https://leetcode.com/problems/find-array-given-subset-sums/)
* [Count Number of Maximum Bitwise-OR Subsets (Medium)](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/)

## Solution 1

```cpp
// Using Bit Manipulation
// Time Complexity: O(2^N * N)
// Space Complexity: O(2^N * N)
// Author: github.com/BCAPATHSHALA

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        // Step 1: traverse for 2^n times
        int powerSet = 1 << n;
        for(int num = 0; num < powerSet; num++){
            vector<int> subsequence;

            // Step 2: traverse for each num for n times
            for(int index = 0; index < n; index++){
                int singleNum = nums[index];
                
                // Step 3: check set bit for each index in num
                int mask = 1<<index;
                if(num & mask){
                    // Create a subsequence
                    subsequence.push_back(singleNum);
                }
            }
            // Step 4: Store the subsequence to the vector
            ans.push_back(subsequence);
        }
        return ans;
    }
};
```
