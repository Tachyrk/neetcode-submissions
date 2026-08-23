class Solution {
public:
    int climbStairs(int n) {
        int dp1 = 1;
        if(n == 1) return dp1;
        int dp2 = 2;
        if(n == 2) return dp2;
        int dp;
        for(int i = 3; i <= n; i++){
            dp = dp1 + dp2;
            dp1 = dp2;
            dp2 = dp;
        }

        return dp;
    }
};
