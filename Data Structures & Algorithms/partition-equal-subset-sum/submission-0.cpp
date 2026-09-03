class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        if(sum & 1) return false;
        sum >>= 1;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for(auto num : nums){
            for(int i = sum; i >= num; i--){
                if(dp[i - num] != false){
                    dp[i] = true;
                }
            }
        }

        return dp[sum];
    }
};
