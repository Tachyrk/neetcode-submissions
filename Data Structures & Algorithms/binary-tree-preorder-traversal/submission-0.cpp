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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* current = root;
        vector<int> ans;
        while(!st.empty() || current){
            while(current){
                st.push(current);
                ans.push_back(current->val);
                current = current->left;
            }
            TreeNode* node = st.top();
            st.pop();
            current = node->right;
        }
        return ans;
    }
};