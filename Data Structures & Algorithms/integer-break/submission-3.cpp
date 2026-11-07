class Solution {
public:
    int integerBreak(int n) {       
        vector<long long> dp(n + 1, 1);        

        for(int i = 1; i < n; i++){
            for(int j = i; j <= n; j++){
                long long res = 1LL * i * dp[j - i];
                if(res > dp[j]){
                    dp[j] = res;
                }
            }
        }

        return dp[n];
    }
};