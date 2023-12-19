// 5. Check if a given Complete Binary Tree is a Max Heap or not? (GFG)

/*
Time complexity: O(N), where N is the number of nodes in the binary tree
Space complexity: O(H), where H is the height of the binary tree.
*/
#include <iostream>
#include<queue>
using namespace std;

// Our Custom Pair Class
class OurPair{
    public:
        int maxVal;
        bool isHeap;

        OurPair(int maxVal, bool isHeap){
            this->maxVal = maxVal;
            this->isHeap = isHeap;
        }
};

// Node Class For CBT
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

// CBT is a valid Max Heap or not (Using our pair)
OurPair checkMaxHeap(Node* root){
    // Base Case 1: Root is Null
    if(root == NULL){
        OurPair temp;
        temp.maxVal = INT_MIN;
        temp.isHeap = true;
        return temp;
    }
    // Base Case 2: Root is a leaf node
    if(root->left == NULL && root->right == NULL){
        OurPair temp;
        temp.maxVal = root->data;
        temp.isHeap = true;
        return temp;
    }

    OurPair leftAns = checkMaxHeap(root->left);
    OurPair rightAns = checkMaxHeap(root->right);

    // 1 case hum solve kr lenge
    if (root->data > leftAns.maxVal && 
        root->data > rightAns.maxVal && 
        leftAns == true && rightAns == true)
    {
        // Valid Max Heap
        OurPair temp;
        temp.maxVal = max(root->data, max(leftAns.maxVal, rightAns.maxVal));
        temp.isHeap = true;
        return temp;
    }
    else
    {
        // Not Valid Max Heap
        OurPair temp;
        temp.maxVal = max(root->data, max(leftAns.maxVal, rightAns.maxVal));
        temp.isHeap = false;
        return temp;
    }    
}

// CBT is a valid Max Heap or not (Using STL Pair)
pair<bool, int> checkMaxHeap(Node* root) {
    // Base Case 1: Root is Null
    if(root == NULL) 
    {
        pair<bool,int> p = make_pair(true, INT_MIN);
        return p;
    }
    // Base Case 2: Root is a leaf node
    if(root->left == NULL && root->right == NULL)
    {
        pair<bool,int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = solve(root->left);
    pair<bool, int> rightAns = solve(root->right);

    // 1 case hum solve kr lenge
    if(leftAns.first == true && 
        rightAns.first == true && 
        root->data > leftAns.second && 
        root->data > rightAns.second) 
    {
        // Valid Max Heap
        pair<bool, int> p =  make_pair(true, root->data);
        return p;
    }
    else 
    {
        // Not Valid Max Heap
        pair<bool, int> p =  make_pair(false, root->data);
        return p;
    }
}