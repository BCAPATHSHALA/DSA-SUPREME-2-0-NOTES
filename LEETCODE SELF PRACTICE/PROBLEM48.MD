DATE: 06-06-2024

## Problem 48: [ Hand of Straights (Leetcode-846) ](https://leetcode.com/problems/hand-of-straights)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size `groupSize`, and consists of `groupSize` consecutive cards.

Given an integer array `hand` where `hand[i]` is the value written on the `ith` card and an integer `groupSize`, return `true` if she can rearrange the cards, or `false` otherwise.

## Examples

Example 1:

```bash
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
```

Example 2:

```bash
Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.
```

Example 3:

```bash
Input: hand = [1,2,3,6,2,3,3,7,8], groupSize = 3
Output: false
Explanation: Alice's hand can not be rearranged into groups of 3 beacuase of second group [1,2,3], [2,3,3], [6,7,8]
```

## Constraints:

1. `1 <= hand.length <= 10^4`
2. `0 <= hand[i] <= 10^9`
3. `1 <= groupSize <= hand.length`

<strong>Note:</strong> This question is the same as&nbsp;1296:&nbsp;<a href="https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/">https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/</a>

**Related Topics**:  
[Ordered Map](https://leetcode.com/tag/ordered-map/)

## Solution 1

```cpp
// Optimal Approach
// Time Complexity: O(N Log N) + (N * groupSize)
// Space Complexity: O(N)
// Author: github.com/BCAPATHSHALA

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Edge Case
        int n = hand.size();
        if(n % groupSize != 0){
            return false;
        }

        // Step 1: tore the frequency of each value of hands in ordered map
        map<int, int> freqMap;
        for(auto &handValue: hand){
            freqMap[handValue]++;
        }

        // Step 2: create the consecutive cards group of group size till map is not empty
        while(!freqMap.empty()){
            int currNumber = freqMap.begin()->first;
            for(int i =0; i < groupSize; i++){
                if(freqMap[currNumber + i] == 0){
                    // Not present the consecutive number like: currNumber + 0, currNumber + 1 ...
                    // it means not possible to build the consecutive cards group
                    return false;
                }

                // Update the frequency of currNumber
                freqMap[currNumber + i]--;

                if(freqMap[currNumber + i] < 1){
                    // currNumber + i frequency is now zero or -ve
                    // delete this number from map
                    freqMap.erase(currNumber + i);
                }
            }
        }

        // Agar ynha tak pahunch gya hu iska mtlb consecutive cards group ban gya hai
        return true;
    }
};
```
