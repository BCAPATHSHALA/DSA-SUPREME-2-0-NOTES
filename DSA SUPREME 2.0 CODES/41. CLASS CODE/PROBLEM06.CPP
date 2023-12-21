// Delete Node From BST (Leetcode-450) with defferent approach by Lakshay Kumar Bhaiya
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case
        if(root == NULL) return NULL;

        // 1 case hum solve kar lenge
        if(root->val == key)
        {
            // Target root par v ho skta hai
            // Case 1: 
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            // Case 2: 
            else if(root->left == NULL && root->right != NULL){
                auto temp = root;
                root = temp->right;
                delete temp;
                return root;
            }
            // Case 3: 
            else if(root->left != NULL && root->right == NULL){
                auto temp = root;
                root = temp->left;
                delete temp;
                return root;
            }
            // Case 4: root->left != NULL && root->right != NULL
            else{
                // RST MIN NODE FIND KRLO
                // auto rscan = root->right;
                // while(rscan->left){
                //     rscan = rscan->left;
                // }
                // rscan->left = root->left;
                // auto temp = root;
                // root = temp->right;
                // delete temp;
                // return root;

                // LST MAX NODE FIND KRLO
                auto lscan = root->left;
                while(lscan->right){
                    lscan = lscan->right;
                }
                lscan->right = root->right;
                auto temp = root;
                root = temp->left;
                delete temp;
                return root;
            }
        }
        // Ab recursion solve kar lega
        else if(root->val < key)
        {
            // Root ke right me chle jaoo
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // Root ke left me chle jaoo
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};