DATE: 03-03-2024

## Problem 20: [ Remove Nth Node From End of List (Leetcode-19) ](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.

## Examples

Example 1:

```bash
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

Example 2:

```bash
Input: head = [1], n = 1
Output: []
```

Example 3:

```bash
Input: head = [1,2], n = 1
Output: [1]
```

Example 4:

```bash
Input: head = [1,2], n = 2
Output: [2]
```

## Constraints:

1. The number of nodes in the list is `sz`.
2. `1 <= sz <= 30`
3. `0 <= Node.val <= 100`
4. `1 <= n <= sz`

**Follow up:** Could you do this in one pass?

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:

- [Swapping Nodes in a Linked List (Medium)](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)
- [Delete N Nodes After M Nodes of a Linked List (Easy)](https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/)

## Solution 1

```cpp
/*
Approach 1: without using two pointer
Time Complexity:  O(N), where N is length of List
Space Complexity: O(1)
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    int getLength(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: get the length of list
        int lengthLL = getLength(head);

        // Handle the corner cases
        if(lengthLL == 1){
            return NULL;
        }

        // Step 2: get removel position from start of list
        int pos = (lengthLL - n) + 1;

        // Step 3: traverse to the removel node
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(pos != 1){
            prev = curr;
            curr = curr->next;
            pos--;
        }

        // Step 4: Take the action to get the intent output after got the removel node position
        if(prev == NULL){
            // Corner Case: delete from head
            head = curr->next;
            curr->next = NULL;
            delete curr;
        }
        else if(prev != NULL){
            // delete from any position except from head
            prev->next = NULL;
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }

        // Return the head
        return head;
    }
};
```

## Solution 2

```cpp
/*
Approach 2: Using Two Pointer(Fast and Slow)
Time Complexity:  O(N)
Space Complexity: O(1)
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Move the fast pointer n positions ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Handle the case when the first element is to be removed
        if (fast == NULL) {
            return head->next;
        }

        // Move both pointers until the fast pointer reaches the end
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        slow->next = slow->next->next;

        return head;
    }
};
```
