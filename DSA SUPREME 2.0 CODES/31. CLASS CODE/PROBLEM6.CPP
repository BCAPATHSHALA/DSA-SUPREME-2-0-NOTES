// 📂 Problem 6: Remove Duplicates from Sorted List (Leetcode-83)

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
        // Empty List
        if(head == NULL){
            return head;
        }

        // Single Element list
        if(head->next == NULL){
            return head;
        }

        // Non-single element list
        ListNode* temp = head;

        while(temp != NULL){
            if(temp->next != NULL && temp->val == temp->next->val){
                // Remove Duplicates
                ListNode* nextNode = temp->next;
                temp->next = nextNode->next;
                nextNode->next = NULL;
                delete nextNode;
            }
            else{
                // Temp ko aange bhej do
                temp = temp->next;
            }
        }
        // Yanha mujhse galti hue thi mene temp ko return kar diya tha
        return head;
    }
};

/*
Time Complexity: O(N), Where N is number of nodes
Space Complexity: O(1)
*/