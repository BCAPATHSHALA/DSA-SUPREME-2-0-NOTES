// PROBLEM 02: Convert Sorted Double Linked List into BST (IMP-QUESTION-INTERVIEW)

/*
Time Complexity: O(N)
Space Complexity: O(log N) (due to the recursive call stack)
Where N is number of nodes of DLL
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

// Level order traversal in level wise
void levelOrderTraversalLevelWise(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();
        
        if(frontNode == NULL){
            cout<<endl;
            if(!q.empty()){ 
                q.push(NULL);
            }
        }
        else{
            cout<< frontNode->data << " ";

            if(frontNode->left != NULL){
                q.push(frontNode->left);
            }
            if(frontNode->right != NULL){
                q.push(frontNode->right);
            }
        }
    }
}

Node* convertDLLtoBST(Node* &head, int n){
    // Base case
    if(head == NULL || n<=0){
        return NULL;
    }

    // Inorder traversal (LNR)
    // L
    Node* leftST = convertDLLtoBST(head, n/2);

    // N
    Node* root = head;
    root->left = leftST;
    // Updating the head
    head = head->right;

    // R
    Node* rightST = convertDLLtoBST(head, (n-n/2-1));
    root->right = rightST;
    return root;
}
void printDLL(Node* head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<< temp->data << " ";
        temp = temp->right;
    }
    cout<<endl;    
}

int main() {

	Node* first = new Node(10);
	Node* second = new Node(20);
	Node* third = new Node(30);

	first->right = second;
	second->left = first;
	second->right = third;
	third->left = second;

	Node* head = first;
    cout << "Sorted Double Linked List: " << endl;
    printDLL(head);

    int n = 3;
	Node* root = convertDLLtoBST(head, n);
    cout << "Level Wise Order: " << endl;
	levelOrderTraversalLevelWise(root);
    return 0;
}
/*
Example 1:
Sorted Double Linked List: 
10<->20<->30

Level Wise Order: 
    20
    / \
   10  30
*/