class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++){
            dp[i] += grid[0][i];
            if(i > 0) dp[i] += dp[i - 1];
        }
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j > 0) dp[j] = min(dp[j], dp[j - 1]);
                dp[j] += grid[i][j];
            }
        }

        return dp[n - 1];
    }
};