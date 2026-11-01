class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(k, INT_MIN));

        auto dfs = [&](auto &self, int start, int k)->int{
            if(memo[start][k] != INT_MIN) return memo[start][k];
            int sum = 0;
            int res;            
            int output = INT_MAX;
            for(int i = start; i < n - k; i++){
                sum += nums[i];                
                if(k > 0) {
                    res = max(sum, self(self, i + 1, k - 1));
                    output = min(output, res);
                }
            }
            return memo[start][k] = (k == 0) ? sum : output;
        };

        return dfs(dfs, 0, k - 1);
    }
};