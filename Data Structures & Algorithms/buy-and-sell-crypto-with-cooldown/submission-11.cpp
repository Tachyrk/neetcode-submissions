class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        int pre_prev_sold = 0;             // dp[i-2][0]
        int prev_sold = 0;                 // dp[i-1][0]
        int prev_hold = -prices[0];        // dp[i-1][1]

        for (int i = 1; i < n; ++i) {
            int cur_sold = max(prev_sold, prev_hold + prices[i]);
            int cur_hold = max(prev_hold, pre_prev_sold - prices[i]);

            // 滾動推進到下一天
            pre_prev_sold = prev_sold;
            prev_sold = cur_sold;
            prev_hold = cur_hold;
        }

        return prev_sold;
    }
};