class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //好好想想為啥這題不用倒過來，用一個 current min 來避免 dp 狀態汙染， 差別是啥?
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int coin : coins){
            for(int j = coin; j <= amount; j++){
                if(dp[j - coin] != INT_MAX){
                    dp[j] = min(dp[j], dp[j - coin] + 1);
                }                
            }         
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
