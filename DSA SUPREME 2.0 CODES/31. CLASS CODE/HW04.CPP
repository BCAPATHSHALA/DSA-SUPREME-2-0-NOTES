// HW 04: Delete N Nodes after M Nodes (GFG)

/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        // Base case
        if(!head) return;
        
        // Step 1: Traverse list to M position from 0th to (M-1)
        Node* tempHead = head;
        for(int i=0; i<M-1; i++){
            // Temp Head yadi Null par hai
            if(!tempHead) return;
            tempHead = tempHead->next;
        }
        Node* MthNode = tempHead;
        // Mth Node yadi null par hai
        if(!MthNode) return;
        
        // Step 2: Delete N node 
        tempHead = MthNode->next;
        for(int i=0; i<N; i++){
            
            // Nth node available nhi hai
            // mtlb tempHead null hai
            if(!tempHead) break;
            
            Node* temp = tempHead->next;
            delete tempHead;
            tempHead = temp;
        }
        MthNode->next = tempHead;
        
        // Recursive call 
        linkdelete(tempHead, M, N);
    }
};


/*
Time Complexity: O(N), Where N is numbers of nodes in list
Space Complexity: O(1)
*/