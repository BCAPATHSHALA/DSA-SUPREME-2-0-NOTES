// PROBLEM 4: Kth Smallest Element in a BST (Leetcode-230)

/*
PROBLEM STATEMENT:
Given the root of a binary search tree, and an integer k, return the 
kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

Constraints:
1. The number of nodes in the tree is n.
2. 1 <= k <= n <= 10^4
3. 0 <= Node.val <= 10^4

Follow up: If the BST is modified often 
(i.e., we can do insert and delete operations) and you need to 
find the kth smallest frequently, how would you optimize?

Time Complexity: O(N)
Space Complexity: O(H)
Where N and H are number of nodes and Height of BST respectively
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
    int kthSmallest(TreeNode* root, int &k) {
        // Base case 
        if(root == NULL){
            return -1;
        }

        // Inorder (LNR)
        // L
        int leftAns = kthSmallest(root->left, k);
        if(leftAns != -1){
            return leftAns;
        }

        // N
        k--;
        if(k == 0){
            return root->val;
        }

        // R
        int rightAns = kthSmallest(root->right, k);
        return rightAns;
    }
};