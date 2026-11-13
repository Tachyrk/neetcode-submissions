class Solution {
public:
    int totalNQueens(int n) {       
        vector<bool> col_check(n, false);
        vector<bool> slash_check(2 * n, false);
        vector<bool> anti_slash_check(2 * n, false);
        int ans = 0;
        
        auto dfs = [&](auto &self, int level)->void{
            if(level == n){
                ans++;
                return;
            }
            for(int i = 0; i < n; i++){
                if(col_check[i]) continue;
                int slash_idx = level + i;
                if(slash_check[slash_idx]) continue;
                int anti_slash_idx = level - i + (n - 1);
                if(anti_slash_check[anti_slash_idx]) continue;
                col_check[i] = true;
                slash_check[slash_idx] = true;
                anti_slash_check[anti_slash_idx] = true;
                self(self, level + 1);
                col_check[i] = false;
                slash_check[slash_idx] = false;
                anti_slash_check[anti_slash_idx] = false;
            }
            return;
        };

        dfs(dfs, 0);
        return ans;   
    }
};