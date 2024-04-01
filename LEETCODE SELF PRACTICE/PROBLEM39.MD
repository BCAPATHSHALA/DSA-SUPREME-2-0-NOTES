DATE: 01-04-2024

## Problem 39: [ Delete the Middle Node of a Linked List (Leetcode-2095) ](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

You are given the `head` of a linked list. Delete the **middle node**, and return the `head` of the modified linked list.

The **middle node** of a linked list of size `n` is the `⌊n / 2⌋th` node from the **start** using **0-based indexing**, where `⌊x⌋` denotes the largest integer less than or equal to `x`.

- For n = `1`, `2`, `3`, `4`, and `5`, the middle nodes are `0`, `1`, `1`, `2`, and `2`, respectively.

## Examples

Example 1:

<p>
  <img src="https://assets.leetcode.com/uploads/2021/11/16/eg1drawio.png" alt="Example 1">
</p>

```bash
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node.
```

Example 2:

<p>
  <img src="https://assets.leetcode.com/uploads/2021/11/16/eg2drawio.png" alt="Example 2">
</p>

```bash
Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
```

Example 3:

<p>
  <img src="https://assets.leetcode.com/uploads/2021/11/16/eg3drawio.png" alt="Example 3">
</p>

```bash
Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
```

## Constraints:

1. The number of nodes in the list is in the range `[1, 10^5]`.
2. `1 <= Node.val <= 10^5`

**Similar Questions**:

- [Remove Nth Node From End of List (Medium)](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
- [Reorder List (Medium)](https://leetcode.com/problems/reorder-list/)
- [Remove Linked List Elements (Easy)](https://leetcode.com/problems/remove-linked-list-elements/)
- [Middle of the Linked List (Easy)](https://leetcode.com/problems/middle-of-the-linked-list/)

## Solution 1

```cpp
// Optimal Approach: Fast-Slow Pointers
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                // Ab fast two step chal chuka hai
                // Ab hum slow ko one step chla skte hai
                slow = slow->next;
            }
        }
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL){
            return NULL;
        }

        // Step 1: Find the middle node from linked list
        ListNode* midNode = middleNode(head);

        // Step 2: Delete the middle node from linked list
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* prevNode = dummyHead;
        ListNode* currNode = head;

        while(currNode != NULL){
            if(currNode != midNode){
                prevNode = currNode;
                currNode = currNode->next;
            }
            else if(currNode == midNode){
                prevNode->next = currNode->next;
                delete currNode;
                break;
            }
        }

        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
```
