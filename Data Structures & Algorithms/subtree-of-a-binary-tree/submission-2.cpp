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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;

        auto isSameTree = [&](auto self,TreeNode* p, TreeNode* q)->bool{
            if(!p && !q) return true;
            if(!p || !q) return false;
            if(p->val != q->val) return false;
            return self(self, p->left, q->left) && self(self, p->right, q->right);
        };

        auto dfs = [&](auto self, TreeNode* root)->bool{
            if(!root) return false;

            if(root->val == subRoot->val){
                if (isSameTree(isSameTree, root, subRoot)) return true;
            }
            if(self(self, root->left)) return true;
            if(self(self, root->right)) return true;
            return false;
        };       

        return dfs(dfs, root);
    }
};
