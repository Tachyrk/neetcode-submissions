class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        //do not have coin /  have coin
        vector<vector<int>> dp(n, vector<int>(2, 0));

        /*dp[0][1] = -prices[0];

        dp[1][0] = max(dp[0][0], prices[1] - dp[0][1]);
        dp[1][1] = max(dp[0][1], -prices[1]);*/
        // Base case: 第 0 天
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        // Base case: 第 1 天
        dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
        dp[1][1] = max(dp[0][1], -prices[1]); // 在第 0 天買 vs 第 1 天買

        for(int i = 2; i < n; i++){           
            if(i > 0){
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = dp[i - 1][1];
            }
            if(i > 1)  dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
            /*dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] +  prices);
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices);

            dp[i][1] = dp[i - 1][1];

            dp[i][0] = dp[i - 1][1] +  prices;

            dp[i][1] = dp[i - 2][0] - prices   */
        }

        /*for (int i = 2; i < n; ++i) {
            // 今天不持股：昨天就沒持股，或今天賣掉
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 今天持股：昨天就持股，或度過冷卻期後今天買入
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
        }*/

        return dp[n - 1][0];
    }
};
