class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        // 1. 尋找目標節點
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // 2. 找到目標：情況一 & 二（0 或 1 個小孩）
            if (!root->left) {
                TreeNode* right_child = root->right;
                delete root;
                return right_child;
            }
            if (!root->right) {
                TreeNode* left_child = root->left;
                delete root;
                return left_child;
            }

            // 情況三（2 個小孩）：找右子樹最小值
            TreeNode* successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }

            // 複製值，並遞迴去右子樹把 successor 幹掉
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
        return root;
    }
};