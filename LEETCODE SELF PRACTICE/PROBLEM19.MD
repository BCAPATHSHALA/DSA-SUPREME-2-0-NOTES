DATE: 02-03-2024

## Problem 19: [ Squares of a Sorted Array (Leetcode-977) ](https://leetcode.com/problems/squares-of-a-sorted-array)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given an integer array `nums` sorted in **non-decreasing** order, return an array of **the squares of each number** sorted in non-decreasing order.

## Examples

Example 1:

```bash
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
```

Example 2:

```bash
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

## Constraints:

1. `1 <= nums.length <= 10^4`
2. `-10^4 <= nums[i] <= 10^4`
3. `nums` is sorted in **non-decreasing** order.

**Follow up:** Squaring each element and sorting the new array is very trivial, could you find an `O(n)` solution using a different approach?

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:

- [Merge Sorted Array (Easy)](https://leetcode.com/problems/merge-sorted-array/)
- [Sort Transformed Array (Medium)](https://leetcode.com/problems/sort-transformed-array/)

## Solution 1

```cpp
/*
Brute force approach
Time Complexity:  O(NLogN)
Space Complexity: O(N)
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squares(nums.size());

        // Square each element in 'nums'
        for (int i = 0; i < nums.size(); ++i) {
            squares[i] = nums[i] * nums[i];
        }

        // Sort the squared values
        sort(squares.begin(), squares.end());

        // Return the sorted squares
        return squares;
    }
};
```

## Solution 2

```cpp
/*
Optimal approach: Using Two Pointer
Time Complexity:  O(N)
Space Complexity: O(N)
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // Square each element in 'nums'
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = nums[i] * nums[i];
        }

        // Sort the squared values
        vector<int> squares(nums.size());
        int start = 0;
        int end = nums.size()-1;
        int k = nums.size()-1;
        while(start <= end){
            if(nums[start] > nums[end]){
                squares[k--] = nums[start];
                start++;
            }
            else{
                squares[k--] = nums[end];
                end--;
            }
        }

        // Return the sorted squares
        return squares;
    }
};
```
