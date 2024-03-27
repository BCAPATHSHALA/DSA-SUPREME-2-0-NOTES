DATE: 26-03-2024

## Problem 34: [ First Missing Positive (Leetcode-41) ](https://leetcode.com/problems/first-missing-positive)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given an unsorted integer array `nums`. Return the smallest positive integer that is not present in `nums`.

You must implement an algorithm that runs in `O(n)` time and uses `O(1)` auxiliary space.

## Examples

Example 1:

```bash
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
```

Example 2:

```bash
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
```

Example 3:

```bash
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
```

## Constraints:

1. `1 <= nums.length <= 10^5`
2. `-2^31 <= nums[i] <= 2^31 - 1`

**Companies**:

- [Amazon](https://leetcode.com/company/amazon)
- [Microsoft](https://leetcode.com/company/microsoft)
- [Netflix](https://leetcode.com/company/netflix)
- [Apple](https://leetcode.com/company/apple)
- [MakeMyTrip](https://leetcode.com/company/makemytrip)
- [Google](https://leetcode.com/company/google)
- [Adobe](https://leetcode.com/company/adobe)
- [Facebook](https://leetcode.com/company/facebook)
- [Morgan Stanley](https://leetcode.com/company/morgan-stanley)
- [IBM](https://leetcode.com/company/ibm)
- [Salesforce](https://leetcode.com/company/salesforce)
- [Walmart Labs](https://leetcode.com/company/walmart-labs)
- [Byte Dance](https://leetcode.com/company/byte-dance)
- [De Shaw](https://leetcode.com/company/de-shaw)
- [TikTok](https://leetcode.com/company/tiktok)
- [Snapdeal](https://leetcode.com/company/snapdeal)
- [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/) [Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:

- [Missing Number (Easy)](https://leetcode.com/problems/missing-number/)
- [Find the Duplicate Number (Medium)](https://leetcode.com/problems/find-the-duplicate-number/)
- [Find All Numbers Disappeared in an Array (Easy)](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
- [Couples Holding Hands (Hard)](https://leetcode.com/problems/couples-holding-hands/)

## Solution 1

```cpp
// Optimal Approach: Pigeonhole Principal inplace
// Time Complexity: O(N)
// Space Complexity: O(1)
// Author: github.com/BCAPATHSHALA

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // Step 1: Modifify the input array's value with new value n+1
        for(int i=0; i<n; i++){
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = n+1;
            }
        }

        // Step 2: Marking the modified array as visited
        // If -ve value => marked seat (visited)
        // If +ve value => vacant seat (not visited)
        for(int i=0; i<n; i++){
            int seatIndexElement = abs(nums[i]);
            if( seatIndexElement == n+1){
                // Overflow index
                continue;
            }

            int seatIndex = seatIndexElement - 1;
            if(nums[seatIndex] > 0){
                // Edge case: for duplicate element
                nums[seatIndex] *= -1;
            }
        }

        // Step 3: Find first missing positive seatIndex from marked array
        int candidate = n+1;
        for(int i=0; i<n; i++){
            if(nums[i] >= 0){
                candidate = i + 1;
                break;
            }
        }
        return candidate;
    }
};
```
