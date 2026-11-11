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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return nullptr;
        stack<TreeNode*> st;
        TreeNode* current = root;
        TreeNode* last_visited = nullptr;
        while(current || !st.empty()){
            while(current){
                st.push(current);
                current = current->left;
            }
            TreeNode* node = st.top();
            if(node->right && node->right != last_visited){
                current = node->right;
            }else{
                st.pop();
                if(!node->left && !node->right && node->val == target){  
                    if(st.empty()){               
                        delete node;             
                        return nullptr;
                    }
                    // 先斷開父節點指標，再執行 delete
                    TreeNode* parent = st.top();
                    if (parent->left == node) {
                        parent->left = nullptr;
                    } else {
                        parent->right = nullptr;
                    }
                    delete node;        
                    
                    last_visited = nullptr;

                }else{
                    last_visited = node;
                }
            }            
        }
        return root;
    }
};