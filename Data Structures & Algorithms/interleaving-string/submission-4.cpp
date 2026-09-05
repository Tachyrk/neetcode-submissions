class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //用 S1、S2 拼出 S3， 本質上就是每一個 S3 char從左到右具體是選 S1 還是 S2。
        //也就是說， 設 n1 = s1 len， n2 = s2 len， 其實是在問 dp[n1][n2] 是否 valid。
        //對於 S3[i] 來說，反推就是要還 s1 還是 s2， 也就是 dp[n1 - 1][n2] || dp[n1][n2 - 1];
        //dp[i][j] = dp[i - 1][j] || dp[i][j - 1], dp[0][0] = 1;

        int m = s1.size(), n = s2.size();
        if(m + n != s3.size()) return 0;
       
        vector<vector<int>> dp(m + 1,vector<int>(n + 1, 0));
        dp[0][0] = 1;        
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
               if (i > 0 && s3[i + j - 1] == s1[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if (j > 0 && s3[i + j - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        return dp[m][n] > 0;
    }
};
