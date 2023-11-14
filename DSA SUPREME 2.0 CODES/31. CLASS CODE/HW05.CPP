// HW 05: Print kth Node from the End (Hackerrank)


/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
*/
 
// APPROACH 01: Recursive and backtracking approach
// Time complexity: O(N), where N is numbers of node
// Space complexity: O(1)
void solve(SinglyLinkedListNode* head, int &pos, int &ans){
    // Base case
    if(head == 0) return;
    
    // Step 1: traverse list from head to tail
    solve(head->next, pos, ans);
    
    // Step 2: traverse list from tail to (Jab tak pos == 0)
    if(pos == 0){
        ans = head->data;
    }
    --pos;
}

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
        // Step 3: return ans
        int ans = -1;
        solve(llist, positionFromTail, ans);
        return ans;
}

// APPROACH 02: Iterative
// Time complexity: O(N), where N is numbers of nodes
// Space complexity: O(1)
int getLength(SinglyLinkedListNode* head){
    SinglyLinkedListNode* temp = head;
    int lenLL = 0;
        
    // Base case
    if(head == 0) return lenLL;
    
    while (temp->next != 0) {
        lenLL++;
        temp = temp->next;
    }
    
    return lenLL; 
}

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
        // Step 1: get length of list
        int length = getLength(llist);
        
        // Step 2: subtract pos from length
        int posFromHead = length - positionFromTail;
        
        // Step 3: traverse list from head to (Jab tak pos==0)
        while(posFromHead != 0){
            llist = llist->next;
            posFromHead--;
        }
        
        return llist->data;
}
