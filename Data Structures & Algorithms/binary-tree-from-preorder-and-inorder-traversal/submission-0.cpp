class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_idx = 0; // 用來追蹤 preorder 目前走到哪裡了
        
        // 為了 O(1) 找到 inorder 裡的值，我們剛才說好的 Hash Map 可以建在這裡
        unordered_map<int, int> in_map;
        for (int i = 0; i < inorder.size(); i++) {
            in_map[inorder[i]] = i; 
        }

        // dfs 的參數變成：當前子樹在 inorder 中的起點 (in_left) 與終點 (in_right)
        auto dfs = [&](auto self, int in_left, int in_right) -> TreeNode*{
            // Base case: 如果範圍交叉，代表沒有節點了
            if (in_left > in_right) {
                return nullptr;
            }

            // 1. 抓出目前的 root (直接用 pre_idx，用完記得 +1)
            int val = preorder[pre_idx++];
            TreeNode* node = new TreeNode(val);

            // 2. 去 Hash Map 裡面查這個 root 在 inorder 裡的 index (這就是切割點 mid)
            int mid = in_map[val];

            // 3. 遞迴建立左右子樹 (以 mid 為中心切開)
            // 你覺得 node->left 和 node->right 的 in_left, in_right 應該填什麼？
            node->left = self(self, in_left, mid - 1);
            node->right = self(self, mid + 1, in_right);

            return node;
        };

        // 一開始整棵樹在 inorder 的範圍是 0 到 n-1
        return dfs(dfs, 0, inorder.size() - 1);
    }
};