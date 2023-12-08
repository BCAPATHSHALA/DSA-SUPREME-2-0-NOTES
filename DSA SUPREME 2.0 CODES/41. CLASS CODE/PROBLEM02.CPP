// 	PROBLEM 02: Traversals of binary search tree

/*
    Time and space complexity: O(N), 
    where N is total number of nodes in binary search tree
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

// CREATE BINARY SEARCH TREE
Node* inserIntoBST(Node* root, int data){
    // Create first node when root is null
    if(root == NULL){
        Node* root = new Node(data);
        return root;
    }

    // Not for first Node
    if(data > root->data){
        // Right Sub Tree
        root->right = inserIntoBST(root->right, data);
    }
    else{
        // Left Sub Tree
        root->left = inserIntoBST(root->left, data);
    }

    return root;
}

void createBST(Node* &root){
    cout<< "Enter Data: " << endl;
    int data;
    cin >> data;

    while (data != -1)
    {
        root = inserIntoBST(root, data);
        cin >> data;
    }
    
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


int main(){
    Node* root = NULL;
    createBST(root);

    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);

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
Binary Tree Input: 50 30 40 20 60 55 70 80 25 -1

OUTPUT:
Level Wise Order: 
50 
30 60 
20 40 55 70 
25 80 

Pre Order: 
50 30 20 25 40 60 55 70 80 

In Order: 
20 25 30 40 50 55 60 70 80 

Post Order: 
25 20 40 30 55 80 70 60 50 
*/