class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {        
        int n = stoneValue.size();

        /*auto dfs = [&](auto &self, int start)->int{
            if(start >= n) return 0;
            int gain;
            int sum = 0;
            int res = INT_MIN;
            for(int i = start; i < min(n, start + 3); i++){
                sum += stoneValue[i];
                gain = sum - self(self, i + 1);
                res = max(res, gain);
            }

            return res;
        };
        int ans = dfs(dfs, 0);
        if(ans == 0) return "Tie";
        if(ans < 0) return "Bob";
        return "Alice";*/

        //int dp1 = 0, dp2 = 0, dp3 = 0;
        int dp[3] = {0};
        for(int i = n - 1; i >= 0; i--){
            int gain = 0;
            int sum = 0;
            int res = INT_MIN;
            for(int j = i; j < min(n, i + 3); j++){
                sum += stoneValue[j];
                gain = sum - dp[j - i];
                res = max(res, gain);
            }
            dp[2] = dp[1];
            dp[1] = dp[0];
            dp[0] = res;
        }

        if(dp[0] == 0) return "Tie";
        if(dp[0] < 0) return "Bob";
        return "Alice";
    }
};