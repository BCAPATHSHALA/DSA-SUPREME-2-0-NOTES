// 3. Implementation of binary tree

// Time and space complexity: O(N), 
// where N is total number of nodes in binary tree

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
    // cout<< "Left of node: " << root->data << endl;
    root->left = createTree();
    // Step 3: Create Right Subtree
    // cout<< "Right of node: " << root->data << endl;
    root->right = createTree();

    return root;
}

int main(){
    Node* root = createTree();
    return 0;
}

/*
Enter the value: 
10
Left of node: 10
Enter the value: 
20
Left of node: 20
Enter the value: 
40
Left of node: 40
Enter the value: 
-1
Right of node: 40
Enter the value: 
-1
Right of node: 20
Enter the value: 
50
Left of node: 50
Enter the value: 
90
Left of node: 90
Enter the value: 
-1
Right of node: 90
Enter the value: 
-1
Right of node: 50
Enter the value: 
100
Left of node: 100
Enter the value: 
-1
Right of node: 100
Enter the value: 
-1
Right of node: 10
Enter the value: 
30
Left of node: 30
Enter the value: 
60
Left of node: 60
Enter the value: 
-1
Right of node: 60
Enter the value: 
-1
Right of node: 30
Enter the value: 
70
Left of node: 70
Enter the value: 
-1
Right of node: 70
Enter the value: 
-1
*/