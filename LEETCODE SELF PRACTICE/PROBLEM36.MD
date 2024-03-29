DATE: 29-03-2024

## Problem 36: [ Swapping Nodes in a Linked List (Leetcode-1721) ](https://leetcode.com/problems/swapping-nodes-in-a-linked-list)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

You are given the `head` of a linked list, and an integer `k`.

Return the head of the linked list after swapping the values of the `kth` node from the beginning and the `kth` node from the end (the list is _1-indexed_).

## Examples

Example 1:

<p>
  <img src="https://assets.leetcode.com/uploads/2020/09/21/linked1.jpg" alt="Example 1">
</p>

```bash
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
```

Example 2:

```bash
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
```

Example 3:

```bash
Input: head = [1], k=1
Output: [1]
```

## Constraints:

1. The number of nodes in the list is `n`.
2. `1 <= k <= n <= 10^5`
3. `0 <= Node.val <= 100`

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:

- [Remove Nth Node From End of List (Medium)](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
- [Swap Nodes in Pairs (Medium)](https://leetcode.com/problems/swap-nodes-in-pairs/)
- [Reverse Nodes in k-Group (Hard)](https://leetcode.com/problems/reverse-nodes-in-k-group/)

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
    // Get the length of LL
    int getLength(ListNode* head) {
        ListNode* temp = head;
        int count = 0;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(head->next == NULL){
            return head;
        }
        // Step 1: get length of linked list
        int height = getLength(head);
        int start = k;
        int end = (height % 2 == 0) ? ((height - k) + 1) : (height - (k-1));

        // Step 2: Initial State
        ListNode* currNode = head;
        ListNode* beginNode = NULL;
        ListNode* endNode = NULL;
        int position = 0;

        // Traverse to the node's position
        while(currNode != NULL){
            position++;
            if(position == start){
                beginNode = currNode;
            }
            if(position == end){
                endNode = currNode;
            }
            currNode = currNode->next;
        }

        // Step 3: Swap the value of both nodes
        swap(beginNode->val, endNode->val);
        return head;
    }
};
```
