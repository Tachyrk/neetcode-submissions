class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> memo(n, vector<int>(n, -1));
        auto dfs = [&](auto &self, int start, int end)->int{
            if(start == end){
                return piles[start];
            }

            if(memo[start][end] != -1) return memo[start][end];
            int res = max(piles[start] - self(self, start + 1, end), piles[end] - self(self, start, end - 1));           
            return memo[start][end] = res;
        };

        return dfs(dfs, 0, n - 1) >= 0;
    }
};