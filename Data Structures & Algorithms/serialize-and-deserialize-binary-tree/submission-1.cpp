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
    //你的直覺是對的， preorder 對這題很方便， 但要注意 to string 跟 s to i， C++ 沒辦法直接把 strign 轉 INT。
    //可以想想看 除了遞迴外怎麼用 BFS 去做， 為甚麼比 Stack 方便?
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
