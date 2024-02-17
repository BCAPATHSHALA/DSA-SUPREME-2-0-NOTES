DATE: 17-02-2024

## Problem 11: [ Furthest Building You Can Reach (Leetcode-1642) ](https://leetcode.com/problems/furthest-building-you-can-reach/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

You are given an integer array `heights` representing the heights of buildings, some `bricks`, and some `ladders`.

You start your journey from building `0` and move to the next building by possibly using bricks or ladders.

While moving from building `i` to building `i+1` **(0-indexed)**,

1. If the current building's height is **greater than or equal** to the next building's height, you do **not** need a ladder or bricks.
2. If the current building's height is **less than** the next building's height, you can either use **one ladder** or `(h[i+1] - h[i])` bricks.

Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.

## Examples

![example1](https://assets.leetcode.com/uploads/2020/10/27/q4.gif)

- Example 1:

```bash
Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
Output: 4
Explanation: Starting at building 0, you can follow these steps:
- Go to building 1 without using ladders nor bricks since 4 >= 2.
- Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
- Go to building 3 without using ladders nor bricks since 7 >= 6.
- Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
It is impossible to go beyond building 4 because you do not have any more bricks or ladders.
```

Example 2:

```bash
Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
Output: 7
```

Example 3:

```bash
Input: heights = [14,3,19,3], bricks = 17, ladders = 0
Output: 3
```

Example 4:

```bash
Input: heights = [1,5,1,2,3,4,10000], bricks = 5, ladders = 1
Output: 5
```

Example 5:

```bash
Input: heights = [5,4,3], bricks = 0, ladders = 0
Output: 2
```

## Constraints:

1. `1 <= heights.length <= 10^5`
2. `1 <= heights[i] <= 10^6`
3. `0 <= bricks <= 10^9`
4. `0 <= ladders <= heights.length`

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Heap](https://leetcode.com/tag/heap/)

## Intuition

- First, I want to use the `all bricks` and if `bricks` are not sufficient then i will use the `ladders`.

### Approach

- Step1: first we will use the all bricks
- Step2: if bricks are not sufficient then use the ladders
- Step 3: apply logic to get the least number of unique element

### Complexity

- Time complexity: O(N Log(N))
- Space complexity: O(N)

## Solution 1

```cpp
/*
Brute Force Approach:
Time complexity: O(N log(K))
Space complexity: O(1)
Author: github.com/BCAPATHSHALA

Where N is the number of buildings and K is the maximum difference between heights
*/


class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int maxReachIndex = 0;
        for(int index = 0; index < heights.size()-1; index++){
        int diff = heights[index+1] - heights[index];

            if(diff <= 0){
                // currBH >= nextBH
                maxReachIndex = index + 1;
                continue;
            }
            else if(diff > 0){
                // currBH < nextBH
                if(diff <= bricks){
                    // Step1: first we will use the all bricks
                    maxReachIndex = index + 1;
                    bricks -= diff;
                }
                else if(ladders > 0){
                    // Step2: if bricks are not sufficient then use the ladders
                    maxReachIndex = index + 1;
                    ladders -= 1;
                }
                else if(diff > bricks && ladders <= 0){
                    return maxReachIndex;
                }
                else if(bricks <=0 && ladders <= 0){
                    return maxReachIndex;
                }
            }
        }
        // Ynha tak me tabhi pahunch skta hu jab mera pura array traverse hu chuka hoga
        return maxReachIndex;
    }
};

```

```cpp
/*
Optimal Approach:
Time complexity: O(N Log N)
Space complexity: O(K)
Author: github.com/BCAPATHSHALA

Where K is a maximum size of ladders
*/

class Solution {
public:
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        // Priority Queue for storing the bricks used in each step in decreasing order (Max at top)
        priority_queue<int> maxBricks;

        int i=0, diff =0;
        for(i=0; i<heights.size()-1; i++){

            // Number of required bricks
            diff = heights[i+1]-heights[i];

            if(diff <= 0){
                // currBH >= nextBH
                continue;
            }
            else if(diff > 0 ){
                // currBH < nextBH
                // Step1: first we will use the all bricks when diff > 0
                bricks -= diff;
                maxBricks.push(diff);

                // Step2: if bricks are not sufficient then use the ladders
                if(bricks < 0){
                    ladders--;
                    // Replace maxBrick with 1 ladder when jab all bricks use ho chuke ho
                    bricks += maxBricks.top();
                    maxBricks.pop();
                }
                // Me is step par tabhi pahuncha hu jab mene all bricks and ladders ko use kr liya hai
                if(ladders < 0) break;
            }
        }
        // Ynha tak me tabhi pahunch skta hu jab mera pura array traverse hu chuka hoga
        return i;
    }
};

```
