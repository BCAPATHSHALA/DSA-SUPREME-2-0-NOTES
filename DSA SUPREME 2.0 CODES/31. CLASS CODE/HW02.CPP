// HW 02: Sort Lists using Merge Sort (Leetcode-148)

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
    /*
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; 
    }
    */

    ListNode* getMid(ListNode* head){
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

    ListNode* merge(ListNode* left, ListNode* right) {
        if(left == NULL) return right;
        if(right == NULL) return left;

        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                mptr->next = left;
                mptr = left;
                left = left->next;
            }
            else{
                mptr->next = right;
                mptr = right;
                right = right->next;
            }
        }

        if(left != NULL){
            mptr->next = left;
        }

        if(right != NULL){
            mptr->next = right;
        }

        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        // Base case
        if(head == NULL || head->next == NULL){
            return head;
        }

        // Step 1: Find mid position of the list
        ListNode* mid = getMid(head);

        // Step 2: Divede list into two half using mid
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        // Step 3: Sort RE
        left = sortList(left);
        right = sortList(right);

        // Step 4: Merge both sorted list left and right
        ListNode* mergeLR = merge(left, right);
        return mergeLR;
    }
};