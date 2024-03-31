DATE: 31-03-2024

## Problem 38: [ Remove Duplicates from Sorted List II (Leetcode-82) ](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given the `head` of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list **sorted** as well.

## Examples

Example 1:

<p>
  <img src="https://assets.leetcode.com/uploads/2021/01/04/linkedlist1.jpg" alt="Example 1">
</p>

```bash
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
```

Example 2:

<p>
  <img src="https://assets.leetcode.com/uploads/2021/01/04/linkedlist2.jpg" alt="Example 2">
</p>

```bash
Input: head = [1,1,1,2,3]
Output: [2,3]
```

## Constraints:

1. The number of nodes in the list is in the range `[0, 300]`.
2. `-100 <= Node.val <= 100`
3. The list is guaranteed to be **sorted** in ascending order.

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [ByteDance](https://leetcode.com/company/bytedance), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Remove Duplicates from Sorted List (Easy)](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
* [Remove Duplicates From an Unsorted Linked List (Medium)](https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/)


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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        // initial state
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* prevNode = dummyHead;
        ListNode* currNode = head;

        while(currNode != NULL && currNode->next != NULL){
            if(currNode->val != currNode->next->val){
                prevNode = currNode;
                currNode = prevNode->next;
            }
            else if(currNode->val == currNode->next->val){
                // Found time duplicate found huaa
                int dupValue = currNode->val;
                while (currNode != NULL && currNode->val == dupValue) {
                    // Ab jab tak duplicate found hoga currNode ko delete & update karte raho
                    ListNode* temp = currNode;
                    currNode = currNode->next;
                    delete temp;
                }
                prevNode->next = currNode;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
```
