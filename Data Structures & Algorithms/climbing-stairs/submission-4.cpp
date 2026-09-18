class Solution {
public:
    int climbStairs(int n) {
        int dp2 = 1;
        if(n == 1) return dp2;
        int dp1 = 2;
        
        if(n == 2) return dp1;
        int dp;
        for(int i = 3; i <= n; i++){
            dp = dp1 + dp2;
            dp2 = dp1;
            dp1 = dp;         
        }

        return dp1;
    }
};
