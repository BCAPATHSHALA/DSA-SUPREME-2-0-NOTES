//PROBLEM 04: Path Sum II (Leetcode-113)

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
    void solve(TreeNode* root, int targetSum, int sum, vector<int> temp, vector<vector<int>> &ans){
        // Base case 
        if(root == NULL){
            return;
        }

        // 1 case hum solve kar lenge
        sum += root->val;
        temp.push_back(root->val);
        // Check krlo --> current root node leaf node par to nhi hai
        if(root->left == NULL && root->right == NULL){
            // Verify
            if(targetSum == sum){
                ans.push_back(temp);
            }
            else{
                return;
            }
        }

        // Ab recursion solve kar lega
        solve(root->left, targetSum, sum, temp, ans);
        solve(root->right, targetSum, sum, temp, ans);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(root, targetSum, sum, temp, ans);
        return ans;
    }
};