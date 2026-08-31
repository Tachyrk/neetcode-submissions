class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int coin : coins){
            int cost = 1;
            for(int i = amount ; i >= 0; i--){
                int current_min = dp[i];
                int temp = coin;
                int cost = 1;
                while(temp <= amount){
                    if(i - temp >= 0 && dp[i - temp] != INT_MAX){
                        current_min = min(current_min, dp[i - temp] + cost);
                    }
                    temp += coin;
                    cost++;
                }
                dp[i] = current_min;
            }           
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
