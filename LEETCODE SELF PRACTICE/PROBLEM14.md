DATE: 20-02-2024

## Problem 14: [ Missing Number (Leetcode-268) ](https://leetcode.com/problems/missing-number/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

## Examples

Example 1:

```bash
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
```

Example 2:

```bash
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
```

Example 3:

```bash
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
```

## Constraints:

1. `n == nums.length`
2. `1 <= n <= 10^4`
3. `0 <= nums[i] <= n`
4. All the numbers of `nums` are **unique**.

**Follow up:** Could you implement a solution using only `O(1)` extra space complexity and `O(n)` runtime complexity?

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:

- [First Missing Positive (Hard)](https://leetcode.com/problems/first-missing-positive/)
- [Single Number (Easy)](https://leetcode.com/problems/single-number/)
- [Find the Duplicate Number (Medium)](https://leetcode.com/problems/find-the-duplicate-number/)
- [Couples Holding Hands (Hard)](https://leetcode.com/problems/couples-holding-hands/)

## Solution 1

```cpp
/*
Brute force approach: Sorting
Time Complexity: O(NlogN)
Space Complexity: O(1)
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    int sortingApproach(vector<int>& nums){
        int n=nums.size();
        // sort
        sort(nums.begin(), nums.end());

        // compare
        for(int i=0;i<n;i++){
            if(nums[i]==i){
                continue;
            }
            else{
                return i;
            }
        }
        return n;
    }

    int missingNumber(vector<int>& nums) {
        return sortingApproach(nums);
    }
};

```

## Solution 2

```cpp
/*
Optimal approach: Mathematical Formula
Time Complexity: O(N)
Space Complexity: O(1)
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    int totalSum(vector<int>& nums){
        int n=nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        int totalSum=(n*(n+1))/2;
        int missingNum=totalSum-sum;

        return missingNum;
    }

    int missingNumber(vector<int>& nums) {
        return totalSum(nums);
    }
};

```

## Solution 3

```cpp
/*
Optimal approach: Bit Manipulation (XOR)
Time Complexity: O(n)
Space Complexity: O(1)
Author: github.com/BCAPATHSHALA
*/

class Solution {
public:
    int xorApproach(vector<int>& nums){
        int n=nums.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            ans = ans ^ nums[i];
        }

        for(int i=0; i<=n; i++){
            ans = ans ^ i;
        }

        return ans;
    }

    int missingNumber(vector<int>& nums) {
        return xorApproach(nums);
    }
};
```
