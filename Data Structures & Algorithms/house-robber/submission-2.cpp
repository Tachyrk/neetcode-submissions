class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp1 = 0, dp2 = 0;
        for(int i = 0; i < n; i++){
            int temp = max(dp1, dp2 + nums[i]);
            dp2 = dp1;
            dp1 = temp;
        }

        return dp1;
    }
};
