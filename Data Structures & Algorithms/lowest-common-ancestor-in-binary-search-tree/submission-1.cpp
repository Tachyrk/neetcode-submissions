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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        auto dfs = [&](auto self, TreeNode* current) ->bool {
            if(!current) return false;            
            bool leftvalid = self(self, current->left);
            bool rightvalid = self(self, current->right);
            if(current->val == p->val || current->val == q->val){
                if(leftvalid || rightvalid){
                    ans = current;
                }
                return true;
            }
            if(leftvalid && rightvalid){
                ans = current;               
            }
            return leftvalid || rightvalid;
        };

        dfs(dfs, root);
        return ans;
    }
};
