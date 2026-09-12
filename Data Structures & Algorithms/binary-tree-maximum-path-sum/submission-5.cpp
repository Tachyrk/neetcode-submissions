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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;

        auto helper = [&](auto &self, TreeNode* current)->int{         
            int val = current->val;
            int left_val = 0, right_val = 0;
            if(current->left) left_val = self(self, current->left);
            if(current->right) right_val = self(self, current->right);

            if(left_val < 0) left_val = 0;
            if(right_val < 0) right_val = 0;
            if(val + left_val + right_val > ans) ans = val + left_val + right_val;
            return max(val + left_val, val + right_val);
        };

        helper(helper, root);

        return ans;
    }
};
