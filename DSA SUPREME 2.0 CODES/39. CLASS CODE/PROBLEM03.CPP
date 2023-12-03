// PROBLEM 03: Path Sum (Leetcode-112)

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
    bool solve(TreeNode* root, int targetSum, int sum){
        // Base case
        if(root == NULL){
            return false;
        }

        // 1 case hum solve kar lenge
        sum += root->val;
        // Check krlo --> current root node leaf node par to nhi hai
        if(root->left == NULL && root->right == NULL){
            // Verify
            if(targetSum == sum){
                return true;
            }
            else{
                return false;
            }
        }

        // Ab recursion solve kr lega
        bool leftSub = solve(root->left, targetSum, sum);
        bool rightSub = solve(root->right, targetSum, sum);
        // Yeh important line hai --> return kaise karna hai
        return leftSub || rightSub;
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;
    }
};