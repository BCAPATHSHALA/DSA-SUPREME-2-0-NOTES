// PROBLEM 3: Lowest Common Ancestor of a BST (Leetcode-235)

/*
PROBLEM STATEMENT:
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T 
that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2
 

Constraints:
1. The number of nodes in the tree is in the range [2, 10^5].
2. -10^9 <= Node.val <= 10^9
3. All Node.val are unique.
4. p != q
5. p and q will exist in the BST.

Time Complexity: O(H)
Space Complexity: O(H)
Where H is height of BST
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case
        if(root == NULL){
            return NULL;
        }

        // Case 1: P is in left subtree of root node && Q is in right subtree of root node
        if(p->val < root->val && q->val > root->val){
            return root;
        }
        // Case 2: Q is in left subtree of root node && P is in right subtree of root node
        else if(p->val > root->val && q->val < root->val){
            return root;
        }
        // Case 3: P and Q are in left subtree of root node
        else if(p->val < root->val && q->val < root->val){
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            return leftAns;
        }
        // Case 4: P and Q are in right subtree of root node
        else if(p->val > root->val && q->val > root->val){
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
            return rightAns;
        }   

        return root; 
    }
};