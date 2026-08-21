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
    int kthSmallest(TreeNode* root, int k) {
        int index = 0;
        stack<TreeNode*> st;
        TreeNode* current = root;
        while(current || !st.empty()){
            while(current){
                st.push(current);
                current = current->left;
            }

            TreeNode* node = st.top();
            st.pop();
            index++;
            if(index == k)  return node->val;

            current = node->right;
        }
        return -1;
    }
};
