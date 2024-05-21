DATE: 04-05-2024

## Problem 43: [ Boats to Save People (Leetcode-881) ](https://leetcode.com/problems/boats-to-save-people)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

You are given an array `people` where `people[i]` is the weight of the `ith` person, and an infinite number of boats where each boat can carry a maximum weight of `limit`. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most `limit`.

Return **_the minimum number of boats to carry every given person_**.

## Examples

Example 1:

```bash
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
```

Example 2:

```bash
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
```

Example 3:

```bash
Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
```

## Constraints:

1. `1 <= people.length <= 5 * 10^4`
2. `1 <= people[i] <= limit <= 3 * 10^4`

**Companies**:  
[Salesforce](https://leetcode.com/company/salesforce), [Amazon](https://leetcode.com/company/amazon), [Cisco](https://leetcode.com/company/cisco), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1

```cpp
// Two Pointer Approach
// Time Complexity: O(n log n)
// Space Complexity: O(1)
// Author: github.com/BCAPATHSHALA

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Step 1: sort the array
        sort(people.begin(), people.end());

        // Step 2: apply two pointer approach
        int boats = 0;
        int start = 0;
        int end = people.size() - 1;

        while(start <= end){
            if(people[start] + people[end] <= limit){
                // Start and End par jo people hai or unka sum of weight jaise hi limit ke equal ho jayega
                // it means, ek boat un sabhi ko carry kar skti hai
                // It means: 1 boat use ho chuki hai
                start++;
            }
            // End do case me decrease hoga
            // Case 1: start and end position jo people bete hue hai or unka sum of weight < limit hai
            // Case 2: start and end position jo people bete hue hai or unka sum of weight > limit hai
            end--;
            boats++;
        }
        return boats;
    }
};
```
