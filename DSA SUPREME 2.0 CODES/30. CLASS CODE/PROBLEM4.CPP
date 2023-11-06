// 📂 Program 4: Linked List Cycle (Leetcode-141)

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
        // Create map table
        map<ListNode*, bool> table;

        // Store head address in temp
        ListNode* temp = head;

        while(temp != NULL){
            if(table[temp] == false){
                table[temp] = true;
            }
            else{
                // Cycle present hai
                return true;
            }
            temp = temp->next;
        }

        // Loop not present
        return false;
    }
};