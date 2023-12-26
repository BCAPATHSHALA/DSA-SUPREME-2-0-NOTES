// PROBLEM 2: Merge K Sorted Linked Lists (Leetcode-23)

/*
Problem statement:
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

Constraints:
1. k == lists.length
2. 0 <= k <= 10^4
3. 0 <= lists[i].length <= 500
4. -10^4 <= lists[i][j] <= 10^4
5. lists[i] is sorted in ascending order.
6. The sum of lists[i].length will not exceed 10^4.

Time complexity: O(N*Log N)
Space complexity: O(K)
Where 
N is number of nodes of each linked lists and 
K is number of all linked lists
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
    // OWN COMPARETOR FOR MIN HEAP
    class Compare
    {
        public:
            bool operator()(ListNode* first, ListNode* second){
                return first->val > second->val;
            }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Create MIN Heap 
         priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // I. process first k elements from k lists
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode* listHead = lists[i];
            if(listHead != NULL){
                pq.push(listHead);
            }
        }

        // II. create new linked list
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!pq.empty()){
            ListNode* topNode = pq.top();
            pq.pop();
            // III. Push first topNode in new linked list first time
            if(head == NULL && tail == NULL){
                head = topNode;
                tail = topNode;
                // IV. Update the topNode
                if(tail->next != NULL){
                    pq.push(tail->next);
                }
            }
            else{
                // III. Not pushing the first node now
                tail->next = topNode;
                tail = topNode;
                // IV. Update the topNode
                if(tail->next != NULL){
                    pq.push(tail->next);
                }
            }
        }
        return head;
    }
};