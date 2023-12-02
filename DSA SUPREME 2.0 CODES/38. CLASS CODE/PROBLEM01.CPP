// PROBLEM 01: Height of a binary tree (Leetcode-104)


// Time and space complexity: O(N), 
// where N is total number of nodes in binary tree


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
    int maxDepth(TreeNode* root) {
        // Base case
        if(root == NULL){
            return 0;
        }

        int leftNode = maxDepth(root->left);
        int rightNode = maxDepth(root->right);
        int height = max(leftNode, rightNode) + 1;
        return height;
    }
};

