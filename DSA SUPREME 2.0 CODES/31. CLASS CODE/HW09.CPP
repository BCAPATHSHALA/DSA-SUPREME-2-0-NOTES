// HW 09: Odd Even Linked List (Leetcode-328)

// Time complexity: O(N), Where N is number of nodes of the linked list
// Space complexity: O(1), no extra space used



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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        // Odd indexed list
        ListNode* h1 = head;
        // Even indexed list
        ListNode* h2 = head->next;
        // Save h2 for attaching the odd index list
        ListNode* evenHead = h2;

        while(h2 && h2->next){
            h1->next = h2->next;
            h2->next = h2->next->next;

            h1 = h1->next;
            h2 = h2->next;
        }

        // Odd and even indexed list ko regroup krdo
        h1->next = evenHead;
        return head;
    }
};

/*
Examples:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
*/