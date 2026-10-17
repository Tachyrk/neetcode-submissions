class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        }

        // 找到目標節點 root，準備刪除：
        // 情況 1 & 2：只有 0 或 1 個小孩
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

        // 情況 3：有 2 個小孩，堅持純動指針，絕不碰 val！
        // 我們要找右子樹的最小值 successor，以及它的父節點 succ_parent
        TreeNode* succ_parent = root;
        TreeNode* successor = root->right;

        while (successor->left) {
            succ_parent = successor;
            successor = successor->left;
        }

        // 1. 將 successor 從原本的位置拔下來
        if (succ_parent != root) {
            // successor 是深層左小孩，它的右子樹移交給父節點的 left
            succ_parent->left = successor->right;
            // successor 繼承 root 的右子樹
            successor->right = root->right;
        }
        // （若 succ_parent == root，代表 root->right 就是最小值，successor->right 本來就對，不需重接）

        // 2. successor 繼承 root 的左子樹
        successor->left = root->left;

        // 3. 釋放原本的 root，回傳 successor 作為新子樹的根節點
        delete root;
        return successor;
    }
};