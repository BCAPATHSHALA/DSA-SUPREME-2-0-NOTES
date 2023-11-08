// 📂PROBLEM 1: Linked List Cycle (Leetcode-141) 

/*
Approach 1: Fast and slow algorithm
Reasoning : Why this algorithm work
Time Complexity: O(N)
Space Complexity: O(1)
*/

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
    bool hasCycle(ListNode *head) {

        // Step 1
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 2
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            // Check loop
            if(slow == fast){
                return true;
            }
        }

        // Lopp present nhi hai
        return false;
    }
};