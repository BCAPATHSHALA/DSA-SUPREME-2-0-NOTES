DATE: 08-03-2024

## Problem 21: [ Count Elements With Maximum Frequency (Leetcode-3005) ](https://leetcode.com/problems/count-elements-with-maximum-frequency)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

You are given an array `nums` consisting of positive integers.

Return the **total frequencies** of elements in `nums` such that those elements all have the **maximum** frequency.

The **frequency** of an element is the number of occurrences of that element in the array.

## Examples

Example 1:

```bash
Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.
```

Example 2:

```bash
Input: nums = [1,2,3,4,5]
Output: 5
Explanation: All elements of the array have a frequency of 1 which is the maximum.
So the number of elements in the array with maximum frequency is 5.
```

## Constraints:

1. `1 <= nums.length <= 100`
2. `1 <= nums[i] <= 100`

## Solution 1

```cpp
/*
Optimal Approach
Time Complexity:  O(N)
Space Complexity: O(N)
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Step 1: Store the frequency of each elements
        unordered_map<int,int> freq;
        for(auto i: nums){
            freq[i]++;
        }

        // Step 2: Get maximum frequency from freq map
        int maxFreq = INT_MIN;
        for(auto f: freq){
            maxFreq = max(maxFreq, f.second);
        }

        // Step 3: Get same maximum frequency count from freq map
        int count = 0;
        for(auto f: freq){
            if(maxFreq == f.second){
                count++;
            }
        }

        // Step 4: Return required ans
        int ans = count * maxFreq;
        return ans;
    }
};
```
