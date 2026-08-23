class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        auto house_robber = [&](int start, int end)->int{
            int dp1 = 0, dp2 = 0;
            for(int i = start; i <= end; i++){
                int temp = max(dp1, dp2 + nums[i]);
                dp2 = dp1;
                dp1 = temp;
            }
            return dp1;
        };

        return max(house_robber(0, n - 2), house_robber(1, n - 1));
    }
};
