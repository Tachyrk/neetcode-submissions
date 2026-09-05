class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //用 S1、S2 拼出 S3， 本質上就是每一個 S3 char從左到右具體是選 S1 還是 S2。
        //也就是說， 設 n1 = s1 len， n2 = s2 len， 其實是在問 dp[n1][n2] 是否 valid。
        //對於 S3[i] 來說，反推就是要還 s1 還是 s2， 也就是 dp[n1 - 1][n2] || dp[n1][n2 - 1];
        //dp[i][j] = dp[i - 1][j] || dp[i][j - 1], dp[0][0] = 1;

        int m = s1.size(), n = s2.size();
        if(m + n != s3.size()) return 0;
       
        vector<int> dp(n + 1, 0);
        dp[0] = 1;        
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
               // 1. 先看能不能從上面來（消耗 s1）
                // 注意：此時的 dp[j] 還裝著上一列 (i - 1) 的結果
                bool from_top = (i > 0 && dp[j] && s1[i - 1] == s3[i + j - 1]);

                // 2. 再看能不能從左邊來（消耗 s2）
                // 注意：此時的 dp[j - 1] 已經是當前列 (i) 的最新結果
                bool from_left = (j > 0 && dp[j - 1] && s2[j - 1] == s3[i + j - 1]);

                // 3. 只有起點 (0, 0) 維持 1，其餘格子必須由這兩條路決定！
                // 如果兩條路都走不通，dp[j] 就會被正確刷成 false，不會有過期髒資料
                if (i == 0 && j == 0) {
                    dp[j] = 1;
                } else {
                    dp[j] = from_top || from_left;
                }
            }
        }

        return dp[n] > 0;
    }
};
