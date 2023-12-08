// PROBLEM 01: Create binary search tree

/*
    Time Complexity: 
    In Unbalanced BST, O(N)
    In balanced BST, O(log N)

    Overall time complexity:
    Worst Case: O(N)
    Average Case: O(N log N)
    Where N is number of nodes in binary search tree

    Space Complexity: O(H), Where H is height of BST
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
*/