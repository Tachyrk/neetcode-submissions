class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> slash(2 * n, false);
        vector<bool> antislash(2 * n, false);

        auto helper = [&](auto &self, int row)->void{
            if(row == n){
                ans.push_back(board);
                return;
            }
            for(int i = 0; i < n; i++){
                int slash_idx = row + i;
                int anti_slash_idx = row - i + n;
                if(!cols[i] && !slash[slash_idx] && !antislash[anti_slash_idx]){
                    cols[i] = true;
                    slash[slash_idx] = true;
                    antislash[anti_slash_idx] = true;
                    board[row][i] = 'Q';
                    self(self, row + 1);
                    board[row][i] = '.';
                    cols[i] = false;
                    slash[slash_idx] = false;
                    antislash[anti_slash_idx] = false;
                    
                }
            }           
        };

        helper(helper, 0);

        return ans;
    }
};
