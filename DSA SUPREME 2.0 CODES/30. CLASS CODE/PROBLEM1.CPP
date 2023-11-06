// 📂 Program 1: Reverse Linked List (Leetcode-206)

/*
Approach 1: Iterative approach
Step 1: 
Node* PREV = NULL
Node* CURR = Head

Step 2: While (CURR != NULL)
Node* nextNode = CURR->NEXT
CURR->NEXT = PREV
PREV = CURR
CURR = nextNode

Step 3: Head = PREV
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
    ListNode* reverseList(ListNode* head) {
        // Step 1
        ListNode* prev = NULL;
        ListNode* curr = head;

        // Step 2
        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3
        // head = prev;
        // return head;

        return prev;
    }
};


// Approach 1: Recursive approach
class Solution {
public:
    ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr){
        // Base case
        if(curr == NULL){
            return prev;
        }

        // Ek case hum solve krenge
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        // Baki recursion sambhal lega
        ListNode* recursionKaAns = reverseUsingRecursion(prev,curr);
        return recursionKaAns;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        return reverseUsingRecursion(prev, curr);
    }
};