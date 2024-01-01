DATE: 01-01-2024

## Problem 6: [Two Sum II - Input Array Is Sorted (Leetcode-167)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given a 1-indexed array of integers `numbers` that is already **sorted in non-decreasing order**, find two numbers such that they add up to a specific `target` number. Let these two numbers be `numbers[index1]` and `numbers[index2]` where `1 <= index1 < index2 <= numbers.length`.

Return the indices of the two numbers, `index1` and `index2`, added by one as an integer array `[index1, index2]` of length 2.

The tests are generated such that there is **exactly one solution**. You **may not** use the same element twice.

Your solution must use only constant extra space.

### Examples

Example 1:

```bash
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
```

Example 2:

```bash
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
```

Example 3:

```bash
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
```

Example 4:

```bash
Input: numbers = [5,25,75], target = 100
Output: [2,3]
```

### Constraints:

1.` 2 <= numbers.length <= 3 * 10^4` 2. `-1000 <= numbers[i] <= 1000` 3. `numbers` is sorted in non-decreasing order. 4. `-1000 <= target <= 1000` 5. The tests are generated such that there is **exactly one solution**.

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:

- [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
- [Two Sum IV - Input is a BST (Easy)](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)
- [Two Sum Less Than K (Easy)](https://leetcode.com/problems/two-sum-less-than-k/)

### Solution

```cpp
/*
Optimal Approach: Two Pointer
Time complexity: O(N)
Space complexity: O(1)
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int start = 0;
        int end = numbers.size()-1;

        while(numbers[start] + numbers[end] != target){

            // If our current sum is too large, move closer to the left
            if(numbers[start] + numbers[end] > target){
                end--;
            }
            // If our current sum is too small, move closer to the right
            else{
                start++;
            }
        }

        ans.push_back(start+1);
        ans.push_back(end+1);
        return ans;
    }
};
```
