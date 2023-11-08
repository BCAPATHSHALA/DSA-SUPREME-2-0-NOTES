// 📂 Problem 2: Starting point of loop (Leetcode-142)

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
    ListNode *detectCycle(ListNode *head) {
        // Step 1: Find loop
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            // Agar loop present hai to while ko break krdo
            if(slow == fast){
                break;
            }
        }

        // Agar loop present nhi hai
        if(fast == NULL){
            return fast;
        }

        // Step 2: Find starting point of loop
        slow = head;

        // Slow and fast -> 1 step
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }

        // Return strating point
        return slow;
    }
};