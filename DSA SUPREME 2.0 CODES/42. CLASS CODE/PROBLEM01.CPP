// PROBLEM 1: Construct BST from Inorder (GFG)

/*
    Time complexity: O(N)

    Space Complexity: 
    Skewed BST: O(N) in the worst case
    Balanced BST: O(log N) in the average case

    Where N is number of elements
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

int main(){

    int inorder[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int size = 8;
    int start = 0;
    int end = size - 1;
    
    Node* root = bstFromInorder(inorder, start, end);

    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);


    return 0;
}

/*

Example 1:
In Order: [10 20 30 40 50 60 70 80]
Level Wise Order: 
40 
20 60 
10 30 50 70 
80 
*/