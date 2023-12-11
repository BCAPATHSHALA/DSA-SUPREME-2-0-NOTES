// PROBLEM 02: Validate BST (Leetcode-98)
/*
PROBLEM STATEMENT:
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
1. The left subtree of a node contains only nodes with keys less than the node's key.
2. The right subtree of a node contains only nodes with keys greater than the node's key.
3. Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:
1. The number of nodes in the tree is in the range [1, 10^4].
2. -2^31 <= Node.val <= 2^31 - 1

Time Complexity: O(N)
Space Complexity: O(N)
Where N is number of nodes
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
public:
    bool solve(TreeNode* root, long long int lowerBound, long long int upperBound){
        // Base case
        if(root == NULL){
            return true;
        }

        // 1 case hum solve kar lenge
        bool cond1 = (root->val > lowerBound);
        bool cond2 = (root->val < upperBound);
        // ab recursion solve kar lega
        bool LS = solve(root->left, lowerBound, root->val);
        bool RS = solve(root->right, root->val, upperBound);

        // ab har ek root par check karlo ki
        // BST hai ya nhi
        if(cond1 && cond2 && LS && RS){
            return true;
        }
        else{
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        long long int lowerBound  = -2147483657;
        long long int upperBound = 2147483657;

        bool ans = solve(root, lowerBound, upperBound);
        return ans;
    }
};