class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        // s 為空時，只有「x*」這種結構可以當作 0 次蒸發掉
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*' && j > 1) {
                dp[0][j] = dp[0][j - 2];
            }
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == p[j - 1]){
                    dp[i][j] = dp[i][j] | dp[i - 1][j - 1];
                }
                if(p[j - 1] == '.'){
                    dp[i][j] = dp[i][j] | dp[i - 1][j - 1];
                }
                if(p[j - 1] == '*'){
                    // 情況 A：匹配 0 次（直接蒸發），隨時都可以成立
                    if (j > 1) dp[i][j] = dp[i][j] | dp[i][j - 2];

                    // 情況 B：匹配 1 次或多次，前提是字元必須吻合
                    if (j > 1 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
                        dp[i][j] = dp[i][j] | dp[i - 1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};
