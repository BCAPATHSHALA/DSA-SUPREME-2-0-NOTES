// PROBLEM 07: Construct Binary Tree from Inorder and POSTorder Traversal (Leetcode-106)
/*
Time and space complexity is O(N), Where N is number of elements in array

PROBLEM STATEMENT:
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree 
and postorder is the postorder traversal of the same tree, construct and return the binary tree.

EXAMPLE 01:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

EXAMPLE 02:
Input: inorder = [-1], postorder = [-1]
Output: [-1]

CONSTRAINTS:
1. 1 <= inorder.length <= 3000
2. postorder.length == inorder.length
3. -3000 <= inorder[i], postorder[i] <= 3000
4. inorder and postorder consist of unique values.
5. Each value of postorder also appears in inorder.
6. inorder is guaranteed to be the inorder traversal of the tree.
7. postorder is guaranteed to be the postorder traversal of the tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    map<int,int> mp;
public:
    // Here, we are finding index position in time complexity of O(1)
    void mapping(vector<int>& inorder,int &size){
        for(int i=0;i<size;i++){
            mp[inorder[i]]=i;   
        }     
    }

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int &postIndex, int size, int inorderStart, int inorderEnd){
        // base case
        if(postIndex < 0 || inorderStart > inorderEnd ){
            return NULL;
        }

        // 1 case hum solve kar lenege
        int element = postorder[postIndex];
        postIndex--;
        TreeNode* root = new TreeNode(element);

        // position map se lelo
        int position = mp[element];

        // Ab baki ka recursion solve kar lega
        // Creating the right sub tree
        root->right = solve(postorder, inorder, postIndex, size, position + 1, inorderEnd);
        // Creating the left sub tree
        root->left = solve(postorder, inorder, postIndex, size, inorderStart, position - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        int postIndex = size - 1;
        int inorderStart = 0;
        int inorderEnd = size - 1;
        mapping(inorder, size);
        TreeNode* binaryTreeRoot = solve(postorder, inorder, postIndex, size, inorderStart, inorderEnd);
        
        return binaryTreeRoot;
    }
};