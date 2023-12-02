// 4. Three binary tree traversals

/*
		I. Pre-order traversal (NLR)
		II. In order traversal (LNR)
		III. Post order traversal (LRN)

        Time and space complexity: O(N), 
        where N is total number of nodes in binary tree
*/


#include<iostream>
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

// It returns the root node of created tree
Node* createTree(){
    cout<< "Enter the value: " << endl;
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    // Step 1: Create Node
    Node* root = new Node(data);
    // Step 2: Create Left Subtree
    root->left = createTree();
    // Step 3: Create Right Subtree
    root->right = createTree();

    return root;
}

// I. Pre-order traversal (NLR)
void preOrderTraversal(Node* root){
    // Base case
    if(root == NULL) return;

    // N
    cout << root->data << " ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);
}

// II. In order traversal (LNR)
void inOrderTraversal(Node* root){
    // Base case
    if(root == NULL) return;

    // L
    inOrderTraversal(root->left);
    // N
    cout << root->data << " ";
    // R
    inOrderTraversal(root->right);
}

// III. Post order traversal (LRN)
void postOrderTraversal(Node* root){
    // Base case
    if(root == NULL) return;

    // L
    postOrderTraversal(root->left);
    // R
    postOrderTraversal(root->right);
    // N
    cout << root->data << " ";
}

int main(){
    Node* root = createTree();

    cout << "Pre Order: " << endl;
    preOrderTraversal(root);
    cout<<endl<<endl;

    cout << "In Order: " << endl;
    inOrderTraversal(root);
    cout<<endl<<endl;

    cout << "Post Order: " << endl;
    postOrderTraversal(root);
    cout<<endl<<endl;

    return 0;
}

/*
Binary Tree Input: 10 20 40 -1 -1 50 90 -1 -1 100 -1 -1 30 60 -1 -1 70 -1 -1

OUTPUT:
Pre Order: 
10 20 40 50 90 100 30 60 70 

In Order: 
40 20 90 50 100 10 60 30 70 

Post Order: 
40 90 100 50 20 60 70 30 10 
*/