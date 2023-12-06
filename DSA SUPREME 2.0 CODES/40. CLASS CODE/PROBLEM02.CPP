// PROBLEM 02: Right view of binary tree

/*
    Time Complexity: O(N), where N is total number of nodes in binary tree
    Space Complexity: O(L), where L is maximum number of nodes in the level of binary tree
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

// Right View of Binary Tree
void printRightView(Node* root, int level, vector<int> &rightView){
    // Base case
    if(root == NULL){
        return;
    }

    // 1 case hum solve kar lenge
    if(level == rightView.size()){
        rightView.push_back(root->data);
    }

    // Ab recursion solve kar lega
    printRightView(root->right, level+1, rightView);
    printRightView(root->left, level+1, rightView);
}

int main(){
    Node* root = createTree();

    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);

    int level = 0;
    vector<int> rightView;
    printRightView(root, level, rightView);
    cout << "Right view: " << endl;
    for(auto data: rightView){
        cout<< data << " ";
    }

    return 0;
}

/*
Binary Tree Input: 10 30 61 -1 -1 60 62 -1 -1 -1 20 50 -1 65 -1 69 -1 -1 40 -1 -1

OUTPUT:
Level Wise Order: 
10 
30 20 
61 60 50 40 
62 65 
69 
Right view: 
10 20 40 65 69 
*/