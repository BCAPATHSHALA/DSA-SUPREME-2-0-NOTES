// HW 08: Rotate List (Leetcode-61)

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
    int getLength(ListNode* head){
        ListNode* temp = head;
        int len = 0;

        while(temp){
            len++;
            temp = temp->next;
        }

        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        // Corner Case
        if(!head) return NULL;

        // Step 1: Find length of list
        int len = getLength(head);

        // Step 2: Find actual rotation of k
        int actualRotateK = k % len;

        // Corner case
        if(actualRotateK == 0) return head;

        // Step 3: Find position of lastNewNode
        int newLastNodePos = len - actualRotateK - 1;
        
        ListNode* newLastNode = head;
        for(int i=0; i<newLastNodePos; i++){
            newLastNode = newLastNode->next;
        }

        // Save newLastNode->next in newHead to track
        ListNode* newHead = newLastNode->next;
        newLastNode->next = NULL;

        // newHead ka next node yadi null ho jata hai 
        // to use old Head se meet kara do
        ListNode* it = newHead;
        while(it->next != NULL){
            it = it->next;
        }
        it->next = head;

        return newHead;

    }
};