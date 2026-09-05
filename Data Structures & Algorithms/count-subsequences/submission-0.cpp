class Solution {
public:
    int numDistinct(string s, string t) {
        //看起來很複雜，但這也是 2D DP。
        //主要透過建立一個 dp[i][j] 代表 s 走到 i - 1 的時候 t 在 j - 1 可以有幾種組合。
        //因此 dp[i][j] += dp[i - 1][j - 1];
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base Case: 任何 s 的前綴湊出空字串的方法數都是 1
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if (s[i - 1] == t[j - 1]) {
                    // 用它 (dp[i-1][j-1]) + 不用它 (dp[i-1][j])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    // 對不上，只能不用它
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }
};
