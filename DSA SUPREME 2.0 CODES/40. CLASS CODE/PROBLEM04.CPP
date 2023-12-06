// PROBLEM 04: Bottom view of binary tree

/*
    Time Complexity: O(N), where N is total number of nodes in binary tree
    Space Complexity: O(N)
    considering a skewed tree: space complexity is O(N)
    considering now skewed tree: space complexity is O(W), Where W is maximum width of the tree
*/


#include<iostream>
#include<queue>
#include<map>
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

// Bottom View of Binary Tree
void printBottomView(Node* root){
    map<int, int> hdToNodeMap; // < level, data >
    queue<pair<Node*, int>> q;
    // Initialy store the root node and level 0 into queue
    q.push(make_pair(root,0));

    while(!q.empty()){
        // Fetch front from queue and pop
        pair<Node*, int> front = q.front();
        q.pop();

        Node* frontNode = front.first;
        int level = front.second;

        // OVERWRITE: Store frontNode->data and level into the map
        hdToNodeMap[level] = frontNode->data;
        
        // Agar root ka left node exist krta hai to queue me push krdo with level-1
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left, level-1));
        }
        // Agar root ka right node exist krta hai to queue me push krdo with level+1
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right, level+1));
        }
    }

    cout<< "Printing Bottom View: " << endl;
    for(auto data: hdToNodeMap){
        cout<< data.second << " ";
    }
}

int main(){
    Node* root = createTree();

    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);

    printBottomView(root);

    return 0;
}

/*
Binary Tree Input: 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 9 112 -1 -1 113 -1 -1

OUTPUT:
10 
20 30 
40 50 60 
70 80 9 
110 111 112 113 
Printing Bottom View: 
110 70 111 80 112 9 113 
*/