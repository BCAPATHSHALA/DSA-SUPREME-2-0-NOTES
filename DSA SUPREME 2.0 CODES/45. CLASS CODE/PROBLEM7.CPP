// 7. Convert Given Combination of CBT and BST into a Valid Max Heap (GFG)

/*
Time complexity: O(N)
Space complexity: O(H+N)
Where N and H are the number of nodes and height of the binary tree respectivily.
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

// CBT+BST to CBT+MAX HEAP
void storeInorderTraversal(Node* root, vector<int> &in){
    // Base case
    if(root == NULL){
        return;
    }

    // L
    storeInorderTraversal(root->left, in);
    // N
    in.push_back(root->data);
    // R
    storeInorderTraversal(root->right, in);
}

void replaceWithPostorder(Node* root, vector<int> in, int &index){
    // Base case
    if(root == NULL){
        return;
    }

    // LRN
    replaceWithPostorder(root->left, in, index);
    replaceWithPostorder(root->right, in, index);
    root->data = in[index];
    index++;
}

Node* convertBSTIntoMaxHeap(Node* root){
    // Step 1: Store inorder traversal
    vector<int> inorder;
    storeInorderTraversal(root, inorder);

    // Step 2: Replace the node value with stored inorder values, using post order traversal
    int index = 0;
    replaceWithPostorder(root, inorder, index);

    return root;
}

int main(){
    Node* root = NULL;
    createBST(root);

    cout << "CBT+BST: " << endl;
    levelOrderTraversalLevelWise(root);

    root = convertBSTIntoMaxHeap(root);
    cout << "CBT+MAX HEAP: " << endl;
    levelOrderTraversalLevelWise(root);

    return 0;
}

/*
Binary Tree Input: 100 50 150 40 60 110 200 20 -1 

OUTPUT:

CBT+BST: 
100 
50 150 
40 60 110 200 
20 

CBT+MAX HEAP: 
200 
60 150 
40 50 100 110 
20 

*/