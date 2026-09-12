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

class Codec {
public:   
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { 
        if(!root) return "#,";
        return to_string(root->val) + ',' + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start_idx = 0;
        auto helper = [&](auto& self)-> TreeNode*{
            int comma = data.find(',', start_idx);
            string s = data.substr(start_idx, comma - start_idx);
            start_idx = comma + 1;
            if(s == "#"){
                return nullptr;
            }            
            TreeNode* node = new TreeNode(stoi(s));
            node->left = self(self);
            node->right = self(self);
            return node;
        };
        return helper(helper);
    }
};
