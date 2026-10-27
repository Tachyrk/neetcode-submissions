class Solution {
public:
    int numSquares(int n) {
        // dp[i] 代表組成整數 i 所需的最少平方數個數
        // 最壞情況全由 1 組成，所以 dp[i] 最大不會超過 i
        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end(), 0); // dp[0]=0, dp[1]=1, dp[2]=2...

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};