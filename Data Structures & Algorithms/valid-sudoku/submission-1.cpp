class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 使用一維陣列即可，初始化為 0
        int rowcheck[9] = {0};
        int colcheck[9] = {0};
        int blockcheck[9] = {0};
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    // 取得位移量 (0 ~ 8)
                    int element = board[i][j] - '1';
                    
                    // 建立遮罩 (例如數字 1 就是 1 << 0，數字 3 就是 1 << 2)
                    int mask = 1 << element;
                    
                    int block = (i / 3) * 3 + (j / 3);
                    
                    // 利用 AND 運算檢查是否已經標記過
                    if ((rowcheck[i] & mask) || (colcheck[j] & mask) || (blockcheck[block] & mask)) {
                        return false;
                    }
                    
                    // 利用 OR 運算將該數字標記為已出現
                    rowcheck[i] |= mask;
                    colcheck[j] |= mask;
                    blockcheck[block] |= mask;
                }
            }
        }
        return true;
    }
};