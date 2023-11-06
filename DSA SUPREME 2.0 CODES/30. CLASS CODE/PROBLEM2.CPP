// 📂 Program 2: Middle of the Linked List (Leetcode-876)

// Approach 1: getLength and getMid
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
    ListNode* middleNode(ListNode* head) {
        // Step 1: Get length
        int length = getLength(head);

        // Step 2: Get mid node
        int position = length/2 + 1;
        int currPos = 1;
        ListNode* temp = head;

        while(currPos != position){
            currPos++;
            temp = temp->next;
        }
        return temp;
    }
};

// Approach 2: Slow and fast pointer "Hare & Tortoise" algorithm
// Note: Slow ek step tabhi chalega jab Fast two step chal skta ho
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                // Ab fast two step chal chuka hai 
                // Ab hum slow ko one step chla skte hai
                slow = slow->next;
            }
        }
        return slow;
    }
};