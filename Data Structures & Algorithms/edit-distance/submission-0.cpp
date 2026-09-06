class Solution {
public:
    int minDistance(string word1, string word2) {
        //dp[i][j] 代表了 word1[i - 1] 拚到 word2[j - 1] 的 cost。
        // dp[i][j] 應該要等於 dp[i - 1][j] + 1; (多砍一個字)
        // dp[i][j] 應該要等於 dp[i][j - 1] + 1; (多加一個字)
        // dp[i][j] 應該要等於 dp[i - 1][j - 1]; (如果剛好 word1[i- 1] == word2[j - 1])
        // dp[0][0] = 0 (啥都不用動)。
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = 0;
        for(int i = 0; i <= n; i++){
            dp[0][i] = i;
        }
        for(int i = 1; i <= m; i++){          
            dp[i][0] = i; 
            for(int j = 1; j <= n; j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    // 取 Delete, Insert, Replace 三者成本的最小值 + 1
                    dp[i][j] = 1 + min({dp[i - 1][j],      // Delete
                                        dp[i][j - 1],      // Insert
                                        dp[i - 1][j - 1]}); // Replace                 
                }                
            }
        }

        return dp[m][n];
    }
};
