DATE: 14-02-2024

## Problem 8: [Rearrange Array Elements by Sign (Leetcode-2149)](https://leetcode.com/problems/rearrange-array-elements-by-sign/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

You are given a **0-indexed** integer array `nums` of **even** length consisting of an equal number of positive and negative integers.

You should **rearrange** the elements of `nums` such that the modified array follows the given conditions:

1. Every **consecutive pair** of integers have **opposite signs**.
2. For all integers with the same sign, the **order** in which they were present in `nums` is **preserved**.
3. The rearranged array begins with a positive integer.

Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

### Examples

Example 1:

```bash
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.
```

Example 2:

```bash
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

Example 3:

```bash
Input: nums = [-1,1]
Output: [1,-1]
Explanation:
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].
```

### Constraints:

1. `2 <= nums.length <= 2 * 10^5`
2. `nums.length` is even
3. `1 <= |nums[i]| <= 10^5`
4. `nums` consists of equal number of positive and negative integers.

**Similar Questions**:

- [Wiggle Subsequence (Medium)](https://leetcode.com/problems/wiggle-subsequence/)
- [Sort Array By Parity II (Easy)](https://leetcode.com/problems/sort-array-by-parity-ii/)

### Solution 1

```cpp
/*
Brute Force Approach:
Time complexity: O(N)
Space complexity: O(N)
Author: github.com/BCAPATHSHALA
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        // Store negative and positive integer
        // from input array to posV and negV separately
        vector<int> posV, negV, ansV;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                posV.push_back(nums[i]);
            }
            else{
                negV.push_back(nums[i]);
            }
        }

        // Now storing the positive and negative integer
        // from posV and negV to ansV one by one
        int evenIn=0, oddIn=0;
        while(oddIn < nums.size()/2){
            ansV.push_back(posV[evenIn]);
            evenIn++;
            ansV.push_back(negV[oddIn]);
            oddIn++;
        }

        // Return final ans
        return ansV;
    }
};

```

### Solution 2

```cpp
/*
Optimal Approach
Time complexity: O(N)
Space complexity: O(N)
Author: github.com/BCAPATHSHALA
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Size of nums
        int size=nums.size();

        // Create new vector array
        vector<int> ans(size,0);

        // Create positive index and negative index
        int posIndex=0;
        int negIndex=1;

        // Iterate the entire array
        for(int index=0;index<size;index++){
            // When element is positive then use even index in ans
            if(nums[index]>0){
                ans[posIndex]=nums[index];
                posIndex+=2;
            }
            // When element is negative then use odd index in ans
            else{
                ans[negIndex]=nums[index];
                negIndex+=2;
            }
        }

        // Return new array
        return ans;
    }
};
```
