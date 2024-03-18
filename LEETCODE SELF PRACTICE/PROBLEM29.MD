DATE: 17-03-2024

## Problem 29: [ Binary Tree Inorder Traversal (Leetcode-94) ](https://leetcode.com/problems/binary-tree-inorder-traversal/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given the `root` of a binary tree, return the inorder traversal of its nodes' values.

## Examples

Example 1:

```bash
Input: root = [1,null,2,3]
Output: [1,3,2]
```

Example 2:

```bash
Input: root = []
Output: []
```

Example 3:

```bash
Input: root = [1]
Output: [1]
```

## Constraints:

1. The number of nodes in the tree is in the range `[0, 100]`.
2. `-100 <= Node.val <= 100`

**Follow up:** Recursive solution is trivial, could you do it iteratively?

## Solution 1

```cpp
// Optimal Approach
// Time Complexity: O(N)
// Space Complexity: O(N)
// Author: github.com/BCAPATHSHALA


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
    // II. In order traversal (LNR)
    void inOrderTraversal(TreeNode* root, vector<int> &ans){
        // Base case
        if(root == NULL) return;

        // L
        inOrderTraversal(root->left, ans);
        // N
        ans.push_back(root->val);
        // R
        inOrderTraversal(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inOrderTraversal(root, ans);
        return ans;
    }
};
```
