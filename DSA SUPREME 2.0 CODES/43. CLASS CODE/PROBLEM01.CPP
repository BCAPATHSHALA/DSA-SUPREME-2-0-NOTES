// PROBLEM 01: Convert BST into Sorted Double Linked List

/*
Time Complexity: O(N)
Space Complexity: O(H)
Where N is number of nodes of BST and H is height of BST
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

Node* bstFromInorder(int inorder[], int start, int end){
    // Base case 
    if(start > end){
        return NULL;
    }

    // 1 case hum solve kar lenge
    int mid = (start + end) / 2;
    int element = inorder[mid];
    Node* root = new Node(element);

    // Ab recursion solve kr lega
    root->left = bstFromInorder(inorder, start, mid - 1);
    root->right = bstFromInorder(inorder, mid + 1, end);
    
    return root;
}

void convertBSTtoDLL(Node* root, Node* &head){
    // Base case
    if(root == NULL){
        return;
    }

    // Reverse Inorder Traversal
    // R
    convertBSTtoDLL(root->right, head);

    // N
    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    // Updating the head (GALTI YANHI HO RHI THI)
    head = root;

    // L
    convertBSTtoDLL(root->left, head);
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

int main(){

    int inorder[] = {5, 50, 60, 100, 200, 300};
    int size = 6;
    int start = 0;
    int end = size - 1;
    
    Node* root = bstFromInorder(inorder, start, end);
    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);

    Node* head = NULL;
    convertBSTtoDLL(root, head); 
    cout << "Sorted Double Linked List: " << endl;
    printDLL(head);

    return 0;
}

/*

Example 1:
In Order: [10 20 30 40 50 60 70 80]
Level Wise Order: 
60 
5 200 
50 100 300 
Sorted Double Linked List: 
5 50 60 100 200 300 
*/