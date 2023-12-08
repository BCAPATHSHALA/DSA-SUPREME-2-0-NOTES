// PROBLEM 03: Min and Max value in BST

/*
    Time complexity:
    Skewed BST: O(N) or O(H) in the worst case
    Balanced BST: O(log N) in the average case

    Space Complexity: O(H)
    In the worst case: H is equal to O(N)
    In the average case: H is equal to O(log N) 

    Where H is height of BST and N is number of nodes in BST
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

// Min value of BST
Node* minValue(Node* root){
    if(root == NULL){
        // No min value of BST
        return NULL;
    }

    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

// Max value of BST
Node* maxValue(Node* root){
    if(root == NULL){
        // No max value of BST
        return NULL;
    }

    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

int main(){
    Node* root = NULL;
    createBST(root);

    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);

    Node* minNode = minValue(root);
    Node* maxNode = maxValue(root);

    if(minNode == NULL){
        cout<< "No Min Value" << endl;
    }
    else{
        cout<< "Min Value: " << minNode->data << endl;
    }

    if(maxNode == NULL){
        cout<< "No Max Value" << endl;
    }
    else{
        cout<< "Max Value: " << maxNode->data << endl;
    }

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
Min Value: 20
Max Value: 80
*/