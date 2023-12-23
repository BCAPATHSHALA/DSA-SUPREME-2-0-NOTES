DATE: 23-12-2023 
## Problem: [Merge Sorted Array (Leetcode-88)](https://leetcode.com/problems/merge-sorted-array/)

You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

Merge `nums1` and `nums2` into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array `nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to 0 and should be ignored. `nums2` has a length of `n`.

### Examples
Example 1:
```bash
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
```
Example 2:
```bash
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
```
Example 3:
```bash
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
```

### Constraints:

1. `nums1.length == m + n`
2. `nums2.length == n`
3. `0 <= m, n <= 200`
4. `1 <= m + n <= 200`
5. `-10^9 <= nums1[i], nums2[j] <= 10^9`

Follow up: Can you come up with an algorithm that runs in `O(m + n)` time?

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Sorting](https://leetcode.com/tag/sorting/)

### Solution 1

```cpp
/* 
Approach: Two Pointer
Time Complexity: O(M+N)
Space Complexity: O(1)
Author: github.com/BCAPATHSHALA
*/

class Solution {
public:
    void twoPointerApproach(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(j >= 0){
            if(i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else 
            {
                nums1[k--] = nums2[j--];
            }
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Approach: Two Pointer
        twoPointerApproach(nums1, m, nums2, n);
    }
};
```


### Solution 2

```cpp
/* 
Approach : Using STL
Time Complexity: O((M+N)log(M+N))
Space Complexity: O(1)
Author: github.com/BCAPATHSHALA
*/

class Solution {
public:
    void usingSTL(vector<int>& nums1, int m, vector<int>& nums2, int n){
        for(int i = m, j = 0; j < n; j++, i++){
            nums1[i] = nums2[j];
        }
        sort(nums1.begin(),nums1.end());
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Approach : Using STL
        usingSTL(nums1, m, nums2, n);
    }
};
```
