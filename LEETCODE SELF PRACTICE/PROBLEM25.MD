DATE: 12-03-2024

## Problem 25: [ Remove Zero Sum Consecutive Nodes from Linked List (Leetcode-1171) ](https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given the `head` of a linked list, we repeatedly delete consecutive sequences of nodes that sum to `0` until there are no such sequences.

After doing so, return the head of the final linked list. You may return any such answer.

(Note that in the examples below, all sequences are serializations of `ListNode` objects.)

## Examples

Example 1:

```bash
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
```

Example 2:

```bash
Input: head = [1,2,3,-3,4]
Output: [1,2,4]
```

Example 3:

```bash
Input: head = [1,2,3,-3,-2]
Output: [1]
```

Example 4
```bash
Input: head = [2,-3,3,1]
Output: [2,1]
```

## Constraints:

1. The given linked list will contain between `1` and `1000` nodes.
2. Each node in the linked list has `-1000 <= node.val <= 1000`.

**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

**Similar Questions**:
* [Delete N Nodes After M Nodes of a Linked List (Easy)](https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/)


## Solution 1

```cpp
/*
Optimal Approach
Time Complexity: O(N)
Space Complexity: O(N)
Author: github.com/BCAPATHSHALA
*/

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        int prefixSum = 0;
        // Step 1: Create the map to store {prefixSum, node}
        unordered_map<int, ListNode*> prefixMap;
        prefixMap[prefixSum] = dummyHead;
        ListNode* temp = dummyHead;

        while(temp != NULL){
            prefixSum += temp->val;
            prefixMap[prefixSum] = temp;
            temp = temp->next;
        }

        // Step 2: remove the sum of zero part of list using map
        prefixSum = 0;
        temp = dummyHead;
        while(temp != NULL){
            prefixSum += temp->val;
            if(prefixMap.find(prefixSum) != prefixMap.end()){
                ListNode* deleteNode = prefixMap[prefixSum]->next;
                temp->next = deleteNode;
                temp = temp->next;
            }
        }

        // Step 3: return head
        return dummyHead->next;
    }
};
```
