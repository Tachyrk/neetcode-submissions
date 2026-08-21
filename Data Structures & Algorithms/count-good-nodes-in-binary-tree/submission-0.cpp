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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        
        auto dfs = [&](auto &self, TreeNode* current, int maxval)->int{
            if(!current) return 0;
            int left_count = self(self, current->left, max(maxval, current->val));
            int right_count = self(self, current->right, max(maxval, current->val));
            int count = left_count + right_count;
            if(current->val >= maxval){
                count++;
            }
            return count;
        };

        return dfs(dfs, root, INT_MIN);
    }
};
