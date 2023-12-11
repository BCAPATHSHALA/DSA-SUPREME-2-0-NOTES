// PROBLEM 5: Two Sum IV - Input is a BST (Leetcode-653)

/*
PROBLEM STATEMENT:
Given the root of a binary search tree and an integer k, return true 
if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false

Constraints:
1. The number of nodes in the tree is in the range [1, 10^4].
2. -10^4 <= Node.val <= 10^4
3. root is guaranteed to be a valid binary search tree.
4. -10^5 <= k <= 10^5

Time Complexity: O(N)
Space Complexity: O(N)
Where N is number of nodes of BST
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
    void storeInorder(TreeNode* root, vector<int> &inorder){
        // Base case
        if(root == NULL){
            return;
        }

        // Inorder (LNR)
        // L
        storeInorder(root->left, inorder);
        // N
        inorder.push_back(root->val);
        // R
        storeInorder(root->right, inorder);
    }

    bool findTarget(TreeNode* root, int k) {
        // Step 1: inorder array
        vector<int> inorder;
        storeInorder(root, inorder);

        // Step 2: find target sum is or not
        int s = 0;
        int e = inorder.size()-1;

        while(s<e){
            int sum = inorder[s] + inorder[e];
            if(sum == k){
                return true;
            }
            else if(sum < k){
                s++;
            }
            else if(sum > k){
                e--;
            }
        }

        return false;
    }
};
