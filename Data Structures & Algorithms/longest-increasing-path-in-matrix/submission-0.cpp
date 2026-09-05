class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int x_dir[4] = {1, 0, -1, 0};
        int y_dir[4] = {0, 1, 0, -1};
        auto dfs = [&](auto &self, int x, int y)->int{
            if(dp[x][y] != -1) return dp[x][y];
            int ans = 1;
            for(int dir = 0; dir < 4; dir++){
                int new_x = x + x_dir[dir];
                int new_y = y + y_dir[dir];
                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n){
                    if(matrix[new_x][new_y] > matrix[x][y]){
                        ans = max(ans, self(self, new_x, new_y) + 1);
                    }
                }
            }

            return dp[x][y] = ans;
        };

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, dfs(dfs, i, j));
            }
        }

        return ans;
    }
};
