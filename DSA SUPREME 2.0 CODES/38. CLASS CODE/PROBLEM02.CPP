// PROBLEM 02: Diameter of binary tree (Leetcode-543)

/*
Problem Statment:
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1

Constraints:
1. The number of nodes in the tree is in the range [1, 10^4].
2. -100 <= Node.val <= 100
*/

// ✅ BRUTE FORCE APPROACH (Overhead of the recursive call)
// Time complexity: O(N^2), Where N number of nodes 
// Why O(N^2)? --> Right and left sub tree ke each one node ke liye height function separately call ho rha hai
// Space complexity is O(N) due to the recursive call stack

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
        if(root == NULL) return 0;

        int LH = height(root->left);
        int RH = height(root->right);
        int finalHeight = max(LH, RH) + 1;
        return finalHeight;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        //base case
        if(root == NULL) {
            return 0;
        }   
        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = height(root->left) + height(root->right);
        int diameter = max(option1, max(option2, option3));
        return diameter;
    }
};

// ✅ OPTIMAL APPROACH (No overhead of the recursive call)
// Time complexity: O(N), Where N number of nodes 
// Why O(N)? --> Right and left sub tree ke each one node ke liye height function ek bar hi call ho rha hai
//  Space complexity: O(H), where H is the height of the binary tree
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
    int height(TreeNode* root, int &diameter){
        if(root == NULL) return 0;

        int LH = height(root->left, diameter);
        int RH = height(root->right, diameter);
        int maxHeight = max(LH, RH) + 1;
        // Update diameter with longest path of tree
        diameter = max(diameter, (LH+RH));
        return maxHeight;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        //base case
        if(root == NULL) {
            return 0;
        }   
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};