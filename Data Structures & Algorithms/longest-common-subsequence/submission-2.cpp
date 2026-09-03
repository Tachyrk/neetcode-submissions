class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<int> dp(n + 1, 0);       
        for(int i = 0; i < m; i++){
            int prev = dp[0];
            for(int j = 0; j < n; j++){
                int temp = dp[j + 1];
                if(text1[i] == text2[j]){
                    dp[j + 1] = prev + 1;
                }else{
                    dp[j + 1] = max(dp[j + 1], dp[j]);
                }
                prev = temp;
            }
        }

        return dp[n];
    }
};
