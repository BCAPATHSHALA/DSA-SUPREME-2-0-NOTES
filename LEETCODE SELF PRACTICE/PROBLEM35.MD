DATE: 28-03-2024

## Problem 35: [ Swap Nodes in Pairs (Leetcode-24) ](https://leetcode.com/problems/swap-nodes-in-pairs)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

## Examples

Example 1:

<p>
  <img src="https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg" alt="Example 1">
</p>

```bash
Input: head = [1,2,3,4]
Output: [2,1,4,3]
```

Example 2:

```bash
Input: head = []
Output: []
```

Example 3:

```bash
Input: head = [1]
Output: [1]
```

## Constraints:

1. The number of nodes in the list is in the range `[0, 100]`.
2. `0 <= Node.val <= 100`

**Companies**:

[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:

- [Reverse Nodes in k-Group (Hard)](https://leetcode.com/problems/reverse-nodes-in-k-group/)
- [Swapping Nodes in a Linked List (Medium)](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)

## Solution 1

```cpp
// Optimal Approach
// Time Complexity: O(N)
// Space Complexity: O(1)
// Author: github.com/BCAPATHSHALA

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        // Initial State
        ListNode* dummyNode = new ListNode();;
        ListNode* prevNode = dummyNode;
        ListNode* currNode = head;

        // Iterate the list
        while(currNode != NULL && currNode->next != NULL){

            // Swapping nodes alternatively
            prevNode->next = currNode->next;
            currNode->next = prevNode->next->next;
            prevNode->next->next = currNode;

            // Now update the prev and curr node
            prevNode = currNode;
            currNode = currNode->next;
        }
        return dummyNode->next;
    }
};
```
