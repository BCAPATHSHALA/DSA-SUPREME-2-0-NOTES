// PROBLEM 04: Target value present or not in BST

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

// Target value found or not
bool searchInBST(Node* root, int target){
    // Base Case
    if(root == NULL){
        return false;
    }

    // 1 case hum solve kr lenge
    if(target == root->data){
        return true;
    }

    bool right = false;
    bool left = false;

    // ab recursion solve kar lega
    if(target > root->data){
        right = searchInBST(root->right, target);
    }
    if(target < root->data){
        left = searchInBST(root->left, target);
    }

    return right || left;
}

int main(){
    Node* root = NULL;
    createBST(root);

    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);

    cout<< "Enter the target:" << endl;
    int target;
    cin >> target;

    while (target != -1)
    {
        bool ans = searchInBST(root, target);
        if(ans == true){
            cout << "FOUND" << endl;
        }
        else{
            cout << "NOT FOUND" << endl;
        }
        cout<< "Enter the target:" << endl;
        cin >> target;
    }
    

    return 0;
}

/*
Binary Tree Input: 50 30 40 20 60 55 70 80 25 -1

Enter the target: 80
OUTPUT: FOUND

Enter the target: 2222
OUTPUT: NOT FOUND
*/