DATE: 23-03-2024

## Problem 32: [ Reorder List (Leetcode-143) ](https://leetcode.com/problems/reorder-list/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

You are given the head of a singly linked-list. The list can be represented as:

`L0 → L1 → … → Ln - 1 → Ln`

Reorder the list to be on the following form:

`L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …`

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

## Examples

Example 1:

<p>
  <img src="https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg" alt="Example 1">
</p>

```bash
Input: head = [1,2,3,4]
Output: [1,4,2,3]
```

Example 2:

<p>
  <img src="https://assets.leetcode.com/uploads/2021/03/09/reorder2-linked-list.jpg" alt="Example 2">
</p>

```bash
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
```

## Constraints:

1. The number of nodes in the list is in the range `[1, 5 * 10^4]`.
2. `1 <= Node.val <= 1000`

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Stack](https://leetcode.com/tag/stack/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:

- [Delete the Middle Node of a Linked List (Medium)](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)

## Solution 1

```cpp
// Brute Force Approach
// Time Complexity: O(N)
// Space Complexity: O(N)
// Author: github.com/BCAPATHSHALA

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

    void reorderList(ListNode* head) {
        // Step 1: Find the length of LL
        int n = getLength(head);

        // Step 2: Create two vectors, left and right
        vector<ListNode*> left;
        vector<ListNode*> right;

        ListNode* temp = head;
        for (int i = 0; i < n / 2; i++) {
            left.push_back(temp);
            temp = temp->next;
        }
        // For odd-sized lists, the middle element should be placed in left/right list
        if (n % 2 != 0) {
            right.push_back(temp);
            temp = temp->next;
        }
        for (int i = (n + 1) / 2; i < n; i++) {
            right.push_back(temp);
            temp = temp->next;
        }

        // Step 3: Create new LL as output (merge both array)
        ListNode dummy(NULL);
        ListNode* ans = &dummy;
        int lSize = left.size();
        int rSize = right.size();

        int i = 0;
        while (i < n) {
            if (i < lSize) {
                ans->next = left[i];
                ans = ans->next;
            }
            if (i < rSize) {
                ans->next = right[rSize - i - 1];
                ans = ans->next;
            }
            i++;
        }
        ans->next = NULL;
         // Update the head of the reordered list
        head = dummy.next;
    }
};
```

## Solution 2

```cpp
// Optimal Approach
// Time Complexity: O(N)
// Space Complexity: O(1)
// Author: github.com/BCAPATHSHALA

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // Find the middle of the list
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }

        // Reverse the second half of the list
        ListNode *prev =NULL, *cur=slow->next, *Next;
        while (cur) {
            Next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=Next;
        }
        slow->next=NULL;

        // Merge the 2 halves
        ListNode *A = head, *B=prev;
        while (A && B) {
            ListNode* A_next=A->next;
            ListNode *B_next=B->next;

            A->next=B;
            B->next=A_next;

            A=A_next;
            B=B_next;
        }
    }
};
```
