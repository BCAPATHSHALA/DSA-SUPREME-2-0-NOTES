DATE: 16-02-2024

## Problem 10: [Least Number of Unique Integers after K Removals (Leetcode-1481)](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given an array of integers `arr` and an integer `k`. Find the least number of unique integers after removing **exactly** `k` elements.

## Examples

Example 1:

```bash
Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
```

Example 2:

```bash
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
```

## Constraints:

1. `1 <= arr.length <= 10^5`
2. `1 <= arr[i] <= 10^9`
3. `0 <= k <= arr.length`

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sort](https://leetcode.com/tag/sort/)


## Intuition
- First, I want to remove the least frequency element one by one till the **Kth** time to get the least number of unique elements from the input array.

### Approach
- Step 1: store the frequency of each unique element
- Step 2: sort the map according to frequencies
- Step 3: apply logic to get the least number of unique element

### Complexity
- Time complexity: O(N Log(N))
- Space complexity: O(N)

## Solution 1

```cpp
/*
Optimal Approach:
Time complexity: O(N Log N)
Space complexity: O(N)
Author: github.com/BCAPATHSHALA
*/


class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int size = arr.size();
        // Step 1: store the frequency of each unique element
        unordered_map<int,int> freqMap;
        for(auto i: arr){
            freqMap[i]++;
        }

        // Step 2: sort the map according to frequencies
        vector<int> storeFreq;
        for(auto value: freqMap){
            storeFreq.push_back(value.second);
        }
        sort(storeFreq.begin(), storeFreq.end());

        // Step 3: apply logic to get the least number of unique element
        int unique = 0;
        int temp = k;
        for(auto value: storeFreq){
            if((temp-value) < 0){
                unique++;
            }
            else if((temp-value) >= 0){
                temp = temp - value;
            }
        }
        return unique;
    }
};
```
