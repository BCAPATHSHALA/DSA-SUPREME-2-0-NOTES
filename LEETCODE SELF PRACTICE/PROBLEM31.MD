DATE: 22-03-2024

## Problem 31: [ Palindrome Linked List (Leetcode-234) ](https://leetcode.com/problems/palindrome-linked-list)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given the `head` of a singly linked list, return `true` if it is a **palindrome** (A palindrome is a sequence that reads the same forward and backward) or `false` otherwise.

## Examples

Example 1:

<p>
  <img src="https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg" alt="Example 1">
</p>

```bash
Input: head = [1,2,2,1]
Output: true
```

Example 2:

<p>
  <img src="https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg" alt="Example 2">
</p>

```bash
Input: head = [1,2]
Output: false
```

## Constraints:

1. The number of nodes in the list is in the range `[1, 10^5]`.
2. `0 <= Node.val <= 9`

**Follow up:** Could you do it in `O(n)` time and `O(1)` space?

**Companies**:  
[IXL](https://leetcode.com/company/ixl), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:

- [Palindrome Number (Easy)](https://leetcode.com/problems/palindrome-number/)
- [Valid Palindrome (Easy)](https://leetcode.com/problems/valid-palindrome/)
- [Reverse Linked List (Easy)](https://leetcode.com/problems/reverse-linked-list/)

## Solution 1

```cpp
// Optimal Approach
// Time Complexity: O(N)
// Space Complexity: O(N)
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
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

    ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr){
        // Base case
        if(curr == NULL){
            return prev;
        }

        // Ek case hum solve kar lete hai
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        // Ab baki ka recursion solve kr lega
        return reverseUsingRecursion(prev, curr);
    }

    bool compareList(ListNode* head, ListNode* head2){
         while(head2 != NULL){
            if(head->val != head2->val){
                return false;
            }
            else{
                head = head->next;
                head2 = head2->next;
            }
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        // Step 1: Break linked list into 2 halfs
        ListNode* midNode = middleNode(head);
        ListNode* head2 = midNode->next;
        midNode->next = NULL;

        // Step 2: Reverse second half of linked list
        ListNode* prev = NULL;
        ListNode* curr = head2;
        head2 = reverseUsingRecursion(prev, curr);

        // Step 3: Compare first half with reversed second half
        bool ans = compareList(head, head2);
        return ans;
    }
};
```
