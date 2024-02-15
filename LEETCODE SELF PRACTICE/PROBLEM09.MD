DATE: 15-02-2024

## Problem 9: [Find Polygon With the Largest Perimeter (Leetcode-2971)](https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

You are given an array of **positive** integers `nums` of length `n`.

A polygon is a closed plane figure that has at least `3` sides. The **longest side** of a polygon is **smaller** than the sum of its other sides.

Conversely, if you have `k` (`k >= 3`) positive real numbers `a1`, `a2`, `a3`, ..., `ak` where `a1 <= a2 <= a3 <= ... <= ak` and `a1 + a2 + a3 + ... + ak-1 > ak`, then there always exists a polygon with `k` sides whose lengths are `a1, a2, a3, ..., ak`.

The **perimeter** of a polygon is the sum of lengths of its sides.

Return the **largest** possible **perimeter** of a **polygon** whose sides can be formed from `nums`, or `-1` if it is not possible to create a polygon.

### Examples

Example 1:

```bash
Input: nums = [5,5,5]
Output: 15
Explanation: The only possible polygon that can be made from nums has 3 sides: 5, 5, and 5. The perimeter is 5 + 5 + 5 = 15.
```

Example 2:

```bash
Input: nums = [1,12,1,2,5,50,3]
Output: 12
Explanation: The polygon with the largest perimeter which can be made from nums has 5 sides: 1, 1, 2, 3, and 5. The perimeter is 1 + 1 + 2 + 3 + 5 = 12.
We cannot have a polygon with either 12 or 50 as the longest side because it is not possible to include 2 or more smaller sides that have a greater sum than either of them.
It can be shown that the largest possible perimeter is 12.
```

Example 3:

```bash
Input: nums = [5,5,50]
Output: -1
Explanation: There is no possible way to form a polygon from nums, as a polygon has at least 3 sides and 50 > 5 + 5.
```

### Constraints:

1. `3 <= n <= 10^5`
2. `1 <= nums[i] <= 10^9`

**Similar Questions**:

- [Valid Triangle Number (Medium)](https://leetcode.com/problems/valid-triangle-number/)

### Solution 1

```cpp
/*
Approach 1( With Backward Iteration):
Time complexity: O(N Log N)
Space complexity: O(1)
Author: github.com/BCAPATHSHALA
*/


class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        // Step1: Sort the array first
        sort(nums.begin(),nums.end());

        // Step2: Sum all the elements in the nums array
        long long sum = 0;
        for(auto i : nums) {
            sum += i;
        }

        // Step3: Traverse the array backwards
        int n = nums.size();
        for(int i = n - 1; i >= 2; i--){
            // Step4: Check if the sum minus the current element is greater than the current element
            sum -= nums[i];

            // Step5: If the condition is met, return the sum plus the current element as the perimeter
            if(sum > nums[i]){
                return sum + nums[i];
            }
        }
        // Step6: If no suitable perimeter is found, return -1
        return -1;
    }
};


```
