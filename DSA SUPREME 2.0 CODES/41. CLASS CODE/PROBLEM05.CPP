// PROBLEM 05: Delete node from BST

/*
    Time complexity:
    CASES 1, 2, and 3 : O(1)
    CASE 4: O(N)

    Overall Time Complexity:
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

// Delete node from BST
Node* deleteFromBST(Node* root, int target){
    // Base case
    if(root == NULL){
        return NULL;
    }

    // Step 01: target ko find krlo
    // Target root v ho skta hai
    if(target == root->data){
        // Step 02: target ko delete krdo
        // Agar target mil jata hai to 4 cases me delete kiya jayega

        // Case 1: leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // Case 2: left me NULL and right NON NULL
        else if(root->left == NULL && root->right != NULL){
            Node* childSubTreeA = root->right;
            delete root;
            return childSubTreeA;
        }
        // Case 3: left non null and right null
        else if(root->left != NULL && root->right == NULL){
            Node* childSubTreeB = root->left;
            delete root;
            return childSubTreeB;
        }
        // Case 4: left NON NULL && right NON NULL
        else if(root->left != NULL && root->right != NULL){
            // Left Sub tree se MAX value find krlo
            Node* maxi = maxValue(root->left);

            // Replace maxi with target value
            root->data = maxi->data;

            // Delete actual maxi->data (YANHA MENE GALTI KARI THI)
            root->left = deleteFromBST(root->left, maxi->data);
            return root;
        }
    }
    // Target root ke left me v ho skta hai
    else if(target < root->data){
        root->left = deleteFromBST(root->left, target);
    }
    // Target root ke right me v ho skta hai
    else{
        root->right = deleteFromBST(root->right, target);
    }

    return root;
}

int main(){
    Node* root = NULL;
    createBST(root);

    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);

    cout<< "Enter target: " << endl;
    int target;
    cin >> target;

    while (target != -1)
    {
        root = deleteFromBST(root, target);
        cout << "Level Wise Order: " << endl;
        levelOrderTraversalLevelWise(root);
        cout<< "Enter target: " << endl;
        cin >> target;
    }
    return 0;
}

/*

Example 1: (CASE: 4)
Binary Tree Input: 50 30 40 20 60 55 70 80 25 -1
Target Node: 50

BEFORE DELETION OF TARGET NODE
Level Wise Order: 
50 
30 60 
20 40 55 70 
25 80

AFTER DELETION OF TARGET NODE
Level Wise Order: 
40 
30 60 
20 55 70 
25 80 

Example 2: (CASE: 2)
Binary Tree Input: 50 30 40 20 60 55 70 80 25 -1
Target Node: 70

BEFORE DELETION OF TARGET NODE
Level Wise Order: 
50 
30 60 
20 40 55 70 
25 80

AFTER DELETION OF TARGET NODE
Level Wise Order: 
50 
30 60 
20 40 55 80 
25

Example 3: (CASE: 1)
Binary Tree Input: 50 30 40 20 60 55 70 80 25 -1
Target Node: 25

BEFORE DELETION OF TARGET NODE
Level Wise Order: 
50 
30 60 
20 40 55 70 
25 80

AFTER DELETION OF TARGET NODE
Level Wise Order: 
50 
30 60 
20 40 55 70 
80 


Example 4: (CASE: 3)
Binary Tree Input: 50 30 60 20 40 55 25 -1
Target Node: 60

BEFORE DELETION OF TARGET NODE
Level Wise Order: 
50 
30 60 
20 40 55 
25 

AFTER DELETION OF TARGET NODE
Level Wise Order: 
50 
30 55 
20 40 
25
*/