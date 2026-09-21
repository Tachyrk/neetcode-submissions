class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 2, 1);
        for(int i = 0; i < n; i++){
            arr[i + 1] = nums[i];
        }

        vector<vector<int>> memo(n + 2, vector<int>(n + 2, -1));
        auto helper = [&](auto &self, int l, int r)->int{       
            if(memo[l][r] != -1) return memo[l][r];
            int ans = 0;
            for(int i = l + 1; i < r; i++){
                int gain = arr[i] * arr[l] * arr[r];
                int left_result = self(self, l, i);
                int right_result = self(self, i, r);
                ans = max(ans, gain + left_result + right_result);
            }

            return memo[l][r] = ans;
        };

        return helper(helper, 0, n + 1);
    }
};
