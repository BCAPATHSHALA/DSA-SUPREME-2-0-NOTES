// HW 03: Intersection of Two Linked Lists (Leetcode-160)

/*
Problem statement:
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null.

For example, 
the following two linked lists begin to intersect at node c1:

Note that the linked lists must retain their original structure after the function returns.

Custom Judge:
The inputs to the judge are given as follows (your program is not given these inputs):

intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
The judge will then create the linked structure based on these inputs and pass the two heads, 
headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.

Time complexity: O(N)
Space complexity: O(1)
*/


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* listA = headA;
        ListNode* listB = headB;

        while(listA->next != NULL && listB->next != NULL){
            if(listA == listB){
                // Agar listA and listB equal length ki hai 
                // iska mtlb wo yahin se intersect Node return kar degi
                return listA;
            }
            listA = listA->next;
            listB = listB->next;
        }

        // Me yanha tak tabhi pahuncha hu
        // jab listA and listB ki length equal nhi hai     
        if(listA->next == NULL){
            // ListB is bigger
            // We need to find the length of ListB

            int listBLength = 0;
            while(listB->next != 0){
                listBLength++;
                listB = listB->next;
            }

            // In starting, Set headB at right node to get the intersection Node
            while(listBLength--){
                headB = headB->next;
            }
        }

        
        if(listB->next == NULL){
            // ListA is bigger
            // We need to find the length of ListA

            int listALength = 0;
            while(listA->next != 0){
                listALength++;
                listA = listA->next;
            }

            // In starting, Set headA at right node to get the intersection Node
            while(listALength--){
                headA = headA->next;
            }
        }

        // Me yaha tak tabhi pahucha hu jab headA and headB starting me right
        // Node par set ho chuke honge
        // We need to traverse again to get the intersection Node
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};