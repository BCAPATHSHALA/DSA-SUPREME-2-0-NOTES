DATE: 20-03-2024

## Problem 30: [ Merge In Between Linked Lists (Leetcode-1669) ](https://leetcode.com/problems/merge-in-between-linked-lists)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

You are given two linked lists: `list1` and `list2` of sizes `n` and `m` respectively.

Remove `list1`'s nodes from the `ath` node to the `bth` node, and put `list2` in their place.

The blue edges and nodes in the following figure indicate the result:

<p align="center">
  <img src="https://assets.leetcode.com/uploads/2020/11/05/fig1.png" alt="Example">
</p>

Build the result list and return its head.

## Examples

Example 1:

<p>
  <img src="https://assets.leetcode.com/uploads/2024/03/01/ll.png" alt="Example 1">
</p>

```bash
Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.
```

Example 2:

<p>
  <img src="https://assets.leetcode.com/uploads/2020/11/05/merge_linked_list_ex2.png" alt="Example 2">
</p>

```bash
Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
Explanation: The blue edges and nodes in the above figure indicate the result.
```

## Constraints:

1. `3 <= list1.length <= 10^4`
2. `1 <= a <= b < list1.length - 1`
3. `1 <= list2.length <= 10^4`

**Companies**:
[Google](https://leetcode.com/company/google)
[VMware](https://leetcode.com/company/vmware)
[Sambanova](https://leetcode.com/company/sambanova)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

## Solution 1

```cpp
// Optimal Approach
// Time Complexity: O(N)
// Space Complexity: O(1)
// Author: github.com/BCAPATHSHALA
// where n is the number of nodes in list1.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // Navigate for position a-1
        ListNode* firstIndex = list1;
        for(int i = 0; i < (a - 1); i++){
            firstIndex = firstIndex->next;
        }

        // Navigate for position b-1
        ListNode* lastIndex = firstIndex->next;
        for(int i = 0; i < (b - a + 1); i++){
            lastIndex = lastIndex->next;
        }

        // Insert list 2 between a & b position in list 1
        firstIndex->next = list2;
        while(list2->next){
            list2 = list2->next;
        }
        list2->next = lastIndex;

        // Return head of list1
        return list1;
    }
};
```
