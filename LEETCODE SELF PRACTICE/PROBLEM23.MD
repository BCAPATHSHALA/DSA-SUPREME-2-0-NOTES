DATE: 10-03-2024

## Problem 23: [ Intersection of Two Arrays (Leetcode-349) ](https://leetcode.com/problems/intersection-of-two-arrays)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given two integer arrays `nums1` and `nums2`, return an array of their intersection. Each element in the result must be **unique** and you may return the result in **any order**.

## Examples

Example 1:

```bash
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
```

Example 2:

```bash
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
```

## Constraints:

1. `1 <= nums1.length, nums2.length <= 1000`
2. `0 <= nums1[i], nums2[i] <= 1000`

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg), [Apple](https://leetcode.com/company/apple), [LinkedIn](https://leetcode.com/company/linkedin), [VMware](https://leetcode.com/company/vmware)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:

- [Intersection of Two Arrays II (Easy)](https://leetcode.com/problems/intersection-of-two-arrays-ii/)
- [Intersection of Three Sorted Arrays (Easy)](https://leetcode.com/problems/intersection-of-three-sorted-arrays/)

## Solution 1

```cpp
/*
Optimal Approach: Using Sort + Two Pointer
Time Complexity: O(min(nlogn, mlogm))
Space Complexity: O(1)
Author: github.com/BCAPATHSHALA
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // Step 1: create array to store the common value
        vector<int> interSectionArray;

        // Step 2: Apply two pointer approach to store the common element
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                interSectionArray.push_back(nums1[i]);

                while (i < nums1.size() - 1 && nums1[i] == nums1[i + 1]) {
                    // remove duplicate from nums1
                    i++;
                }
                while (j < nums2.size() - 1 && nums2[j] == nums2[j + 1]) {
                    // remove duplicate from nums2
                    j++;
                }
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            }
        }

        // Step 3: return required ans
        return interSectionArray;
    }
};
```
