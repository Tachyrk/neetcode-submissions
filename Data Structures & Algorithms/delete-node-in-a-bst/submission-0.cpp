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
        if(!root) return root;
        if(root->val == key){
            if(!root->left && !root->right) return nullptr;
            TreeNode* temp;
            TreeNode* new_root;
            TreeNode* current;
            if(root->left){
                temp = root->right;
                new_root = root->left;
                current = new_root;
                while(current->right) current = current->right;
                current->right = temp;
                return new_root;
            }else{
                temp = root->left;
                new_root = root->right;
                current = new_root;
                while(current->left) current = current->left;
                current->left = temp;
                return new_root;
            }            
        }else{
            if(root->left && key < root->val) root->left = deleteNode(root->left, key);
            else if(root->right) root->right = deleteNode(root->right, key);            
        }
        return root;
    }
};