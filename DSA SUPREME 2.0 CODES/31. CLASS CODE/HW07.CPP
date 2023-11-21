// HW 07: Copy List with Random Pointer (Leetcode-138)

// Approach 1: Using Map
// Time Complexity: O(N), Where N is number of nodes in list
// Space Complexity: O(N), where N is number of elements (Nodes) stored in map

/*
Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* solve(Node* head, unordered_map<Node*, Node*> &mp){

        // Base case
        if(!head) return NULL;

        // Step 1: Copy list in map
        Node* newHead = new Node(head->val);
        mp[head] = newHead;
        newHead->next = solve(head->next, mp);

        // Step 2: Allocate the random pointer
        if(head->random){
            newHead->random = mp[head->random];
        }

        return newHead;
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        return solve(head, mp);
    }
};


// Approach 2: Without Using Map
// Time Complexity: O(N), Where N is number of nodes in list
// Space Complexity: O(1)


/*
Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* solve(Node* head){
        if(!head) return NULL;

        // Step 1: Clone A->A'
        Node* it = head; // Iterating Over Old Head
        while(it){
            Node* cloneNode = new Node(it->val);
            cloneNode->next = it->next;
            it->next = cloneNode;
            it = cloneNode->next;
        }

        // Step 2: Assign random pointer of A' with the help of A
        it = head;
        while(it){
            Node* cloneNode = it->next;
            cloneNode->random = it->random ? it->random->next : NULL;
            it = cloneNode->next;
        }

        // Step 3: Detach A' from A
        it = head;
        Node* cloneHead = it->next; // cloneHead is not changed after its initial assignment
        while(it){
            Node* cloneNode = it->next;
            it->next = cloneNode->next;
            if(cloneNode->next){
                cloneNode->next = cloneNode->next->next;
            }
            it = it->next;
        }
        return cloneHead;
    }
    Node* copyRandomList(Node* head) {
        return solve(head);
    }
};