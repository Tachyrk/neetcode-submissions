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

        auto helper = [&](auto &self, TreeNode* node)->int{         
            if (!node) return 0;

            // 若子樹回傳負數，直接取 0 捨棄
            int left = max(0, self(self, node->left));
            int right = max(0, self(self, node->right));

            // 以當前節點為頂點更新最大路徑和
            ans = max(ans, node->val + left + right);

            // 回傳單一最大分支供父節點延伸
            return node->val + max(left, right);
        };

        helper(helper, root);

        return ans;
    }
};
