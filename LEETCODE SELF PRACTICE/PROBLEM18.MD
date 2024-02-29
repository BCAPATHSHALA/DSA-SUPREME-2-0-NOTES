DATE: 29-02-2024

## Problem 18: [ Even Odd Tree (Leetcode-1609) ](https://leetcode.com/problems/even-odd-tree/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

A binary tree is named **Even-Odd** if it meets the following conditions:

- The root of the binary tree is at level index `0`, its children are at level index `1`, their children are at level index `2`, etc.

- For every **even-indexed** level, all nodes at the level have **odd** integer values in **strictly increasing** order (from left to right).
- For every **odd-indexed** level, all nodes at the level have **even** integer values in **strictly decreasing** order (from left to right).

Given the `root` of a binary tree, return `true` if the binary tree is `Even-Odd`, otherwise return `false`.

## Examples

Example 1:

<p align="center">
  <img src="https://assets.leetcode.com/uploads/2020/09/15/sample_1_1966.png" alt="Example 1">
</p>

```bash
Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.
```

Example 2:

<p align="center">
  <img src="https://assets.leetcode.com/uploads/2020/09/15/sample_2_1966.png" alt="Example 2">
</p>

```bash
Input: root = [5,4,2,3,3,7]
Output: false
Explanation: The node values on each level are:
Level 0: [5]
Level 1: [4,2]
Level 2: [3,3,7]
Node values in level 2 must be in strictly increasing order, so the tree is not Even-Odd.
```

Example 3:

<p align="center">
  <img src="https://assets.leetcode.com/uploads/2020/09/22/sample_1_333_1966.png" alt="Example 3">
</p>

```bash
Input: root = [5,9,1,3,5,7]
Output: false
Explanation: Node values in the level 1 should be even integers.
```

## Constraints:

1. The number of nodes in the tree is in the range `[1, 10^5]`.
2. `1 <= Node.val <= 10^6`

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1

```cpp
/*
Optimal approach: Using Level-order traversal
Time Complexity:  O(N)
Space Complexity: O(N)
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        queue<TreeNode*> q;
        // Initial state
        int level = 0;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            // Set previous node value to compare current node value on each level
            int prevNodeValue = (level % 2 == 0) ? INT_MIN : INT_MAX;

            for(int i = 0; i < size; i++){
                TreeNode* currNode = q.front();
                q.pop();

                // Check if the values follow the conditions
                if ((level % 2 == 0 && (currNode->val % 2 == 0 || currNode->val <= prevNodeValue)) ||
                    (level % 2 == 1 && (currNode->val % 2 == 1 || currNode->val >= prevNodeValue))) {
                    return false;
                }
                
                // Add children to the queue
                if (currNode->left) {
                    q.push(currNode->left);
                }
                if (currNode->right) {
                    q.push(currNode->right);
                }

                // Update previous node value 
                prevNodeValue = currNode->val;
            }
            // Update level after completing the previous level
            level++;
        }
        // All conditions are satisfied
        return true;
    }
};
```
