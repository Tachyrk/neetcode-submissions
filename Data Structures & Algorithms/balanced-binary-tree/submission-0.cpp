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
    bool isBalanced(TreeNode* root) {
       auto dfs = [&](auto self, TreeNode* node) -> int{
            if(!node) return 0;
            int left = self(self, node->left);
            int right = self(self, node->right);
            if(left == -1 || right == -1) return -1;
            if(abs(left - right) > 1) return -1;
            return max(left, right) + 1;
       };

       return dfs(dfs, root) == -1 ? false : true;
    }
};
