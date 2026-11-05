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
    int rob(TreeNode* root) {
        auto dfs = [&](auto &self, TreeNode* current)->pair<int, int>{
            if(!current) return {0, 0};
            int rob_this_node = current->val;
            int rub_child = 0;
            auto left = self(self, current->left);
            auto right = self(self, current->right);
            rob_this_node += (left.second + right.second);
            rub_child = max(left.first, left.second) + max(right.first, right.second);
            return {rob_this_node, rub_child};
        };

        pair<int, int> ans = dfs(dfs, root);
        return max(ans.first, ans.second);
    }
};