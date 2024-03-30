DATE: 30-03-2024

## Problem 37: [ Delete Node in a Linked List (Leetcode-237) ](https://leetcode.com/problems/delete-node-in-a-linked-list)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

There is a singly-linked list `head` and we want to delete a `node` in it.

You are given the node to be deleted `node`. You will not be given access to the first node of `head`.

All the values of the linked list are _**unique**_, and it is guaranteed that the given node node is not the last `node` in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

- The value of the given node should not exist in the linked list.
- The number of nodes in the linked list should decrease by one.
- All the values before `node` should be in the same order.
- All the values after `node` should be in the same order.

**Custom testing:**

- For the input, you should provide the entire linked list `head` and the node to be given `node`. `node` should not be the last node of the list and should be an actual node in the list.
- We will build the linked list and pass the node to your function.
- The output will be the entire list after calling your function.

## Examples

Example 1:

<p>
  <img src="https://assets.leetcode.com/uploads/2020/09/01/node1.jpg" alt="Example 1">
</p>

```bash
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
```

Example 2:

<p>
  <img src="https://assets.leetcode.com/uploads/2020/09/01/node2.jpg" alt="Example 2">
</p>

```bash
Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
```

## Constraints:

1. The number of the nodes in the given list is in the range `[2, 1000]`.
2. `-1000 <= Node.val <= 1000`
3. The value of each node in the list is **unique**.
4. The node to be deleted is **in the list** and is **not a tail** node.

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

**Similar Questions**:

- [Remove Linked List Elements (Easy)](https://leetcode.com/problems/remove-linked-list-elements/)

## Solution 1

```cpp
// Optimal Approach
// Time Complexity: O(1)
// Space Complexity: O(1)
// Author: github.com/BCAPATHSHALA

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Step 1: copy the next node val to given node
        node->val = node->next->val;
        // Step 2: deleting the next node
        node->next = node->next->next;
    }
};
```
