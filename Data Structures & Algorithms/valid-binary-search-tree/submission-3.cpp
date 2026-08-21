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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        auto inorder = [&](auto &self, TreeNode* node) ->bool {
            if(!node) return true;

            if(!self(self, node->left)) return false;
            if(prev && node->val <= prev->val) return false;
            prev = node;

            if(!self(self, node->right)) return false;
            return true;
        };
        return inorder(inorder, root);
    }
};
