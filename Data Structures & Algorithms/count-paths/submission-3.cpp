class Solution {
public:
    int uniquePaths(int m, int n) {
        /*vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){              
                if(j > 0) dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];*/
        int N = m + n - 2;
        int k = min(m - 1, n - 1); // 挑小的算，C(N, k) 迴圈跑最少次
        long long ans = 1;         // 用 long long 防止單步的乘法溢位
        
        for (int i = 1; i <= k; i++) {
            // 每次迴圈對應計算：ans = ans * (分子) / (分母)
            ans = ans * (N - i + 1) / i;
        }
        
        return ans;
    }    
};
