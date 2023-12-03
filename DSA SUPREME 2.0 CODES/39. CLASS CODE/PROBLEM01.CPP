// PROBLEM 01: Balanced Binary Tree (Leetcode-110)

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
public:
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftH = height(root->left);
        int rightH = height(root->right);
        int finalH = max(leftH, rightH) + 1;
        
        return finalH;
    }

    bool isBalanced(TreeNode* root) {
        // Base case
        if(root == NULL){
            // Hum leaf node ko balanced tree assume kar rhe hai
            return true;
        }

        // 1 case hum solve kr lenge
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight);

        bool currentNode = (diff <= 1);

        // Ab recursion baki ka solve khud kar lega
        bool leftSub = isBalanced(root->left);
        bool rightSub = isBalanced(root->right);

        // Check ki tree balanced hai ya nhi
        if(currentNode && leftSub && rightSub){
            return true;
        }
        else{
            return false;
        }
    }
};