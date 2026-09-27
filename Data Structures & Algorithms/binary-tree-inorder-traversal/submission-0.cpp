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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* current = root;        
        while(!st.empty() || current != nullptr){
            while(current){
                st.push(current);
                current = current->left;
            }
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);
            current = node->right;
        }
        return ans;
    }
};