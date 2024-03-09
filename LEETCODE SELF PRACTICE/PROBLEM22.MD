DATE: 09-03-2024

## Problem 22: [ Minimum Common Value(Leetcode-2540) ](https://leetcode.com/problems/minimum-common-value)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, return the **minimum integer common** to both arrays. If there is no common integer amongst `nums1` and `nums2`, return `-1`.

Note that an integer is said to be **common** to `nums1` and `nums2` if both arrays have **at least one** occurrence of that integer.

## Examples

Example 1:

```bash
Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.
```

Example 2:

```bash
Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.
```

Example 3:

```bash
Input: nums1 = [1,2,3], nums2 = [4,5,6]
Output: -1
```
## Constraints:

1. `1 <= nums1.length, nums2.length <= 10^5`
2. `1 <= nums1[i], nums2[j] <= 10^9`
3. Both `nums1` and `nums2` are sorted in **non-decreasing** order.

**Companies**:
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Intersection of Two Arrays (Easy)](https://leetcode.com/problems/intersection-of-two-arrays/)
* [Intersection of Two Arrays II (Easy)](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

## Solution 1

```cpp
/*
Optimal Approach: Using Two Pointer
Time Complexity: O(min(n, m))
Space Complexity: O(min(n, m))
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Step 1: create array to store the common value
        vector<int> interSectionArray;
        int minValue = INT_MAX;

        // Step 2: Apply two pointer approach to store the common element
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                interSectionArray.push_back(nums1[i]);
                minValue = min(minValue, nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
        }

        // Step 3: return required ans
        if(minValue == INT_MAX){
            // Does not have any common element
            return -1;
        }
        else{
            // Does have at least common element
            return minValue;
        }
    }
};
```

## Solution 2

```cpp
/*
Optimal Approach: Using Two Pointer
Time Complexity: O(min(n, m))
Space Complexity: O(1)
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                return nums1[i];
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
        }
        return -1;
    }
};

```
