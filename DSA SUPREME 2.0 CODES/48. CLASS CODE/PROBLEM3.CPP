// PROBLEM 3: Linked List Cycle (Leetcode-141)

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

        unordered_map<ListNode*, bool> mapping;
        ListNode* temp = head;

        while(temp != NULL){
            // Visited Address
            if(mapping.find(temp) != mapping.end()){
                // Visited address found-> cycle present hai
                return true;
            }
            // Not Visited Address
            else{
                mapping[temp] = true;
            }

            // Update temp
            temp = temp->next;
        }

        // Cycle is not present
        return false;        
    }
};