class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 其實就是挑那些數字要是正的，那些是負的
        // 設 P 為正數之合， N 為負數之合的絕對值， 那
        // P - N = target, P + N = total_sum  => 2P = target + total_sum
        // 也就是說 target + total_sum 要可以 /2， 也要 > 0
        // 問題變成了  挑那些數字可以湊出P  (0/1 問題)?

        int total_sum = 0;
        for(int num : nums) total_sum += num;
        if(total_sum + target < 0) return 0;
        if((total_sum + target) & 1) return 0;
        int P = (total_sum + target) >> 1;
        vector<int> dp(P + 1, 0);
        dp[0] = 1;
        for(int num : nums){
            for(int i = P; i >= num; i--){
                dp[i] += dp[i - num];
            }
        }

        return dp[P];
    }
};
