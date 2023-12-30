DATE: 30-12-2023

## Problem 5: [Unique Number of Occurrences (Leetcode-1207)](https://leetcode.com/problems/unique-number-of-occurrences/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given an array of integers `arr`, return `true` if the number of occurrences of each value in the array is **unique** or `false` otherwise.

### Examples

Example 1:

```bash
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
```

Example 2:

```bash
Input: arr = [1,2]
Output: false
```

Example 3:

```bash
Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
```

### Constraints:

1. `1 <= arr.length <= 1000`
2. `-1000 <= arr[i] <= 1000`

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)
[Array](https://leetcode.com/tag/array/)

### Solution

```cpp
/*
Optimal Approach
Time complexity: O(N+M) = O(N)
Space complexity: O(N)
where N is number of elements in input array, and M is the number of unique frequencies in the map.

Note 1: In the worst case, where all elements are unique, the space complexity can be O(n) for unordered_map
Note 2: In the worst case, where all frequencies are unique, the space complexity can be O(n) for unordered_set

Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        // Step 1: Frequency Counting using map
        unordered_map<int,int>mp;
        for(auto it:arr){
            mp[it]++;
        }

        // Step 2: Checking for Unique Frequencies
        unordered_set<int>st;
        for(auto it:mp){
            auto temp=st.emplace(it.second);
            if(!temp.second){
                return false;
            }
        }
        return true;
    }
};

/*
In set Data Structure, emplace() method return a pair to newly inserted unique elemet and a value of true otherwise false
Resource: https://cplusplus.com/reference/set/set/
*/
```
