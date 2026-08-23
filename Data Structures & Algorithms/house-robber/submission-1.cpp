class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int dp1 = nums[0], dp2 = 0;
        for(int i = 1; i < n; i++){
            int temp = max(dp1, dp2 + nums[i]);
            dp2 = dp1;
            dp1 = temp;
        }

        return max(dp1, dp2);
    }
};
