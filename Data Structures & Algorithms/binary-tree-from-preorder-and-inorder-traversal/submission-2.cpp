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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx = 0;
        int n = preorder.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }

        auto dfs = [&](auto self, int left, int right) -> TreeNode*{
            // left and right is range in inorder vec.
            if(left > right) return nullptr;

            //left <= right means valid node in preorder, just add preidx;
            //preorder == root -> left -> right.
            TreeNode* node = new TreeNode(preorder[preidx++]); 

            int mid = mp[node->val];

            //preorder ordering.
            node->left = self(self, left, mid - 1);
            node->right = self(self, mid + 1, right);

            return node;
        };

        return dfs(dfs, 0, n - 1);
    }
};
