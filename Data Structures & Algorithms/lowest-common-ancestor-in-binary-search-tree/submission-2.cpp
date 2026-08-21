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
        int n1, n2;
        if(p->val > q->val){
            n1 = p->val;
            n2 = q->val;
        }else{
            n1 = q->val;
            n2 = p->val;
        }

        auto dfs = [&](auto self, TreeNode* current) ->void {
            if(current->val == n1 || current->val == n2){
                ans = current;
                return;
            }
            if(n1 > current->val && current->val > n2){
                ans = current;
                return;
            }
            if(n1 > current->val && n2 > current->val){
                self(self, current->right);
            }else{
                self(self, current->left);
            }
        };        
        dfs(dfs, root);
        return ans;
    }
};
