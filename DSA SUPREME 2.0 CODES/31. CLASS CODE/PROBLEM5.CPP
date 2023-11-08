// 📂 Problem 5: Reverse Nodes in K-Group (Leetcode-25)

/*
Approach 1: Recursive approach
Time Complexity: O(N/2) = O(N), Where N is number of nodes
Space Complexity: O(1)

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
    int getLength(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base Case
        int len = getLength(head);
        if(len < k) {
            // We can handle 
            // Empty, and Single element list using this condition
            return head;
        }

        // 1 Case hum solve kar lete hai
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = curr->next;
        int position = 0;

        while(position < k){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            position++;
        }

        // Ab recursion solve kar lega
        ListNode* recursionKaAns = NULL;
        if(nextNode != NULL){
            recursionKaAns = reverseKGroup(nextNode, k);

            // CATCH 1: Yanha bhaiya ne 4 time galti kari thi
            head->next = recursionKaAns;
        }

        // CATCH 2: Yanha bhi bhaiya ne 4 time galti kari thi
        return prev;
    }
};