// 6. Check Whether a Binary Tree is a Complete Binary Tree or Not? (Leetcode-958)

/*
Time Complexity: O(N)
Space Complexity: O(N)
Where N is number of nodes in binary tree
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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        // initially 
        q.push(root);
        bool nullFound = false;

        // Ab queue par traverse kar rhe hai
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL)
            {
                nullFound = true;
            }
            else
            {
                if(nullFound == true)
                {
                    return false;
                }
                q.push(front->left);
                q.push(front->right);
            }
        }
        // Agar yanha tak pahunch gya hu to
        // CBT tree hi hoga queue ke empty hone par
        return nullFound;
    }
};