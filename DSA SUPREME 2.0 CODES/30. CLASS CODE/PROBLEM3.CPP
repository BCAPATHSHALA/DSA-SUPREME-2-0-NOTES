// 📂 Program 3: Palindrome Linked List (Leetcode-234)

/*
Approach 1: Optimal 
NOTE: Problem in this approach ki hum original linked list ko change kar rhe hai jo ek bad practice hoti hai
Step 1: Break linked list into 2 halfs
Step 2: Reverse second half of linked list
Step 3: Compare first half and reversed second half

Time Complexity = O(N) + O(N) + O(N) = O(N)
Space Complexity = O(1)
*/

/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     ListNode *next;
 **     ListNode() : val(0), next(nullptr) {}
 **     ListNode(int x) : val(x), next(nullptr) {}
 **     ListNode(int x, ListNode *next) : val(x), next(next) {}
 ** };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head){
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

    ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr){
        // Base case
        if(curr == NULL){
            return prev;
        }

        // Ek case hum solve kar lete hai
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        // Ab baki ka recursion solve kr lega
        return reverseUsingRecursion(prev, curr);
    }

    bool compareList(ListNode* head, ListNode* head2){
         while(head2 != NULL){
            if(head->val != head2->val){
                return false;
            }
            else{
                head = head->next;
                head2 = head2->next;
            }
        }
        return true; 
    }
    
    bool isPalindrome(ListNode* head) {
        // Step 1: Break linked list into 2 halfs
        ListNode* midNode = middleNode(head);
        ListNode* head2 = midNode->next;
        midNode->next = NULL;

        // Step 2: Reverse second half of linked list
        ListNode* prev = NULL;
        ListNode* curr = head2;
        head2 = reverseUsingRecursion(prev, curr); 

        // Step 3: Compare first half with reversed second half  
        bool ans = compareList(head, head2);  
        return ans;
    }
};

/*
Approach 2: Brute force
Step 1: Reverse linked list
Step 2: Compare actual and reversed linked list

Time Complexity = O(N) + O(N) = O(N)
Space Complexity = O(N)
*/
